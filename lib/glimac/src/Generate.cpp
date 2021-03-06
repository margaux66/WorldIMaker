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
				mat(j,k) = norm(m_controlPoints[k].position - m_controlPoints[j].position);
			}
			
		}

		Eigen::ColPivHouseholderQR<Eigen::MatrixXd> qr(mat);
		Eigen::VectorXd result = qr.solve(value);
		

		return result;
	}

	void Generate::RBF(glm::vec3 vec, int type){
		Eigen::VectorXd Omega = this->omega();
		std::vector <double> result;
		

		for (uint i = 0; i < m_controlPoints.size(); ++i)
		{
			double d = glm::distance(vec,m_controlPoints[i].position);
			switch (type){
				case 1:
					result.push_back(Omega[i]*d);
					break;
				case 2: 
					result.push_back(Omega[i]* sqrt(1 + pow(1*d,2)));
					break;
				case 3:
					result.push_back(Omega[i]*(1/(1+pow(1*d,2))));
					break;
				case 4:
					result.push_back(Omega[i]* (1/sqrt(1 + pow(1*d,2))));
					break;
				case 5:
					result.push_back(Omega[i]* (exp(-1*pow(1*d,2))));
					break;
				case 6:
					result.push_back(Omega[i]* (cos(0.4*d)));
					break;	

			}
		}

		m_rbf = result;

		
	}

	const void Generate::applyRBF(std::vector<Cube> &allCube,int type){
		for( uint c = 0; c < allCube.size(); ++c){
			RBF(allCube[c].getPosition(),type);
			double value = 0 ;
			for (uint i = 0; i < m_rbf.size(); ++i)
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