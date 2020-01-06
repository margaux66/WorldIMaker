#pragma once

#include <glimac/Cube.hpp>
#include <glimac/Scene.hpp>
#include <glimac/common.hpp>
#include <glimac/Cursor.hpp>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace glimac{
	///\class Scult
	///\brief Classe qui gère les différentes modifications apportées à la scène
	class Scult {
		protected :


		public : 
		///\brief Constructeur par défaut
		Scult() =default;
		///\brief Destructeur par défaut
		~Scult()=default;
		///\brief Rend visble le cube à la position du curseur 
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		void add (Cursor cursor,std::vector<Cube> &allCubes);
		///\brief Rend invisble le cube à la position du curseur 
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		void remove(Cursor cursor,std::vector<Cube> &allCubes);
		///\brief Rend visible le cube au sommet de la pile où le curseur est placé
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		void extrud(Cursor cursor,std::vector<Cube> &allCubes);
		///\brief Rend invisible le cube au sommet de la pile où le curseur est placé
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		void dig(Cursor cursor,std::vector<Cube> &allCubes);
		///\brief Change la couleur du cube à la position du curseur
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		void changeColor(Cursor cursor,std::vector<Cube> &allCubes);
		///\brief Renvoie la couleur du cube à la position du curseur
		///\param Cursor : le curseur de la scène
		///\param allCubes : tous les cubes de la scène
		const void getColor(Cursor cursor,std::vector<Cube> &allCubes);	
	};
}

			