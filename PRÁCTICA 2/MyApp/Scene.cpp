#include "Scene.h"

//-------------------------------------------------------------------------

void Scene::init()
{ 
	glEnable(GL_TEXTURE_2D);
	// OpenGL basic setting
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST);  
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glEnable(GL_CULL_FACE);
  
  camera->setAZ();
  light_ = new Light();
    
  // lights
  // textures  

  objetos.push_back(new Esfera(100,70,50));

}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources 
  
  for each (Entity* it in objetos)
  {
	  delete it;
  }
}
//-------------------------------------------------------------------------

void Scene::render()
{
  
	light_->load();

	for each (Entity* it in objetos)
	{
		it->render(camera->getViewMat());
	}
 

}
//-------------------------------------------------------------------------

