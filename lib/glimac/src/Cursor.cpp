#include <glimac/Cursor.hpp>

namespace glimac {

	Cursor::Cursor(glm::vec3 position, glm::vec4 color) : Cube(position,color){

	}
	void Cursor::display(){
	    glBindVertexArray(m_vao);
	    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDisable(GL_DEPTH_TEST);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
        glEnable(GL_DEPTH_TEST);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBindVertexArray(0);
	}
}