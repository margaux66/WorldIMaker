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
			glm::vec4 m_color;
			bool m_isVisible;
			bool m_isSelected;

		public :
			Cube();
			void display();
			//Cube select();
			//void remove();
			inline void setIsVisible(bool visibility){m_isVisible = visibility;};
			inline void setIsSelected(bool selected){m_isSelected = selected;};
			void setColor(glm::vec4 color);
			void bonsoir();

	};
}
