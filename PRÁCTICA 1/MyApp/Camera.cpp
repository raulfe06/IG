#include "Camera.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

 void Viewport::setSize(GLsizei aw, GLsizei ah)
 { 
   w = aw; 
   h = ah; 
   set(); 
 }
 void Viewport::setPosition(GLint ax, GLint ay)
 {
	 x = ax;
	 y = ay;
	 set();
 }



 //-------------------------------------------------------------------------

 void Viewport::set() 
 { 
   glViewport(x, y, w, h);
 }
//-------------------------------------------------------------------------

void Camera::setAZ() 
{
  eye= dvec3(0, 0, 500);
  look= dvec3(0, 0, 0);
  up= dvec3(0, 1, 0);

  front = -(normalize(eye - look));
  right = normalize(cross(up, -front));

  viewMat = lookAt(eye, look, up);
  setVM();
}
//-------------------------------------------------------------------------

void Camera::set3D() 
{
	eye = dvec3(500, 500, 500);
	look = dvec3(0, 10, 0);
	up = dvec3(0, 1, 0);

	front = -(normalize(eye - look));
	right = normalize(cross(up, -front));

  viewMat = lookAt(eye, look, up);
  setVM();
}
//-------------------------------------------------------------------------

void Camera::setVM() 
{
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixd(value_ptr(viewMat));
}
//-------------------------------------------------------------------------

void Camera::pitch(GLdouble a) 
{  
	rotatePY(a, 0);
  //viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(1.0, 0, 0));
}
//-------------------------------------------------------------------------
void Camera::yaw(GLdouble a)
{
	rotatePY(0,a);
  //viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 1.0, 0));
}
//-------------------------------------------------------------------------
void Camera::roll(GLdouble a)
{
  viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 0, 1.0));
}
void Camera::moveLR(GLdouble cs)
{
	eye += right * cs;
	viewMat = lookAt(eye, eye+front, up);
}
void Camera::moveFB(GLdouble cs)
{
	eye += -front * cs;
	viewMat = lookAt(eye, eye+front, up);
}
void Camera::moveUD(GLdouble cs)
{
	eye += cross(-front,right) * cs;
	viewMat = lookAt(eye, eye+front, up);
}
void Camera::rotatePY(GLdouble incrPitch, GLdouble incrYaw)
{
	pitch_ += incrPitch;
	yaw_ += incrYaw;
	if (pitch_ > 89.5) pitch_ = 89.5;
	if (yaw_ > 89.5) yaw_ = 89.5;

	front.x = sin(radians(yaw_)) * cos(radians(pitch_));
	front.y = sin(radians(pitch_));
	front.z = -cos(radians(yaw_)) * cos(radians(pitch_));
	front = glm::normalize(front);
	viewMat = lookAt(eye, eye+front, up);
}
//-------------------------------------------------------------------------

void Camera::scale(GLdouble s)
{ 
  factScale -= s; 
  if (s < 0) s = 0.01;
  setPM(); 
}
//-------------------------------------------------------------------------

void Camera::setSize(GLdouble aw, GLdouble ah) 
{
  xRight = aw / 2.0;
  xLeft = -xRight;
  yTop = ah / 2.0;
  yBot = -yTop;
 
  setPM();
}
//-------------------------------------------------------------------------

void Camera::setPM() 
{
  projMat = ortho(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(value_ptr(projMat));
  glMatrixMode(GL_MODELVIEW);
}
void Camera::setPrj()
{
	if (orto) {
		glMatrixMode(GL_PROJECTION);
		projMat = ortho(-500, 500, -250, 250, 500, 1000);
		glLoadMatrixd(value_ptr(projMat));
		glMatrixMode(GL_MODELVIEW);
	}
	else {
		glMatrixMode(GL_PROJECTION);
		projMat = frustum(-500, 500, -250, 250, 500, 10000);
		glLoadMatrixd(value_ptr(projMat));
		glMatrixMode(GL_MODELVIEW);
	}
}
//-------------------------------------------------------------------------


