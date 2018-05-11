#pragma once
#include "Light.h"
#include <GL/freeglut.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

class Spotlight :
	public Light
{
public:
	Spotlight();
	~Spotlight();
	virtual void loadLight();
	void setSpotDir(glm::fvec3 dir) { dir_ = dir; };

	
private:
	glm::fvec3 dir_;
};

