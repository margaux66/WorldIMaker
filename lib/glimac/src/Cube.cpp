#include <glimac/Cube.hpp>

namespace glimac {
	Cube::Cube(){

		//coordonnées des sommets
		std::vector<glm::vec3> temporary_vertices = {
			glm::vec3(0.5f,0.5f,0.5f),
	        glm::vec3(-0.5f,0.5f,0.5f),
	        glm::vec3(-0.5f,-0.5f,0.5f),
	        glm::vec3(0.5f,-0.5f,0.5f),
	        
	        glm::vec3(0.5f,-0.5f,-0.5f),
	        glm::vec3(0.5f,0.5f,-0.5f),
	        glm::vec3(-0.5f,0.5f,-0.5f),
	        glm::vec3(-0.5f,-0.5f,-0.5f)
		};

		for (uint i = 0; i < temporary_vertices.size(); ++i)
		{
			glimac::ShapeVertex vertex;

			vertex.texCoords.x = 0;
			vertex.texCoords.y = 1;

			vertex.normal.x = temporary_vertices[i].x;
			vertex.normal.y = temporary_vertices[i].y;
			vertex.normal.z = temporary_vertices[i].z;

			vertex.position = vertex.normal;
			vertices.push_back(vertex);
		}

		if(vertices.empty()){
			std::cout<< "Vertices is empty"<<std::endl;
		}
		else{
			std::cout << "Vertices is full" <<std::endl;
		}

		//création du vbo
		glGenBuffers(1,&vbo);

		//Binding du vbo 
		glBindBuffer(GL_ARRAY_BUFFER,vbo);

		//on passe le tableau vertices dans le vbo
		glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glimac::ShapeVertex),vertices.data(),GL_STATIC_DRAW);

		//débindage
		glBindBuffer(GL_ARRAY_BUFFER,0);

		//création de l'ibo
		glGenBuffers(1,&ibo);

		//bindage de ibo
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		//tableau d'indices 
		std::vector<uint32_t> indices ={
			0,1,2,    0,2,3, //front
	        0,5,4,    0,4,3, //right
	        5,6,1,    5,1,0, //top
	        1,2,7,    1,7,6, //left
	        4,7,2,    4,2,3, //bottom
	        5,6,7,    5,7,4 //back
		};

		//on passe le tableau d'indices dans l'ibo
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(uint32_t),indices.data(),GL_STATIC_DRAW);
		//on débinde ibo
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

		glGenVertexArrays(1,&vao);
		glBindVertexArray(vao);

		//binde ibo 
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);

		//on active les différents attributs
        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

        const GLuint VERTEX_ATTR_NORMAL = 1;
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

        const GLuint VERTEX_ATTR_TEXTURE = 2;
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

        //on binde le vbo
        glBindBuffer(GL_ARRAY_BUFFER,vbo);

        glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, position));
        glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, normal));
        glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, texCoords));

        //debind vbo
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //debinder this->vao
        glBindVertexArray(0);

	}

	void Cube::display(){
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
        glBindVertexArray(0);
	}


	void Cube::setColor(glm::mat3 color){
		m_color = color;
	}

	void Cube::bonsoir(){
		std::cout << "BONSOIR" << std::endl;
	}


}
