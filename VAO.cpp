#include "VAO.h"
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);
}
void VAO::LinkVBO(VBO &VBO, GLuint L)
{
	VBO.Bind();
	glVertexAttribPointer(
		L,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(L);
	VBO.Unbind();
}

void VAO::LinkVEO(VEO& VEO, GLuint L)
{
	VEO.Bind();
	glVertexAttribPointer(
		L,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(L);
	VEO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}
void VAO::Unbind()
{
	glBindVertexArray(0);
}
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
