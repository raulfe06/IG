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
	glm::fvec4 diffuse = { 0.7, 0.7, 0.7, 1 };
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };
	glm::fvec4 posDir = { 0, 0, 1, 0 };
	bool lightOn;

public:
	Light();
	~Light();
	void disable();
	void switchLight();
	void enable();
	virtual void loadLight(/*...*/);
	void setAmb(glm::fvec4 amb);
	virtual void load(glm::dmat4 const& modelViewMat);
	void setPos(glm::fvec3 pos) { posDir = glm::fvec4(pos, 1.0); };
	void setDir(glm::fvec3 dir) { posDir = glm::fvec4(dir, 0.0); }; //-dir?
	

};

