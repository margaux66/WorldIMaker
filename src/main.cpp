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
                                        applicationPath.dirPath() + "../assets/shaders/coloredCube.fs.glsl");
    program.use();

    
    glimac::Cursor cursor(glm::vec3(10,4,10));

    scene.createAllCubes();
    std::vector<glimac::Cube> allCube;
    allCube = scene.getAllCubes();

    scene.uniformMatrix(program);

    

    // GPU checks depth
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    scene.setLight(glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                        glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                        0.5,
                        glm::vec3(1.0,1.0,1.0),
                        glm::vec3(1.0,1.0,1.0),
                        glm::vec3(1.,1.,1.));

    scene.setUp();

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
                        camera.moveLeft(-1);
                        break;
                    case SDLK_d :
                        camera.moveLeft(+1);
                        break;
                    case SDLK_s :
                        camera.moveTop(-1);
                        break;
                    case SDLK_z :
                        camera.moveTop(1);
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
                    case SDLK_h :
                        scene.changeColor(cursor,glm::vec4(0,1,1,1));
                        break;
                    case SDLK_k :
                        scene.getColor(cursor);
                        break;
                    case SDLK_c :
                        scene.clean();
                        break;    




                }
            }

            std::cout<< cursor.getPosition() << std::endl;
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

        if(cursor.getPosition().x < 0 || cursor.getPosition().x >scene.getWidth() || cursor.getPosition().y < 0 || cursor.getPosition().y >scene.getHeight()||cursor.getPosition().z < 0 || cursor.getPosition().z >scene.getLenght() ){
            cursor.setColor(glm::vec4(1,0,0,1));
        }
        else{
           cursor.setColor(glm::vec4(0,0,1,1)); 
        }

        

        //Clear the window
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene.applyLight(camera);
        scene.displayCubes(camera);

        scene.applyLight(camera);
        scene.updateMatrix(camera,cursor.getPosition(),cursor);
        cursor.display();

        windowManager.swapBuffers();

    }
    return EXIT_SUCCESS;
    
}


