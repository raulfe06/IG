#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
class Light
{
protected:
	static GLuint cont; // valor inicial cont = 0
	GLuint id = GL_MAX_LIGHTS; // GL_LIGHTi
	glm::fvec4 ambient = { 0.1, 0.1, 0.1, 1 };
	glm::fvec4 diffuse = { 0.5, 0.5, 0.5, 1 };
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };

public:
	Light();
	~Light();
	void disable();
	void enable();
	virtual void load(/*...*/);
	void setAmb(glm::fvec4 amb);
};

