#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include<glad/glad.h>

class VBO
{
	GLuint ID;
	
public :
	VBO(GLfloat* vertices, GLsizeiptr size);

	void Bind();

	void Unbind();

	void Delete();
};


#endif // VBO.H
