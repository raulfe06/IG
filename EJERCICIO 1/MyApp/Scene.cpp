#include "Scene.h"

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST);  
  
  camera->setAZ();
    
  // lights
  // textures  

  // objets
  objetos.push_back(new EjesRGB(200.0));
  //objetos.push_back(new Triangulo(200.0)); //triangulo solo con lineas
  //objetos.push_back(new TrianguloRGB(200.0));
  //objetos.push_back(new TriPyramid(200.0, 500.0));
  //objetos.push_back(new ContCubo(200.0));
 // objetos.push_back(new Dragon(30000));
  objetos.push_back(new Diabolo());
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
  glMatrixMode(GL_MODELVIEW);
  
	for each (Entity* it in objetos)
	{
		it->render(camera->getViewMat());
	}

  //PARA DIVIDIRLO EN 4 VIEWPORTS

 /* double w = viewPort_->getW();
  double h = viewPort_->getH();
  viewPort_->setSize(w/ 2, h/ 2);
  viewPort_->setPosition(0, 0);
  objetos[0]->render(camera->getViewMat());
 viewPort_->setPosition(0, h /2);
  objetos[1]->render(camera->getViewMat());
  viewPort_->setPosition(w / 2, 0);
  objetos[2]->render(camera->getViewMat());
  viewPort_->setPosition(w/ 2, h/2);
  objetos[3]->render(camera->getViewMat());
  viewPort_->setSize(w, h);*/

}
//-------------------------------------------------------------------------

