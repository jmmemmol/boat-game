/*
 * Water.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#include "Water.h"

#include <math.h>

Water::Water() :
	mDisplayList(0),
	mTexture(NULL)
{}

Water::Water(Texture* tex) :
	mTexture(tex)
{
	mDisplayList = glGenLists(1);
	glNewList(mDisplayList, GL_COMPILE);
	{
		glTranslated(-250.0, 0.0, -500.0);
		glScaled(600.0, 600.0, 600.0);
		//glColor4d(8.0, 0.5, 0.45, 0.9);
		glColor4d(0.81, 0.89, 0.94, 0.9);

		glEnable(GL_TEXTURE_2D);
		mTexture->Initialize(false);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0); glVertex3d(0.0, 0.0, 1.0);
		glTexCoord2d(100.0, 0.0); glVertex3d(1.0, 0.0, 1.0);
		glTexCoord2d(100.0, 100.0);	glVertex3d(1.0, 0.0, 0.0);
		glTexCoord2d(0.0, 100.0); glVertex3d(0.0, 0.0, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
  }
  glEndList();
}

Water::~Water()
{
  // Nothing to do here right now.
}

void Water::Update(double delta)
{}

void Water::Draw()
{
	glPushMatrix();
	glCallList(mDisplayList);
	glPopMatrix();
}
