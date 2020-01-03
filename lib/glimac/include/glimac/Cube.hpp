#pragma once 

#include <glm/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/common.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace glimac {
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
			Cube(glm::vec3 position);
			~Cube()= default;
			Cube(const Cube& c);
			Cube operator=(const Cube& cube);
			
			void display();
			

			void setColor(glm::vec4 color);

			//setter
			inline void setIsVisible(bool visibility){m_isVisible = visibility;};
			inline void setPosition(glm::vec3 position){m_position = position;};

			//getter
			inline glm::vec3 getPosition(){return m_position;};
			inline glm::vec4 getColor(){return m_color;};
			inline bool getIsVisible(){return m_isVisible;};
			//inline std::vector<glimac::Cube> getAllCube(){return m_allCubes;};


	};
}
