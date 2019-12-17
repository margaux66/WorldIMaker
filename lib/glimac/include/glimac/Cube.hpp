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
			std::vector<glimac::ShapeVertex> vertices;
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			glm::mat3 m_color;

		public :
			Cube();
			void display();
			//Cube select();
			//void remove();
			void setColor(glm::mat3 color);
			void bonsoir();

	};
}
