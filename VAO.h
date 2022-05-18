#ifndef VAO_CLASS.H
#define VAO_CLASS.H
#include <glad/glad.h>
#include "VBO.h"
class VAO
{
	GLuint ID;
public:
	VAO();
	void LinkVBO(VBO &VBO , GLuint L);
	void Bind();
	void Unbind();
	void Delete();


};
#endif // !VAO_CLASS.H

