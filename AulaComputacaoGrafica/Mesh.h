#include <GL/glew.h>

#pragma once
class Mesh
{
	public:
		Mesh();
		//Destrutor
		~Mesh();
		//unsigned int - inteiros positivos
		void CreatMesh(GLfloat *vertices, unsigned int numOfVertices, GLuint *indices, unsigned int numOfIndices);
		void RenderMesh();

	private:
		GLuint VAO, VBO, IBO;
		unsigned int numOfIndices;

};

