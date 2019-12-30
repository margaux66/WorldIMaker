#pragma once 

#include <glm/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/common.hpp>
#include <glimac/Cube.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/Cursor.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>

namespace glimac {
	class Scene {
		protected:
			std::vector<Cube> m_allCubes;

			//matrice uniformes
			GLint uMVPMatrix;
			GLint uMVMatrix;
			GLint uNormalMatrix;
			GLint uKd;
			GLint uKs;
			GLint uShininess;
			GLint uLightDir_vs;
			GLint uLightPos_vs;
			GLint uLightIntensity;
			GLint uColor;

			//matrice 
			glm::mat4 m_ProjMatrix, m_MVMatrix;;
			//directional light caracteristics 
			glm::vec3 m_Kd,m_Ks, m_LightDir,m_LightPos , m_LightIntensity;
			float m_Shininess;

			//scene catacterictis 
			uint m_width = 20;
			uint m_height = 20;
			uint m_length = 20;

		public: 
			Scene()=default;
			~Scene()=default;
			void createAllCubes();
			void uniformMatrix(Program program);
			void updateMatrix(TrackballCamera camera, glm::vec3 position, Cube cube);
			void displayCubes(TrackballCamera camera);
			void setLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightDir,glm::vec3 LightPos, glm::vec3 LightIntensity);
			void applyLight(TrackballCamera camera);
			uint getCubeAtThisPos(glm::vec3 position);
			void add (Cursor cursor);
			void remove(Cursor cursor);
			void extrud(Cursor cursor);
			void dig(Cursor cursor);
			void changeColor(Cursor cursor, glm::vec4 color);
			void getColor(Cursor cursor);
			void clean();
			void setUp();

			//get
			std::vector<Cube> getAllCubes(){return m_allCubes;};
			inline uint getWidth(){return m_width;}
			inline uint getHeight(){return m_height;}
			inline uint getLenght(){return m_length;}
	};
}