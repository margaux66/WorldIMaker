#pragma once 

#include <glm/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/common.hpp>
#include <glimac/Cube.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cursor.hpp>
#include <GL/glew.h>
#include <vector>
#include <string>
#include <iostream>

///\namespace glimac
///\brief Librairie glimac qui comprend l'intégralité du projet
namespace glimac {
	///\class Scene
	///\brief Classe qui gère la scène, donc tous les cubes qui la composent et la lumière
	class Scene {
		protected:
			

			//matrice uniformes
			GLint uMVPMatrix;
			GLint uMVMatrix;
			GLint uNormalMatrix;
			GLint uKd;
			GLint uKs;
			GLint uShininess;
			GLint uLightDir_vs;
			GLint uLightPos_vs;
			GLint uLightIntensity;
			GLint uColor;

			//matrice 
			glm::mat4 m_ProjMatrix, m_MVMatrix;;

			//light caracteristics 
			glm::vec3 m_Kd,m_Ks, m_LightDir,m_LightPos , m_LightIntensity;
			float m_Shininess;

			//scene catacterictis 
			uint m_width = 20;
			uint m_height = 20;
			uint m_length = 20;

		public: 
			std::vector<Cube> m_allCubes;
			///\brief Constructeur
			Scene()=default;
			///\brief Destructeur
			~Scene()=default;
			///\brief Créée tous les cubes de la scènes même ceux qui ne sont pas visibles
			void createAllCubes();
			///\brief Créée toutes les variables uniformes de la scène et les lie aux shaders
			///\param Program : fait le lien entre l'application et les shaders
			const void uniformMatrix(Program program);
			///\brief Met à jours les variables uniformes selon le contexte d'affichage
			///\param Camera : la camera de la scène
			///\param Position : position de l'objet
			///\param Cube : cube que l'on souhaite afficher
			const void updateMatrix(TrackballCamera camera, glm::vec3 position, Cube cube);
			///\brief Surcharge de la fonction updateMatrix qui ne prend en paramètre que la camera
			const void updateMatrix(TrackballCamera camera);
			///\brief Affiche tous les cubes de la scène
			///\param Camera : caméra de la scène
			void displayCubes(TrackballCamera camera);
			///\brief Met en place la lumière directionnelle de la scène
			void setDirectionalLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightDir,glm::vec3 LightIntensity);
			///\brief Met en place la lumière pontuelle de la scène
			void setPointLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess,glm::vec3 LightPos, glm::vec3 LightIntensity);
			///\brief Applique la lumière
			void applyLight(TrackballCamera camera);
			///\brief Donne l'indice du cube à la position donnée en paramètre
			///\param Position : position (x,y,z) du cube dont on veut connaître l'indice dans le tableau de cubes
			///\return Renvoie l'indice du cube à la position
			const uint getCubeAtThisPos(glm::vec3 position);
			///\brief Efface tous les cubes de la scène
			void clean();
			///\brief Met en place la scène de base avec trois couches de cubes
			void setUp();

			//get
			///\bief Renvoie tous les cubes de la scène qu'ils soient visibles ou non
			inline const std::vector<Cube>  getAllCubes(){return m_allCubes;};
			///\brief Renvoie la largeur de la scène
			inline const uint getWidth(){return m_width;}
			///\brief Renvoie la hauteur de la scène
			inline const uint getHeight(){return m_height;}
			///\brief Renvoie la longueur de la scène
			inline const uint getLenght(){return m_length;}
	};
}