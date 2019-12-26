#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Cursor.hpp>

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
    TrackballCamera camera = TrackballCamera();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //load les shaders 
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program program = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/directionallight.fs.glsl");
    program.use();

    
    glimac::Cursor cursor(glm::vec3(1,1,1),glm::vec4(0,0,1,1));
    glm::vec4 color = glm::vec4(0,1,0,1);
    std::vector<glimac::Cube> allCube;

    for(uint i = 0; i<10; i++){
        for (int j = 0; j < 10; ++j){
            for (int k = 0; k < 10; ++k){

                allCube.push_back(glimac::Cube(glm::vec3(i,j,k),color));

            }
        }
    }
    

    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uKd = glGetUniformLocation(program.getGLId(), "uKd");
    GLint uKs = glGetUniformLocation(program.getGLId(), "uKs");
    GLint uShininess = glGetUniformLocation(program.getGLId(), "uShininess");
    GLint uLightDir_vs = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
    GLint uLightIntensity = glGetUniformLocation(program.getGLId(), "uLightIntensity");

    // GPU checks depth
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f),800.f/600.f,0.1f, 100.f);

    glm::mat4 MVMatrix = camera.getViewMatrix();

    glm::vec3 Kd = glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0));
    glm::vec3 Ks = glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0));
    float Shininess = 0.5;
    glm::vec3 LightDir= glm::vec3(1.0,1.0,1.0);
    glm::vec3 LightIntensity = glm::vec3(1.,1.,1.);

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
                        for (int i = 0; i < allCube.size(); ++i)
                        {
                            if(cursor.getPosition() == allCube[i].getPosition()){
                                if(allCube[i].getIsVisible()==false){
                                    allCube[i].setIsVisible(true);
                                }
                                else{
                                   allCube[i].setIsVisible(false); 
                                }
                            }

                        }
                        break;  
/*                     case SDLK_t :
                        for (uint i = 0; i < allCube.size(); ++i)
                        {
                            if(cursor.getPosition() == allCube[i].getPosition()){
                            	
                            	while(allCube[j].getIsVisible()==true){
                            		j++;
                            	}
                            	allCube[j+1].setIsVisible(true);
                                
                            }

                        }

                     	break;*/




                }
            }
            
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

/*        MVMatrix = camera.getViewMatrix();

        glUniform3fv(uKd, 1, glm::value_ptr(Kd));
        glUniform3fv(uKs, 1, glm::value_ptr(Ks));
        glUniform1f(uShininess, Shininess);
        glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(camera.getViewMatrix())*LightDir));
        glUniform3fv(uLightIntensity, 1, glm::value_ptr(LightIntensity));

        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
        //glm::mat4 mvp = ProjMatrix * MVMatrix;
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));

        
        cube.display();*/

        for (int i = 0; i < allCube.size(); ++i)
        {
            MVMatrix = camera.getViewMatrix();
            glm::mat4 cube2MVMatrix = glm::translate(MVMatrix, allCube[i].getPosition());
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
            //allCube[0].setColor(glm::vec4(1,1,0,1));
            allCube[i].display();
            
        }

		/*MVMatrix = camera.getViewMatrix();
		glm::mat4 cubesMVMatrix = glm::translate(MVMatrix, allCube[1].getPosition());
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cubesMVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cubesMVMatrix))));
	    glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cubesMVMatrix));
	            //allCube[0].setColor(glm::vec4(1,1,0,1));
	    allCube[1].setIsVisible(true);
	    allCube[1].display();*/

        /*MVMatrix = camera.getViewMatrix();
        glm::mat4 cube2MVMatrix = glm::translate(MVMatrix, cube.getPosition());
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        //allCube[0].setColor(glm::vec4(1,1,0,1));
        allCube[0].display();

        MVMatrix = camera.getViewMatrix();
        cube2MVMatrix = glm::translate(MVMatrix, cube2.getPosition());
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        //allCube[1].setColor(glm::vec4(1,1,0,1));
        allCube[1].display();*/



        MVMatrix = camera.getViewMatrix();
        glm::mat4 cube2MVMatrix = glm::translate(MVMatrix, cursor.getPosition());
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        cursor.display();

        /*MVMatrix = camera.getViewMatrix();
        cube2MVMatrix = glm::translate(MVMatrix, glm::vec3(2,1,1));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        allCube[1].setColor(glm::vec4(0,1,0,1));
        allCube[1].display();

        MVMatrix = camera.getViewMatrix();
        cube2MVMatrix = glm::translate(MVMatrix, glm::vec3(2,2,1));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        allCube[2].setColor(glm::vec4(0,0,1,1));
        allCube[2].display();

        MVMatrix = camera.getViewMatrix();
        cube2MVMatrix = glm::translate(MVMatrix, glm::vec3(1,2,1));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));
        allCube[3].setColor(glm::vec4(0,1,1,1));
        allCube[3].display();*/


        //allCube[1*+1*1].setColor(glm::vec4(0,1,0,1));

        
        //cube.setColor(glm::vec4(0,0,1,0.3));

        // for (int i = 0; i < 3; ++i)
        // {
        //     for (int j = 0; j < 3; ++j)
        //     {
        //         for (int k = 0; k < 3; ++k)
        //         {
        //             /*if (k%2 == 0){
        //                 cube.setIsVisible(false);
        //             }
        //             else{
        //                 cube.setIsVisible(true);
        //             }*/
        //             MVMatrix = camera.getViewMatrix();
            
        //             glUniform3fv(uKd, 1, glm::value_ptr(Kd));
        //             glUniform3fv(uKs, 1, glm::value_ptr(Ks));
        //             glUniform1f(uShininess, Shininess);
        //             glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(camera.getViewMatrix())*LightDir));
        //             glUniform3fv(uLightIntensity, 1, glm::value_ptr(LightIntensity));

        //             glm::mat4 cube2MVMatrix = glm::translate(MVMatrix, glm::vec3(i,j,k));

        //             glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cube2MVMatrix));
        //             glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cube2MVMatrix))));
        //             glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( ProjMatrix * cube2MVMatrix));

        //             cube.display();
        //         }
        //         /* code */
        //     }
        //     /* code */

        // }

        windowManager.swapBuffers();

    }
    return EXIT_SUCCESS;
    
}


