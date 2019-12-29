#pragma once 

#include <glm/glm.hpp>
#include <glimac/Cube.hpp>

namespace glimac {
	
	class Cursor : public Cube{

		public:
			Cursor(glm::vec3 position);
			~Cursor()=default;
			void display();
		
	};
}