#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"VAO.h"
#include"VBO.h"
#include"VEO.h"
#include"shaderClass.h"

GLfloat g_vertex_buffer_data[] = {
-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	 0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	 0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	 -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	 0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	 0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};
GLuint indice[] =
{
	0,3,5,
	3,2,4,
	5,4,1
};

int main()
{
	glfwInit(); //init glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// use opengl 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use OpenGL core function package  

	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Tutorial", NULL, NULL); // width,height,tab name, fullscreen toggle, smth
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window \n";
		glfwTerminate();
		return -1;
	} 
	glfwMakeContextCurrent(window);
	gladLoadGL(); // load config for openGL
	glViewport(0, 0, 800, 800);// bottom left , top right coor of the window
	glClearColor(0.1f, 0.9f, 0.7f, 1.0f); // color object
	glClear(GL_COLOR_BUFFER_BIT); // clean back buffer 

	Shader shader = Shader("triangle.vert", "triangle.frag");
	VAO vao = VAO();
	VBO vbo = VBO(g_vertex_buffer_data,sizeof(g_vertex_buffer_data));
	VEO veo = VEO(indice, sizeof(indice));
	vao.LinkVBO(vbo, 0);
	glfwSwapBuffers(window); // swap back buffer with current buffer
	// unbind to prevent accident modification
	vao.Unbind();
	vbo.Unbind();
	veo.Unbind();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.9f, 0.7f, 1.0f); // color object
		glClear(GL_COLOR_BUFFER_BIT); // clean back buffer 
		vao.Bind();
		shader.Activate();
		// Draw the triangle !
		//glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window); // swap back buffer with current buffer
		glfwPollEvents();
	}
	glDisableVertexAttribArray(0);
	vao.Delete();
	veo.Delete();
	shader.Delete();
	glfwDestroyWindow(window);
 	glfwTerminate(); // clsoe glfw
	return 0;
}
