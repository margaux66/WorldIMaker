#pragma once 

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glimac/Cube.hpp>
#include <glimac/Scene.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace glimac {
	class Save {
		protected :

		public :
		Save() = default;
		~Save() = default;

		void saveScene(std::string filepath, std::vector<Cube> allCube);
		void loadScene(std::string filepath, std::vector<Cube> &allCube);

	};
}