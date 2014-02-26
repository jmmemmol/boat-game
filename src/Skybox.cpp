/*
 * Skybox.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#include "Skybox.h"

Skybox::Skybox() :
	mImageWidth( 512 ),
	mImageHeight( 512 ),
	mDisplayList( 0 )
{
	// set image file names
	mImageNames.push_back( "data/textures/islands_north.png" );
	mImageNames.push_back( "data/textures/islands_east.png" );
	mImageNames.push_back( "data/textures/islands_south.png" );
	mImageNames.push_back( "data/textures/islands_west.png" );
	mImageNames.push_back( "data/textures/islands_up.png" );
	mImageNames.push_back( "data/textures/islands_down.png" );

	// load textures
	for( unsigned int i = 0; i < mImageNames.size(); i++ )
	{
		Texture tex( mImageNames[i] );
		if( !tex.Load() )
		{
			cerr << "ERROR: Skybox - Failed to load texture: " << mImageNames[i] << endl;
			return;
		}
		mTextures.push_back( tex );
	}

	// set up display list
	mDisplayList = glGenLists( 1 );
	glNewList( mDisplayList, GL_COMPILE );
	{
		glEnable( GL_TEXTURE_2D );
		// 1. north face
		for( int i = 0; i < 4; i++ )
		{
			glPushMatrix();
			glTranslated( -400.0 + i*200.0, 25.0, -600.0 );
			glScaled( 100.0, 100.0, 100.0 );

			mTextures[i].Initialize();
			glBegin( GL_QUADS );
			glTexCoord2d(0.0, 0.0); glVertex3d(-1.0, 1.0, -1.0);
			glTexCoord2d(1.0, 0.0); glVertex3d(1.0, 1.0, -1.0);
			glTexCoord2d(1.0, 1.0); glVertex3d(1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3d(-1.0, -1.0, -1.0);
			glEnd();
			glPopMatrix();
		}

		// 2. east face
		for(int i = 0; i < 4; i++)
		{
			glPushMatrix();
			glTranslated(200.0, 25.0, -600.0 + i*200);
			glScaled(100.0, 100.0, 100.0);

			mTextures[i].Initialize();
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d(1.0, 1.0, -1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 1.0); glVertex3d(1.0, -1.0, 1.0);
			glTexCoord2d(0.0, 1.0); glVertex3d(1.0, -1.0, -1.0);
			glEnd();
			glPopMatrix();
		}

		// 3. south face
		for(int i = 0; i < 4; i++)
		{
			glPushMatrix();
			glTranslated(200.0 - i*200, 25.0, 0.0);
			glScaled(100.0, 100.0, 100.0);

			mTextures[i].Initialize();
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0); glVertex3d(1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 0.0); glVertex3d(-1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 1.0);	glVertex3d(-1.0, -1.0, 1.0);
			glTexCoord2d(0.0, 1.0); glVertex3d(1.0, -1.0, 1.0);
			glEnd();
			glPopMatrix();
		}

		// 4. west face
		for(int i = 0; i < 4; i++)
		{
			glPushMatrix();
			glTranslated(-400, 25.0, 0.0 - i*200);
			glScaled(100.0, 100.0, 100.0);

			mTextures[i].Initialize();
			glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0);	glVertex3d(-1.0, 1.0, 1.0);
			glTexCoord2d(1.0, 0.0);	glVertex3d(-1.0, 1.0, -1.0);
			glTexCoord2d(1.0, 1.0); glVertex3d(-1.0, -1.0, -1.0);
			glTexCoord2d(0.0, 1.0); glVertex3d(-1.0, -1.0, 1.0);
			glEnd();
			glPopMatrix();
		}
		glDisable(GL_TEXTURE_2D);
	}
	glEndList();
}

Skybox::~Skybox()
{
  // Nothing to do here right now.
}

void Skybox::Draw()
{
	if(mDisplayList != 0)
	{
		glCallList(mDisplayList);
	}
}
