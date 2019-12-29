#pragma once 

#include <GL/glew.h>
#include "glm.hpp"
#include "FilePath.hpp"
namespace glimac {
	class TrackballCamera {
		private:
		float m_fDistance;
		float m_lDistance;
		float m_tDistance;
		float m_fAngleX;
		float m_fAngleY;

		public:
		TrackballCamera();
		void moveFront(float delta);
		void moveLeft(float delta);
		void moveTop(float delta);
		void rotateLeft(float degrees);
		void rotateUp(float degrees);
		void resetCameraSetUp();
		glm::mat4 getViewMatrix() const;
		
	};	
}




