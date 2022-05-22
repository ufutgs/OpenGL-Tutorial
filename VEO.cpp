#include"VEO.h"
VEO::VEO(GLuint* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID); // generate buffer 
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); // bind buffer to GL_ELEMENT_ARRAY_BUFFER
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW); // declare current GL_ELEMENT_ARRAY_BUFFER buffer data
}
void VEO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);// bind GL_ELEMENT_ARRAY_BUFFER to this buffer 
}
void VEO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);// unbind GL_ELEMENT_ARRAY_BUFFER to this buffer 
}
void VEO::Delete()
{
	glDeleteBuffers(1, &ID); // delete this buffer
}