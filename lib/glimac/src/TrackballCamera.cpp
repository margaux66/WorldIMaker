#include "glimac/TrackballCamera.hpp"
#include <iostream>

namespace glimac {

    TrackballCamera::TrackballCamera(){
        m_fDistance=-10;
        m_fAngleX= -3;
        m_fAngleY=-3;
    };

    void TrackballCamera::moveFront(float delta){
        m_fDistance += delta;

    }

    void TrackballCamera::rotateLeft(float degrees){
        m_fAngleY += degrees;
    }

    void TrackballCamera::rotateUp(float degrees){
        m_fAngleX += degrees;
    }

    glm::mat4 TrackballCamera::getViewMatrix() const{
        glm::mat4 ViewMatrix = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, m_fDistance));
        ViewMatrix = glm::rotate(ViewMatrix,glm::radians(m_fAngleX), glm::vec3(1, 0, 0));
        ViewMatrix = glm::rotate(ViewMatrix,glm::radians(m_fAngleY), glm::vec3(0, 1, 0));
        return ViewMatrix;
    }
}