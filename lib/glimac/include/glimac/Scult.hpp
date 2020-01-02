#pragma once

#include <glimac/Cube.hpp>
#include <glimac/Scene.hpp>
#include <glimac/common.hpp>
#include <glimac/Cursor.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace glimac{
	class Scult {
		protected :


		public : 
		Scult() =default;
		~Scult()=default;
		void add (Cursor cursor,std::vector<Cube> &allCubes);
		void remove(Cursor cursor,std::vector<Cube> &allCubes);
		void extrud(Cursor cursor,std::vector<Cube> &allCubes);
		void dig(Cursor cursor,std::vector<Cube> &allCubes);
		void changeColor(Cursor cursor, glm::vec4 color,std::vector<Cube> &allCubes);
		const void getColor(Cursor cursor,std::vector<Cube> &allCubes);	
	};
}

			