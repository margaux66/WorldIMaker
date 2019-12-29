#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Cursor.hpp>
#include <glimac/Scene.hpp>


int main(int argc, char const *argv[]){
     // Initialize SDL and open a window
    glimac::SDLWindowManager windowManager(800, 600, "WorldIMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Creation TrackballCamera
    glimac::Scene scene;
    glimac::TrackballCamera camera;

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //load les shaders 
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program program = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/directionallight.fs.glsl");
    program.use();

    
    glimac::Cursor cursor(glm::vec3(1,1,1),glm::vec4(0,0,1,1));
    glimac::Cube cube(glm::vec3(0,0,0),glm::vec4(0,1,0,1));

    scene.createAllCubes();
    std::vector<glimac::Cube> allCube;
    allCube = scene.getAllCubes();

    scene.uniformMatrix(program);

    // GPU checks depth
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    scene.setDirectionalLight(glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                                glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                                0.5,
                                glm::vec3(1.0,1.0,1.0),
                                glm::vec3(1.,1.,1.));

    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            if(e.type == SDL_MOUSEMOTION && (e.motion.state & SDL_BUTTON_LEFT)){
                camera.rotateUp(e.motion.yrel);
                camera.rotateLeft(e.motion.xrel);
                //std::cout<< e.motion.yrel <<std::endl;                  
            }

            if(e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym){
                    case SDLK_q :
                        camera.rotateLeft(-10);
                        break;
                    case SDLK_d :
                        camera.rotateLeft(+10);
                        break;
                    case SDLK_s :
                        camera.rotateUp(-10);
                        break;
                    case SDLK_z :
                        camera.rotateUp(10);
                        break;

                    case SDLK_RIGHT :
                        cursor.setPosition(glm::vec3(cursor.getPosition().x +1, cursor.getPosition().y, cursor.getPosition().z));
                        break;
                    case SDLK_LEFT :
                        cursor.setPosition(glm::vec3(cursor.getPosition().x -1, cursor.getPosition().y, cursor.getPosition().z));
                        break;
                    case SDLK_UP:
                        cursor.setPosition(glm::vec3(cursor.getPosition().x, cursor.getPosition().y+1, cursor.getPosition().z));
                        break;
                    case SDLK_DOWN:
                        cursor.setPosition(glm::vec3(cursor.getPosition().x, cursor.getPosition().y-1, cursor.getPosition().z));
                        break;

                    case SDLK_w:
                        cursor.setPosition(glm::vec3(cursor.getPosition().x, cursor.getPosition().y, cursor.getPosition().z+1));
                        break;  
                    case SDLK_x:
                        cursor.setPosition(glm::vec3(cursor.getPosition().x, cursor.getPosition().y, cursor.getPosition().z-1));
                        break;
                    case SDLK_r :
                        scene.add(cursor);
                        break;
                    case SDLK_t :
                        scene.remove(cursor);   
                        break;   
                    case SDLK_u :
                         scene.extrud(cursor);
                      	break;
                    case SDLK_i :
                         scene.dig(cursor);
                        break;
                    case SDLK_l :
                        scene.changeColor(cursor,glm::vec4(0,0,1,1));
                        break;
                    case SDLK_k :
                        scene.getColor(cursor);
                        break;




                }
            }
            allCube[1].setIsVisible(true);
            if ( e.type == SDL_MOUSEWHEEL ) {
                if (e.wheel.y > 0) {
                    camera.moveFront(0.1f);

                }
                else if (e.wheel.y < 0)  {
                    camera.moveFront(-0.1f);
                }
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //Clear the window
        glClearColor(1,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene.applyDirectionalLight(camera);
        scene.displayCubes(camera);

        scene.applyDirectionalLight(camera);
        scene.updateMatrix(camera,cursor.getPosition(),cursor);
        cursor.display();

        windowManager.swapBuffers();

    }
    return EXIT_SUCCESS;
    
}


