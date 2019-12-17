#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cube.hpp>

int main(int argc, char const *argv[]){
     // Initialize SDL and open a window
    glimac::SDLWindowManager windowManager(800, 600, "WorldIMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //load les shaders 
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program program = loadProgram(applicationPath.dirPath() + "../assets/shaders/3D.vs.glsl",
                                        applicationPath.dirPath() + "../assets/shaders/directionallight.fs.glsl");
    program.use();

    glimac::Cube cube;

    //Creation TrackballCamera
    TrackballCamera camera = TrackballCamera();

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

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f),800.f/600.f,0.1f, 100.f);

    glm::mat4 MVMatrix = camera.getViewMatrix();

    glm::vec3 Kd = glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0));
    glm::vec3 Ks = glm::vec3(glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0),glm::linearRand (0.0,1.0));
    float Shininess = glm::linearRand (0.0,3.0);
    glm::vec3 LightDir= glm::vec3(1.0,1.0,1.0);
    glm::vec3 LightIntensity = glm::vec3(0.5,0.5,0.5);

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
                std::cout<< e.motion.yrel <<std::endl;                  
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        MVMatrix = camera.getViewMatrix();

        glUniform3fv(uKd, 1, glm::value_ptr(Kd));
        glUniform3fv(uKs, 1, glm::value_ptr(Ks));
        glUniform1f(uShininess, Shininess);
        glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(camera.getViewMatrix())*LightDir));
        glUniform3fv(uLightIntensity, 1, glm::value_ptr(LightIntensity));

        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));

        cube.display();

        windowManager.swapBuffers();

    }
    return EXIT_SUCCESS;
    
}


