#include "VBO.h"
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);// generate buffer  
	glBindBuffer(GL_ARRAY_BUFFER, ID); // bind buffer to GL_ARRAY_BUFFER
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
};

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID); // bind buffer to GL_ARRAY_BUFFER
}
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0); // unbind buffer to GL_ARRAY_BUFFER
}
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}