#ifndef VAO_CLASS_H
#define VAO_CLASS_H
#include <glad/glad.h>
#include "VBO.h"
#include"VEO.h"
class VAO
{
	GLuint ID;
public:
	VAO();
	void LinkVBO(VBO &VBO , GLuint L);
	void LinkVEO(VEO& VEO, GLuint L);
	void Bind();
	void Unbind();
	void Delete();


};
#endif // !VAO_CLASS.H

