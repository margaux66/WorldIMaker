#pragma once 

#include <GL/glew.h>
#include "glm.hpp"
#include "FilePath.hpp"
namespace glimac {
	///\class TrackballCamera
	///\brief Classe qui gère la caméra de la scène
	class TrackballCamera {
		private:
		float m_fDistance;
		float m_lDistance;
		float m_tDistance;
		float m_fAngleX;
		float m_fAngleY;

		public:
		/*!	
		*\brief Constructeur 
		*Initialise le point de vue de la caméra
		*/
		TrackballCamera();
		///\brief Zoom ou dézoome la scène
		///\param Delta : pas de zoom
		void moveFront(float delta);
		///\brief Déplace la caméra horizontalement
		///\param Delta : pas de déplacement
		void moveLeft(float delta);
		///\brief Déplace la caméra verticalement
		///\param Delta : pas de déplacement
		void moveTop(float delta);
		///\brief Change l'angle de la caméra horizontalement
		///\param Degrees : degrés de rotation de la caméra
		void rotateLeft(float degrees);
		///\brief Change l'angle de la caméra verticalement
		///\param Degrees : degrés de rotation de la caméra
		void rotateUp(float degrees);
		///\brief Remet les paramètres de la caméra à leurs valeurs initiales
		void resetCameraSetUp();
		///\brief Calcule la view matrix
		///\return Matrice 4*4
		glm::mat4 getViewMatrix() const;
		
	};	
}




