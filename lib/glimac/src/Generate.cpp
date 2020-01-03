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
				std::cout<< cp.position.x <<std::endl;
				controlPts >> cp.position.y;
				std::cout<< cp.position.y <<std::endl;
				controlPts >> cp.position.z;
				std::cout<< cp.position.z <<std::endl;
				controlPts >> cp.value;
				std::cout<< cp.value<<std::endl;

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

		Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(mat);
		Eigen::VectorXd result = qr.solve(value);

		return result;
	}

	void Generate::RBF(glm::vec3 vec){
		Eigen::VectorXd Omega = this->omega();
		std::vector <double> result;
		

		for (int i = 0; i < m_controlPoints.size(); ++i)
		{
			double d = glm::distance(vec,m_controlPoints[i].position);
			result.push_back(Omega[i]* sqrt(1 + pow(1+d,2)));
		}

		m_rbf = result;

		
	}

	const void Generate::applyRBF(std::vector<Cube> &allCube){
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