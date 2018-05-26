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
  camera->setPrj();

  light_ = new Light();
  light_->setDir(glm::fvec3(0, 0, 1));

  spotLight_ = new Spotlight();

  esferaLuz_ = new EsferaLuz(50, 70, 50, 3);

  objetos.push_back(esferaLuz_);

  
  objetos.push_back(new Esfera(100,70,50,0));
  objetos.push_back(new Esfera(100, 70, 50, 1));
  objetos.push_back(new Esfera(100, 70, 50, 2));

  objetos.push_back(new Terreno());

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
	light_->load(camera->getViewMat());

	spotLight_->setPos(camera->getPos());
	spotLight_->setSpotDir(camera->getDir());
	spotLight_->load(camera->getViewMat());

	for each (Entity* it in objetos)
	{
		it->render(camera->getViewMat());
	}
 

}
//-------------------------------------------------------------------------

