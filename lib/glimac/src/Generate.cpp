#include <glimac/Generate.hpp>

namespace glimac {
	 void Generate::readControlPoints(std::string filepath){
		std::ifstream controlPts(filepath);
		if(controlPts){
			std::string element;
			getline(controlPts,element);

			if(element.compare("RBF") != 0){
				std::cerr <<"Read control points : The file is not valid." <<std::endl;
				controlPts.close();
				return;
			}
			
			while(controlPts){
				ControlPoint cp;
				controlPts >> cp.position.x;
				controlPts >> cp.position.y;
				controlPts >> cp.position.z;
				controlPts >> cp.value;

				m_controlPoints.push_back(cp);
			}

			controlPts.close();
			return;
		}
		else{
			std::cerr << "Read control points : Can't open the file" << std::endl;
			return;
		}
	}

	const double Generate::norm(const glm::vec3 &vec){
		double norm = sqrt(vec.x * vec.x+ vec.y*vec.y + vec.z*vec.z);
		return norm;
	}

	const Eigen::VectorXd Generate::omega(){
		Eigen::MatrixXd mat = Eigen::MatrixXd::Ones(m_controlPoints.size(),m_controlPoints.size());
		Eigen::VectorXd value = Eigen::VectorXd::Ones(m_controlPoints.size());
		for (uint i = 0; i < m_controlPoints.size(); ++i)
		{

			value[i]=m_controlPoints[i].value;
		}

		for (uint j = 0; j < m_controlPoints.size(); ++j)
		{
			for (uint k = 0; k < m_controlPoints.size() ; ++k)
			{
				mat(j,k) = norm(m_controlPoints[j].position - m_controlPoints[k].position);
			}
			
		}

		Eigen::PartialPivLU<Eigen::MatrixXd> lu(mat);
		Eigen::VectorXd result = lu.solve(value);

		return result;
	}

	void Generate::RBF(glm::vec3 vec){
		Eigen::VectorXd Omega = this->omega();
		std::vector <double> result;

		for (int i = 0; i < m_controlPoints.size(); ++i)
		{
			result.push_back(Omega[i]*glm::distance(vec,m_controlPoints[i].position));
		}

		m_rbf = result;

		
	}

	const void Generate::applyRBF(std::vector<Cube> &allCube){
		std::cout<< "RBF coucou 2" <<std::endl;
		for( uint c = 0; c < allCube.size(); ++c){
			RBF(allCube[c].getPosition());
			double value = 0 ;
			for (int i = 0; i < m_rbf.size(); ++i)
			{	
				value += m_rbf[i];
			}

			if (value > 0.0)
			{
				allCube[c].setIsVisible(true);
			}
			else{
				allCube[c].setIsVisible(false);
			}
		}
		return;
	}
}