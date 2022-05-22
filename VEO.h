#ifndef VEO_CLASS_H
#define VEO_CLASS_H
#include<glad/glad.h>
class VEO
{
	GLuint ID;
public:
	VEO(GLuint* vertices, GLsizeiptr size);
	void Bind();

	void Unbind();

	void Delete();
};
#endif // !VEO_CLASS_H
