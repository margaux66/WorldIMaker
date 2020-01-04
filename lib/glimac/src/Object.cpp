#include <glimac/Object.hpp>

namespace glimac {

	void Object::loadOBJ(const std::string path,int face){
		//std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
		

		std::ifstream file(path);

		if (!file.is_open())
			std::cout << "Import OBJ : Can't read the file" << std::endl;
		else{
			std::cout << "Import OBJ : OK" << std::endl;

			while(file){
				std::string element;
				file >> element;
				if(element.compare("v")==0){
					glimac::ShapeVertex vertex;

					glm::vec3 position;
					file >> position.x;
					file >> position.y;
					file >> position.z;

					vertex.position = position;

					m_vertices.push_back(vertex);
				}
				if(element.compare("f")==0){
					uint32_t index;
					for (uint i = 0; i < face; ++i)
					{
						file >> index;
					 	m_indices.push_back(index);
					 	//std::cout << i << "   " << indices << std::endl;
					}
				}
			}
		}
	}

	void Object::setUpOBJ(){
		//création du vbo
		glGenBuffers(1,&m_vbo);

		//Binding du vbo 
		glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

		//on passe le tableau vertices dans le vbo
		glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(glimac::ShapeVertex),m_vertices.data(),GL_STATIC_DRAW);

		//débindage
		glBindBuffer(GL_ARRAY_BUFFER,0);

		//création de l'ibo
		glGenBuffers(1,&m_ibo);

		//bindage de ibo
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(uint32_t),m_indices.data(),GL_STATIC_DRAW);
		//on débinde ibo
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);


		GLuint m_vao;
	     glGenVertexArrays(1, &m_vao);
	     glBindVertexArray(m_vao);

	     const GLuint VERTEX_ATTR_POSITION = 0;
	     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	     glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	     glVertexAttribPointer(VERTEX_ATTR_POSITION,3,GL_FLOAT,GL_FALSE,sizeof(glm::vec3),(const GLvoid*)offsetof(glimac::ShapeVertex, position));
	     glBindBuffer(GL_ARRAY_BUFFER, 0);
	     glBindVertexArray(0); 
	}

	void Object::displayOBJ(int face){
		glBindVertexArray(m_vao);
		if(face == 4){
			glDrawElements(GL_QUADS,m_indices.size(),GL_UNSIGNED_INT,0);
		}
		else if(face == 3){
			glDrawElements(GL_TRIANGLES,m_indices.size(),GL_UNSIGNED_INT,0);
		}
        
        glBindVertexArray(0);
	}	
}