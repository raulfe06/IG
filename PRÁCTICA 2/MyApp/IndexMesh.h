#pragma once
#include "Mesh.h"
#include <fstream>
class IndexMesh :
	public Mesh
{
public:
	IndexMesh();
	~IndexMesh();
	void draw();
	static IndexMesh* generateGrid(GLdouble lado, GLuint numDiv);
	static IndexMesh* generateTerrain();
protected:
	GLuint * indices = nullptr;
	GLuint numIndices = 0;
	virtual void enable();
	virtual void disable();


};

