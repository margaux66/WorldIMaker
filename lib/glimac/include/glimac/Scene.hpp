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
#include <string>
#include <iostream>

namespace glimac {
	class Scene {
		protected:
			

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

			//light caracteristics 
			glm::vec3 m_Kd,m_Ks, m_LightDir,m_LightPos , m_LightIntensity;
			float m_Shininess;

			//scene catacterictis 
			uint m_width = 20;
			uint m_height = 20;
			uint m_length = 20;

		public: 
			std::vector<Cube> m_allCubes;
			Scene()=default;
			~Scene()=default;
			void createAllCubes();
			const void uniformMatrix(Program program);
			const void updateMatrix(TrackballCamera camera, glm::vec3 position, Cube cube);
			const void updateMatrix(TrackballCamera camera);
			void displayCubes(TrackballCamera camera);
			void setDirectionalLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightDir,glm::vec3 LightIntensity);
			void setPointLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess,glm::vec3 LightPos, glm::vec3 LightIntensity);
			void applyLight(TrackballCamera camera);
			const uint getCubeAtThisPos(glm::vec3 position);
			void clean();
			void setUp();
			void generateScene(std::string filename);

			//get
			const std::vector<Cube>  getAllCubes(){return m_allCubes;};
			inline const uint getWidth(){return m_width;}
			inline const uint getHeight(){return m_height;}
			inline const uint getLenght(){return m_length;}
	};
}