/*
 * Buoy.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Buoy.h"
#include <math.h>
#include "Scene_lua.h"

Buoy::Buoy( Point3D pos ) :
	mFileName( "data/buoy.lua" ),
	mBobHeight( 0.05 ),
	mBobAmount( 0.0 )
{
	mRoot = import_lua( mFileName );
	if ( !mRoot )
	{
		cerr << "ERROR: Buoy - Could not load " << mFileName << endl;
		return;
	}

	// initial min and max point
	//mMinPoint = mPosition - Vector3D(2.0, 0.0, 2.0);
	//mMaxPoint = mPosition + Vector3D(2.0, 0.0, 2.0);

	// initial transformation
	mRoot->Translate( Vector3D( pos[0], pos[1], pos[2] ) );
	mTrans = mRoot->GetTransform();
	mPosition = Point3D( mTrans[0][3], mTrans[1][3], mTrans[2][3] );
	mNormal = mTrans * mNormal;
	mNormal.normalize();
}

Buoy::~Buoy()
{
  // Nothing to do here right now.
}

void Buoy::Update( double delta )
{
	if( mRoot )
	{
		// buoyancy
		mBobAmount += M_PI*delta;
		Vector3D trans( 0.0, sin( mBobAmount ) * mBobHeight, 0.0 );
		mRoot->Translate( trans );

		// update position
		mTrans = mRoot->GetTransform();
		mPosition = Point3D( mTrans[0][3], mTrans[1][3], mTrans[2][3] );
	}
}

void Buoy::Draw()
{
	if( mRoot )
	{
		glPushMatrix();
		mRoot->WalkGl( false );
		glPopMatrix();
	}

	// draw collision box for testing
	glPushMatrix();
	glBegin( GL_QUADS );
	// draw box
	glEnd();
	glPopMatrix();
}

void Buoy::Highlight()
{
	if( mRoot )
	{
		mRoot->Highlight();
	}
}
