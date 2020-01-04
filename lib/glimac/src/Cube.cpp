#include <glimac/Cube.hpp>

namespace glimac {

	//tableau d'indices 
		std::vector<uint32_t> indices ={
			0,1,2,    0,2,3, //front
	        0,5,4,    0,4,3, //right
	        5,6,1,    5,1,0, //top
	        1,2,7,    1,7,6, //left
	        4,7,2,    4,2,3, //bottom
	        5,6,7,    5,7,4 //back
		};

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

	Cube::Cube(glm::vec3 position): m_isVisible(false), m_position(position){

		//m_color = glm::vec4(0,1,0,1);
		for (uint i = 0; i < temporary_vertices.size(); ++i)
		{
			glimac::ShapeVertex vertex;

			vertex.texCoords.x = 0;
			vertex.texCoords.y = 1;

			vertex.normal.x = temporary_vertices[i].x;
			vertex.normal.y = temporary_vertices[i].y;
			vertex.normal.z = temporary_vertices[i].z;

			vertex.position = vertex.normal;

			vertex.color = m_color;

			m_vertices.push_back(vertex);
		}

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

		//on passe le tableau d'indices dans l'ibo
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(uint32_t),indices.data(),GL_STATIC_DRAW);
		//on débinde ibo
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

		glGenVertexArrays(1,&m_vao);
		glBindVertexArray(m_vao);

		//binde ibo 
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ibo);

		//on active les différents attributs
        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

        const GLuint VERTEX_ATTR_NORMAL = 1;
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

        const GLuint VERTEX_ATTR_TEXTURE = 2;
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

        const GLuint VERTEX_ATTR_COLOR = 3;
        glEnableVertexAttribArray(VERTEX_ATTR_COLOR);

        //on binde le vbo
        glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

        glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, position));
        glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, normal));
        glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, texCoords));
        glVertexAttribPointer(VERTEX_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, color));
        //debind vbo
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //debinder this->vao
        glBindVertexArray(0);

	}

	Cube::Cube(const Cube& c): m_vertices(c.m_vertices), m_vao(c.m_vao), m_vbo(c.m_vbo), m_ibo(c.m_ibo), m_color(c.m_color), m_isVisible(c.m_isVisible),m_position(c.m_position){}

	Cube Cube::operator =(const Cube &cube){
		Cube res(cube.m_position);
		res.m_vertices = cube.m_vertices;
		res.m_vao = cube.m_vao;
		res.m_vbo = cube.m_vbo;
		res.m_ibo = cube.m_ibo;
		res.m_color = cube.m_color;
		res.m_isVisible = cube.m_isVisible;
		res.m_position = cube.m_position;

		return res; 
	}

	void Cube::display(){
		if(m_isVisible == true){
			setColor(m_color);
			glBindVertexArray(m_vao);
			glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
        	glBindVertexArray(0);
			
		}
		else{
			
	        glBindVertexArray(0);
		}

		
	}

/*	void Cube::display(){
		//setColor(glm::vec4(0,1,0,1));
		glBindVertexArray(m_vao);
		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
	    glBindVertexArray(0);
	}*/


	void Cube::setColor(glm::vec4 color){
		m_color = color;
		for (uint i = 0; i < m_vertices.size(); ++i)
		{
			m_vertices[i].color = color;
			
		}
		

		glGenBuffers(1,&m_vbo);

		//Binding du vbo 
		glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

		//on passe le tableau vertices dans le vbo
		glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*sizeof(glimac::ShapeVertex),m_vertices.data(),GL_STATIC_DRAW);

		//débindage
		glBindBuffer(GL_ARRAY_BUFFER,0);

		glGenVertexArrays(1,&m_vao);
		glBindVertexArray(m_vao);

		//binde ibo 
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_ibo);

		//on active les différents attributs
        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

        const GLuint VERTEX_ATTR_NORMAL = 1;
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);

        const GLuint VERTEX_ATTR_TEXTURE = 2;
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

        const GLuint VERTEX_ATTR_COLOR = 3;
        glEnableVertexAttribArray(VERTEX_ATTR_COLOR);

        //on binde le vbo
        glBindBuffer(GL_ARRAY_BUFFER,m_vbo);

        glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, position));
        glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, normal));
        glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*) offsetof(glimac::ShapeVertex, texCoords));
        glVertexAttribPointer(VERTEX_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, color));
        //debind vbo
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //debinder this->vao
        glBindVertexArray(0);
	}

}
