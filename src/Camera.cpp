/*
 * Camera.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#include "Camera.h"
#include <iostream>
#include <GLUT/glut.h>

Camera::Camera() :
	mOffset( Point3D( 0.0, 3.0, 20.0 ) ),
	mAttachEntity( NULL )
{
}

Camera::~Camera()
{
  // Nothing to do here right now.
}

void Camera::Update()
{
	if( mAttachEntity )
	{
		Point3D entPos = mAttachEntity->GetPosition();
		Matrix4x4 transform = mAttachEntity->GetTransform();
		Point3D cameraPos = transform * mOffset;
		gluLookAt( cameraPos[0], cameraPos[1], cameraPos[2], // eye at camera position
				   entPos[0], entPos[1], entPos[2], // look towards entity position
				   0.0, 1.0, 0.0 ); // up vector
	}
}

void Camera::Attach( Entity* ent )
{
	mAttachEntity = ent;
}

