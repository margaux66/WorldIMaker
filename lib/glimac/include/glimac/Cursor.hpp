#pragma once 

#include <glm/glm.hpp>
#include <glimac/Cube.hpp>

namespace glimac {
	///\class Cursor
	///\brief Classe qui hérite de la classe Cube, qui gère la création du cursor
	class Cursor : public Cube{

		public:
			///\brief Constructeur qui initialise la curseur à la position passée en paramètre
			///\param Position ; position (x,y,z) du curseur
			Cursor(glm::vec3 position);
			///\brief Destructeur
			~Cursor()=default;
			///\brief Gère l'affichage du curseur dans la scène
			void display();
			
		
	};
}