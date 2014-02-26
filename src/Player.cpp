/*
 * Player.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#include "Player.h"

#include <math.h>
#include "scene_lua.h"


Player::Player( Point3D pos ) :
	mFileName( "data/boat.lua" ),
	mVelocity( Vector3D(0.0, 0.0, -40.0) ),
	mWidth( 2.5 ),
	mLength( 5.7 ),
	mHeight( 7.0 )
{
	mRoot = import_lua( mFileName );
	if ( !mRoot )
	{
		cerr << "ERROR: Player - Could not load " << mFileName << endl;
		return;
	}

	// initial min and max point
	mBoundingBox = OBB3D( mPosition, mPosition + Vector3D( 1.5, 1.0, 5.0 ) );

	// set up display list
	mDisplayList = glGenLists( 1 );
	glNewList( mDisplayList, GL_COMPILE );
	mRoot->WalkGl( false );
	glEndList();

	// set normal to be facing into the screen for player
	mNormal = Vector3D( 0.0, 0.0, -1.0 );

	// initial tranformation
	mRoot->Translate( Vector3D( pos[0], pos[1], pos[2] ) );
	mRoot->Rotate( 'y', 90 );
	mTrans = mRoot->GetTransform();
	mLastTrans = mTrans;
	mPosition = Point3D( mTrans[0][3], mTrans[1][3], mTrans[2][3] );
	mLastPosition = mPosition;
	mNormal = mTrans * mNormal;
	mNormal.normalize();
	mLastNormal = mNormal;
}

Player::~Player()
{
  // Nothing to do here right now.
}

void Player::Update( double delta )
{}

void Player::UpdatePosition()
{
	mLastTrans = mTrans;
	mTrans = mRoot->GetTransform();
	mLastPosition = mPosition;
	mPosition = Point3D( mTrans[0][3], mTrans[1][3], mTrans[2][3] );
	mLastNormal = mNormal;
	mNormal = mTrans * mNormal;
	mNormal.normalize();
}

void Player::Draw()
{
	if( mRoot )
	{
		glPushMatrix();
		mTrans = mRoot->GetTransform();
		glLoadMatrixd( mTrans.transpose().begin() );
		glCallList( mDisplayList );
		glPopMatrix();
	}

	// draw collision box for testing
	glPushMatrix();
	glBegin( GL_QUADS );
	//glVertex3d(GetMinPoint()[0], 1.0, GetMinPoint()[1]);
	//glVertex3d(GetMaxPoint()[0], 1.0, GetMinPoint()[1]);
	//glVertex3d(GetMaxPoint()[0], 1.0, GetMaxPoint()[1]);
	//glVertex3d(GetMinPoint()[0], 1.0, GetMaxPoint()[1]);
	glEnd();
	glPopMatrix();
}

void Player::TurnLeft( double delta )
{
	if( mRoot )
	{
		mRoot->Rotate( 'y', delta * 70.0 );
		UpdatePosition();
	}
}

void Player::TurnRight( double delta )
{
	if( mRoot )
	{
		mRoot->Rotate( 'y', -delta * 70.0 );
		UpdatePosition();
	}
}

void Player::MoveForward( double delta )
{
	if( mRoot )
	{
		mRoot->Translate( delta * mVelocity );
		UpdatePosition();
	}
}

void Player::UndoLastMove()
{
	mPosition = mLastPosition;
	mNormal = mLastNormal;
	mTrans = mLastTrans;
	if( mRoot )
	{
		mRoot->SetTransform( mTrans );
	}
}
