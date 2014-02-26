/*
 * Crate.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#include "Crate.h"
#include "Scene_lua.h"

// display list stuff
static bool gDisplayListCreated = false;
static GLuint gCrateDisplayList;

Crate::Crate( Point3D pos ) :
		mRoot( NULL ),
		mFileName( "data/crate.lua" ),
		mBobHeight( 0.03 ),
		mBobAmount( 0.0 )
{
	// set position of crate
	mPosition = pos;

	mRoot = import_lua( mFileName );
	if ( !mRoot )
	{
		cerr << "ERROR: Crate - Could not load " << mFileName << endl;
		return;
	}

	if( !gDisplayListCreated )
	{
		// set up display list
		gCrateDisplayList = glGenLists( 1 );
		glNewList( gCrateDisplayList, GL_COMPILE );
		mRoot->WalkGl( false );
		glEndList();
		gDisplayListCreated = true;
	}
}

Crate::~Crate()
{
  // Nothing to do here right now.
}

void Crate::Update( double delta )
{
	// buoyancy
	mBobAmount += M_PI * delta;
	Vector3D trans( 0.0, sin( mBobAmount ) * mBobHeight, 0.0 );

	// update position
	mPosition = mPosition + trans;
}

void Crate::Draw()
{
	if( gDisplayListCreated )
	{
		glPushMatrix();
		glTranslated( mPosition[0], mPosition[1], mPosition[2] );
		glCallList( gCrateDisplayList );
		glPopMatrix();
	}
}
