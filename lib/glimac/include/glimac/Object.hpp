#pragma once 

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glimac/common.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

namespace glimac {
	///\class Object
	///\brief Classe qui gère de manière simplifié l'import d'un objet 3D dans la scène
	class Object {
		protected : 
			std::vector< ShapeVertex> m_vertices;
			std::vector <uint32_t> m_indices;
			GLuint m_vbo, m_vao, m_ibo;

		public :
		///\brief Constructeur
		Object() =default;
		///\brief Destructeur
		~Object() = default;
		///\brief Charge l'objet
		///\param Path : chemin vers le fichier
		///\param Face : Pour savoir si l'objet est constitué de triangles ou de carrés
		void loadOBJ(const std::string path,int face);
		///\brief Initialise les buffers de l'objet
		void setUpOBJ();
		///\brief Affiche l'objet dans le scène
		///\param Face : pour savoir si l'ont doit dessiner des traingles ou des quadrilatères
		void displayOBJ(int face);
	};
}