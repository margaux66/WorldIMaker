#pragma once 

#include <glm/glm.hpp>
#include <Eigen/Dense>
#include <GL/glew.h>
#include <vector>
#include <string>
#include <iostream>


namespace glimac {

	struct ControlPoint {
	    glm::vec3 position;
	    float value;
	};

	class Generate {
		Generate() = default;
		~Generate()=default;

		std::vector<ControlPoint> readControlPoints(std::string fileName);


	};
}