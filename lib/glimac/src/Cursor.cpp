#include <glimac/Cursor.hpp>

namespace glimac {

	Cursor::Cursor(glm::vec3 position) : Cube(position){
                m_color = glm::vec4(0,0,1,1);
	}
	void Cursor::display(){
	    glBindVertexArray(m_vao);
	    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
            glDisable(GL_DEPTH_TEST);
            glDrawElements(GL_LINES,36,GL_UNSIGNED_INT,0);
            glEnable(GL_DEPTH_TEST);
            glBindVertexArray(0);
	}
}