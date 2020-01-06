#pragma once 

#include <glm/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/common.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace glimac {
	/// \class Cube
	/// \brief Classe qui gère la création d'un cube
	class Cube {
		protected:
			
			std::vector<glimac::ShapeVertex> m_vertices;
			GLuint m_vao;
			GLuint m_vbo;
			GLuint m_ibo;
			glm::vec4 m_color= glm::vec4(0,1,0,1);
			bool m_isVisible;
			glm::vec3 m_position;

		public :
			///\brief Constructeur par défaut place le cube à la position passée en paramètre et initialise les buffers du cube
			///\param Position : position que va prendre le cube dans la scène
			Cube(glm::vec3 position);
			///\brief Destructeur
			~Cube()= default;
			///\brief Constructeur par recopie
			///\param cube : le cube a copier
			Cube(const Cube& c);
			///\brief Opérateur d'affectation
			Cube operator=(const Cube& cube);
			
			///\brief Affiche le cube dans la fenêtre
			void display();
			
			///\brief Change la couleur du cube par celle passée en paramètre
			////\param color : couleur (RGBA) que va prendre le cube
			void setColor(glm::vec4 color);

			//setter
			///\brief Affecte la valeur passer en paramètre à l'attribut isVisible
			///\param visibilty : vaut vrai ou faux selon si le cube apparaît ou non dans la scène
			inline void setIsVisible(bool visibility){m_isVisible = visibility;};
			///\brief Affecte la valeur passer en paramètre à l'attribut position
			///\param position : position (x,y,z) que va prendre le cube
			inline void setPosition(glm::vec3 position){m_position = position;};

			//getter
			///\brief Retourne la valeur de la position
			inline glm::vec3 getPosition(){return m_position;};
			///\brief Retourne la valeur de la couleur
			inline glm::vec4 getColor(){return m_color;};
			///\brief Retourne si le cube est visible ou non
			inline bool getIsVisible(){return m_isVisible;};

			//inline std::vector<glimac::Cube> getAllCube(){return m_allCubes;};


	};
}
