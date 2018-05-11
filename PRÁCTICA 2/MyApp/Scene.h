//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <vector>
#include "Camera.h"
#include "Entities.h"
#include "Light.h"
#include "Spotlight.h"

//-------------------------------------------------------------------------

class Scene	
{ 
public:
    Scene(Camera* cam,Viewport* viewPort): camera(cam),viewPort_(viewPort) { };
	  ~Scene();
    void init();
	  void render();    
	  Entity* getObject(int num) const { return objetos[num]; };
	  Spotlight* getSpotLight() { return spotLight_; };
	  Light* getLight() { return light_; };
	  
protected:
	  Camera* camera;
	  Viewport* viewPort_;
	  std::vector<Entity*> objetos;
	  Light* light_;
	  Spotlight* spotLight_;

	  

};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

