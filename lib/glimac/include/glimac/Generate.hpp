#pragma once 

#include <glm/glm.hpp>
#include <Eigen/Dense>
#include <GL/glew.h>
#include <glimac/Cube.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>


namespace glimac {

	struct ControlPoint {
	    glm::vec3 position;
	    double value;
	};

	class Generate {
	private:
		std::vector<ControlPoint> m_controlPoints;

	public:
		Generate() = default;
		~Generate()=default;

		void readControlPoints(std::string filepath);
		const double norm(const glm::vec3 &vec);
		const Eigen::VectorXd omega();
		const std::vector<double> RBF(glm::vec3 vec);
		const void applyRBF(std::vector<Cube> allCube);

	};
}