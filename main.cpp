#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


GLuint build(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	GLuint shaderProgram = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(shaderProgram);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return shaderProgram;
}

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
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	static const GLfloat g_vertex_buffer_data[] = {
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
	glViewport(0, 0, 800, 800);// bottom left , top right coor of the window
	glClearColor(0.1f, 0.9f, 0.7f, 1.0f); // color object
	glClear(GL_COLOR_BUFFER_BIT); // clean back buffer 
	// This will identify our vertex buffer
	GLuint vertexbuffer , ElementBO;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	glGenBuffers(1, &ElementBO);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ElementBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indice), indice, GL_STATIC_DRAW);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(0);
	
	GLuint shaderProgram = build(vertexShaderSource, fragmentShaderSource);
	glfwSwapBuffers(window); // swap back buffer with current buffer
	
	

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.9f, 0.7f, 1.0f); // color object
		glClear(GL_COLOR_BUFFER_BIT); // clean back buffer 
		glUseProgram(shaderProgram);
		// Draw the triangle !
		//glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window); // swap back buffer with current buffer
		glfwPollEvents();
	}
	glDisableVertexAttribArray(0);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &ElementBO);
	glfwDestroyWindow(window);
 	glfwTerminate(); // clsoe glfw
	return 0;
}
