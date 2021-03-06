#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Cursor.hpp>
#include <glimac/Scene.hpp>
#include <glimac/Generate.hpp>
#include <glimac/Scult.hpp>
#include <glimac/Save.hpp>
#include <glimac/Object.hpp>


int main(int argc, char const *argv[]){
     // Initialize SDL and open a window
    constexpr int windowWidth = 800;
    constexpr int windowHeight = 600;
    glimac::SDLWindowManager windowManager(windowWidth, windowHeight, "WorldIMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //Creation des nos objets
    glimac::Scene scene;
    glimac::TrackballCamera camera;
    glimac::Generate gen;
    glimac::Generate gen2;
    glimac::Scult scult;
    glimac::Save save;
    glimac::Object obj;
    glimac::Cursor cursor(glm::vec3(10,3,10));

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;



    //load les shaders 
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program program = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/coloredCube.fs.glsl");
    program.use();

    
   
    //initialise la scène
    scene.createAllCubes();
    scene.uniformMatrix(program);

    //import d'un objet
    obj.loadOBJ(applicationPath.dirPath() + "../assets/models/cube.obj", 4);
    obj.setUpOBJ();

    

    // pour que l'application gère la profondeur et la transparence
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //initialisation 
    scene.setPointLight(glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                        glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                        0.5,
                        glm::vec3(3.0,3.0,3.0),
                        glm::vec3(1.,1.,1.));

    scene.setDirectionalLight(glm::vec3(0.5,0.5,0.5),
                                   glm::vec3(0.2,0.2,0.2),
                                    0.5,
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
            }
            if ( e.type == SDL_MOUSEWHEEL ) {
                if (e.wheel.y > 0) {
                    camera.moveFront(0.1f);
                }
                else if (e.wheel.y < 0)  {
                    camera.moveFront(-0.1f);
                }
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
                        scult.add(cursor,scene.m_allCubes);
                        break;
                    case SDLK_t :
                        scult.remove(cursor,scene.m_allCubes);   
                        break;   
                    case SDLK_u :
                         scult.extrud(cursor,scene.m_allCubes);
                      	break;
                    case SDLK_i :
                         scult.dig(cursor,scene.m_allCubes);
                        break;
                    case SDLK_l :
                        scult.changeColor(cursor,scene.m_allCubes);
                        break;
                    case SDLK_k :
                        scult.getColor(cursor,scene.m_allCubes);
                        break;
                    case SDLK_c :
                        scene.clean();
                        break;
                    case SDLK_b :
                        scene.setUp();
                        break; 
                    case SDLK_f :
                        save.saveScene(applicationPath.dirPath()+"../assets/save/", scene.m_allCubes);
                        break;
                    case SDLK_v :
                        save.loadScene(applicationPath.dirPath()+"../assets/save/", scene.m_allCubes);
                        break;
                    case SDLK_p :
                        gen.readControlPoints(applicationPath.dirPath()+"../assets/controlPoints/controlpoints.txt");
                        gen.applyRBF(scene.m_allCubes, 2);
                        break;
                    case SDLK_m :
                        gen2.readControlPoints(applicationPath.dirPath()+"../assets/controlPoints/controlpoints2.txt");
                        gen2.applyRBF(scene.m_allCubes, 2);
                        for (uint i = 0; i < scene.m_allCubes.size(); ++i)
                        {
                            if (scene.m_allCubes[i].getIsVisible()==true)
                            {
                               scene.m_allCubes[i].setColor(glm::vec4(0,0,1,1));
                            }
                        }
                        break;
                    case SDLK_j :
                        scene.setDirectionalLight(glm::vec3(0.5,0.5,0.5),
                                            glm::vec3(0.2,0.2,0.2),
                                            0.5,
                                            glm::vec3(1.0,1.0,1.0),
                                            glm::vec3(1.,1.,1.));
                        break;
                    case SDLK_n :
                        scene.setDirectionalLight(glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                                        glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0)),
                                        0.5,
                                        glm::vec3(1.0,1.0,1.0),
                                        glm::vec3(0.,0.,0.));

                        break;
                    case SDLK_g:
                        camera.resetCameraSetUp();
                        break;
                }
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //change la couleur du cursor quand il dépasse la limite de la scène
        if(cursor.getPosition().x < 0 || cursor.getPosition().x >scene.getWidth() || cursor.getPosition().y < 0 || cursor.getPosition().y >scene.getHeight()||cursor.getPosition().z < 0 || cursor.getPosition().z >scene.getLenght() ){
            cursor.setColor(glm::vec4(1,0,0,1));
        }
        else{
           cursor.setColor(glm::vec4(0,0,1,1)); 
        }

        

        //Clear the window
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.use();

        scene.applyLight(camera);
        scene.displayCubes(camera);

        scene.applyLight(camera);
        scene.updateMatrix(camera,cursor.getPosition(),cursor);
        cursor.display();

		scene.applyLight(camera);
		scene.updateMatrix(camera);
        obj.displayOBJ(4);

        windowManager.swapBuffers();

    }
    return EXIT_SUCCESS;
    
}


