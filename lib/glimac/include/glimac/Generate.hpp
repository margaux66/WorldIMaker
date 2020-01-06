#pragma once 

#include <glm/glm.hpp>
#include <Eigen/Dense>
#include <GL/glew.h>
#include <glimac/Cube.hpp>
#include <glimac/Scene.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>


namespace glimac {
	///\struct ControlPoint
	///\brief Structure des points de contrôle
	///\param Position : position (x,y,z) du point de contrôle
	///\param Value : poids du point de contrôle
	struct ControlPoint {
	    glm::vec3 position;
	    double value;
	};

	///\class Generate
	///\brief Classe qui gère la génération procédural de la scène
	class Generate {
	private:
		std::vector<ControlPoint> m_controlPoints;
		std::vector<double> m_rbf;

	public:
		Generate() = default;
		~Generate()=default;
		///\brief Lit le fichier où sont stockés les points de contrôle afin de les stocker dans un vector
		///\param Filepath : chemin vers le fichiers où sont stockés les points de contrôle
		void readControlPoints(std::string filepath);
		///\brief Calcule la norme du vecteur passé en paramètre
		///\param Vec : vecteur dont on veut calculet la norme
		const double norm(const glm::vec3 &vec);
		///\brief Met en place le système et le résout afin d'obtenir le vecteur avec les omega
		///\return Un vecteur avec la solution du système
		const Eigen::VectorXd omega();
		/*!
		*\brief Calcule les RBF
		*
		* Si le type est égal à 1 : fonction linéaire 
		*
		* Si le type est égal à 2 : fonction multiquadrique
		*
		* Si le type est égal à 3 : fonction inverce quadrique
		*
		* Si le type est égal à 4 : fonction inverce multiquadrique
		*/
		///\param vec : position du cube sur lequel on applique une rbf
		///\param type : type de la rbf
		void RBF(glm::vec3 vec,int type);
		///\brief Applique la RBF selon son tyoe sur la scène
		///\param AllCube : Tous les cubes de la scène
		///\param Type : type de la fonction radiale
		const void applyRBF(std::vector<Cube> &allCube,int type);

	};
}