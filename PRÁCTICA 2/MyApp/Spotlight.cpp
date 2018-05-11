#include "Spotlight.h"



Spotlight::Spotlight()
{
}


Spotlight::~Spotlight()
{
}

void Spotlight::loadLight()
{
	glLightf(id, GL_SPOT_CUTOFF, 15.0);
	glLightf(id, GL_SPOT_EXPONENT,4.0);
	glLightfv(id, GL_SPOT_DIRECTION, value_ptr(dir_));
	Light::loadLight();
}


