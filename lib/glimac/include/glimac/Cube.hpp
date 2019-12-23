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
		private :
			std::vector<glimac::ShapeVertex> m_vertices;
			GLuint m_vao;
			GLuint m_vbo;
			GLuint m_ibo;
			glm::vec3 m_color;
			bool m_isVisible;
			bool m_isSelected;

		public :
			Cube();
			void display();
			//Cube select();
			//void remove();
			void setColor(glm::vec3 color);
			void bonsoir();

	};
}
