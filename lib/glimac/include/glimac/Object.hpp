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
	class Object {
		protected : 
			std::vector< ShapeVertex> m_vertices;
			std::vector <uint32_t> m_indices;
			GLuint m_vbo, m_vao, m_ibo;

		public :
		Object() =default;
		~Object() = default;
		void loadOBJ(const std::string path,int face);
		void setUpOBJ();
		void displayOBJ(int face);
	};
}