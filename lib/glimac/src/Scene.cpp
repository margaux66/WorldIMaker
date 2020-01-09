#include <glimac/Scene.hpp>

namespace glimac {
	void Scene::createAllCubes(){

		for(uint i = 0; i<m_length; i++){
	        for (int j = 0; j < m_height; ++j){
	            for (int k = 0; k < m_width; ++k){
	            	Cube cube(glm::vec3(k,j,i));
	                m_allCubes.push_back(cube);
	            }
	        }
	    }
	}

	const void Scene::uniformMatrix(Program program){
		uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
	    uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
	    uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
	    uKd = glGetUniformLocation(program.getGLId(), "uKd");
	    uKs = glGetUniformLocation(program.getGLId(), "uKs");
	    uShininess = glGetUniformLocation(program.getGLId(), "uShininess");
	    uLightDir_vs = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
	    uLightPos_vs = glGetUniformLocation(program.getGLId(), "uLightPos_vs");
	    uLightIntensity = glGetUniformLocation(program.getGLId(), "uLightIntensity");

	    uColor = glGetUniformLocation(program.getGLId(), "uColor");

	    m_ProjMatrix = glm::perspective(glm::radians(70.f),800.f/600.f,0.1f, 100.f);

    	m_MVMatrix = glm::translate(glm::mat4(1.0f),glm::vec3(0,0,-10));

    	glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(m_MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(m_MVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( m_ProjMatrix * m_MVMatrix));

	}

	const void Scene::updateMatrix(TrackballCamera camera, glm::vec3 position, Cube cube){
		m_MVMatrix = camera.getViewMatrix();
		glm::mat4 cubeMVMatrix = glm::translate(m_MVMatrix,position);
		glUniform4fv(uColor, 1, glm::value_ptr(cube.getColor()));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cubeMVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cubeMVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( m_ProjMatrix * cubeMVMatrix));
	}

	const void Scene::updateMatrix(TrackballCamera camera){
		m_MVMatrix = camera.getViewMatrix();
		glm::mat4 cubeMVMatrix = glm::translate(m_MVMatrix,glm::vec3(0,0,0));
		glUniform4fv(uColor, 1, glm::value_ptr(glm::vec4(0,1,1,1)));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(cubeMVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cubeMVMatrix))));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr( m_ProjMatrix * cubeMVMatrix));
	}

	void Scene::displayCubes(TrackballCamera camera){
		for (int i = 0; i < m_allCubes.size(); ++i)
		{
			updateMatrix(camera,m_allCubes[i].getPosition(),m_allCubes[i]);
			m_allCubes[i].setColor(m_allCubes[i].getColor());
			m_allCubes[i].display();
		}
	}

	void Scene::setDirectionalLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightDir,glm::vec3 LightIntensity){
		m_Kd = Kd;
		m_Ks = Ks;
		m_Shininess = Shininess;
		m_LightDir = LightDir;
		m_LightIntensity = LightIntensity;
	}
	void Scene::setPointLight(glm::vec3 Kd, glm::vec3 Ks, float Shininess, glm::vec3 LightPos,glm::vec3 LightIntensity){
		m_Kd = Kd;
		m_Ks = Ks;
		m_Shininess = Shininess;
		m_LightPos = LightPos;
		m_LightIntensity = LightIntensity;
	}


	void Scene::applyLight(TrackballCamera camera){
		glUniform3fv(uKd, 1, glm::value_ptr(m_Kd));
        glUniform3fv(uKs, 1, glm::value_ptr(m_Ks));
        glUniform1f(uShininess, m_Shininess);
        glUniform3fv(uLightDir_vs, 1, glm::value_ptr(glm::mat3(camera.getViewMatrix())*m_LightDir));
        glUniform3fv(uLightPos_vs, 1, glm::value_ptr(glm::mat3(camera.getViewMatrix())*m_LightPos));
        glUniform3fv(uLightIntensity, 1, glm::value_ptr(m_LightIntensity));

	}

	const uint Scene::getCubeAtThisPos(glm::vec3 position){
		return position.y * m_width + position.x + position.z * m_width * m_length;
	}


	
	void Scene::clean(){
		for (int i = 0; i < m_allCubes.size(); ++i)
		{
			m_allCubes[i].setIsVisible(false);
		}

	}

	void Scene::setUp(){
		for (int x = 0; x < m_width ; ++x){	
			for (int z = 0; z < m_length; ++z){
				for (int y = 0; y < 3; ++y)
				{
					m_allCubes[getCubeAtThisPos(glm::vec3(x,y,z))].setIsVisible(true);
					m_allCubes[getCubeAtThisPos(glm::vec3(x,y,z))].setColor(glm::vec4 (253, 238, 0,1));
				}
			}
		}

	}

}