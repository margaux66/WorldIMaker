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
	///\class Save
	///\brief Classe qui gère la sauvegarde et le chargement de la scène
	class Save {
		protected :

		public :
		///\brief Constructeur
		Save() = default;
		///\brief Destructeur
		~Save() = default;
		///\brief Sauvegarde la scène dans le fichier choisi par l'utilisateur
		///\param Filepath : localisation des fichiers de sauvegarde
		///\param AllCube : ensemble des cubes qui compose la scène
		void saveScene(std::string filepath, std::vector<Cube> allCube);
		///\brief Charge la scène stockée dans le fichier de sauvegarde
		///\param Filepath : localisation des fichiers de sauvegarde
		///\param AllCube : ensemble des cubes qui compose la scène
		void loadScene(std::string filepath, std::vector<Cube> &allCube);

	};
}