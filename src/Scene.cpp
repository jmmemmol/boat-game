/*
 * Scene.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Scene.h"

#include <iostream>
#include <math.h>

using namespace std;

static int nextID = 0;

SceneNode::SceneNode( const std::string& name ) :
		mId( nextID++ ),
		mName( name )
{}

SceneNode::~SceneNode()
{}

void SceneNode::WalkGl( bool picking ) const
{
	glPushMatrix();
	glMultMatrixd( mTrans.transpose().begin() );

	if( picking )
	{
		glPushName( mId );
	}

	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		(*it)->WalkGl( picking );
	}

	if( picking )
	{
		glPopName();
	}

	glPopMatrix();
}

void SceneNode::Highlight()
{
	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		(*it)->Highlight();
	}
}

SceneNode* SceneNode::SelectNode( unsigned int* stackptr )
{
	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		if( (*it)->GetId() == *stackptr )
		{
			stackptr++;
			return (*it)->SelectNode( stackptr );
		}
	}
	return NULL;
}

void SceneNode::ResetJoints()
{
	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		(*it)->ResetJoints();
	}
}


void SceneNode::Rotate( char axis, double angle )
{
	if( IsJoint() )
	{
		JointNode* joint = dynamic_cast<JointNode*>(this);
		switch( axis )
		{
			case 'x':
				joint->SetCurX( joint->GetJointX().cur + angle );
				break;
			case 'y':
				joint->SetCurY( joint->GetJointY().cur + angle );
				break;
			default:
				break;
		}
	}

	angle = angle * M_PI / 180.0;
	Matrix4x4 rotMatrix;
	switch( axis )
	{
    	case 'x':
    		rotMatrix[1][1] = cos( angle );
    		rotMatrix[1][2] = -sin( angle );
    		rotMatrix[2][1] = sin( angle );
    		rotMatrix[2][2] = cos( angle );
    		break;
    	case 'y':
    		rotMatrix[0][0] = cos( angle );
    		rotMatrix[0][2] = sin( angle );
    		rotMatrix[2][0] = -sin( angle );
    		rotMatrix[2][2] = cos( angle );
    		break;
    	case 'z':
    		rotMatrix[0][0] = cos( angle );
    		rotMatrix[0][1] = -sin( angle );
    		rotMatrix[1][0] = sin( angle );
    		rotMatrix[1][1] = cos( angle );
    		break;
    	default:
    		break;
	}

	SetTransform( mTrans * rotMatrix );
}

void SceneNode::Scale( const Vector3D& amount )
{
	Matrix4x4 scaleMatrix;
	scaleMatrix[0][0] = amount[0];
	scaleMatrix[1][1] = amount[1];
	scaleMatrix[2][2] = amount[2];

	mScale = mScale * scaleMatrix;

	SetTransform( mTrans * scaleMatrix );
}

void SceneNode::Translate( const Vector3D& amount )
{
	Matrix4x4 transMatrix;
	transMatrix[0][3] = amount[0];
	transMatrix[1][3] = amount[1];
	transMatrix[2][3] = amount[2];

	SetTransform( mTrans * transMatrix );
}

bool SceneNode::IsJoint() const
{
	return false;
}

bool SceneNode::IsGeometry() const
{
	return false;
}

JointNode::JointNode( const std::string& name ) :
		SceneNode( name ),
		mSelected( false )
{}

JointNode::~JointNode()
{}

void JointNode::WalkGl( bool picking ) const
{
	glPushMatrix();
	glMultMatrixd( mTrans.transpose().begin() );

	if( picking )
	{
		glPushName( mId );
	}

	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		(*it)->WalkGl( picking );
	}

	if( picking )
	{
		glPopName();
	}

	glPopMatrix();
}

SceneNode* JointNode::SelectNode( unsigned int* stackptr )
{
	SceneNode* joint = this;
	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		if( (*it)->GetId() == *stackptr )
		{
			stackptr++;
			SceneNode* node = (*it)->SelectNode( stackptr );
			if( node != NULL )
			{
				joint = node;
			}

			// if we found the joint then select all of its chidren that is geometry
			// and highlight them or un-highlight them if they are already highlighted
			if( joint == this )
			{
				ChildList::const_iterator it2;
				for( it2 = mChildren.begin(); it2 != mChildren.end(); it2++ )
				{
					if( (*it2)->IsGeometry() )
					{
						(*it2)->Highlight();
					}
				}
			}
			return joint;
		}
	}
	return NULL;
}

void JointNode::ResetJoints()
{
	Rotate( 'x', -( mJointX.cur - mJointX.init ) );
	Rotate( 'y', -( mJointX.cur - mJointX.init ) );

	ChildList::const_iterator it;
	for( it = mChildren.begin(); it != mChildren.end(); it++ )
	{
		(*it)->ResetJoints();
	}
}

bool JointNode::IsJoint() const
{
	return true;
}

void JointNode::SetJointX( double min, double init, double max )
{
	mJointX.min = min;
	mJointX.init = init;
	mJointX.max = max;
	mJointX.cur = init;
}

void JointNode::SetJointY( double min, double init, double max )
{
	mJointY.min = min;
	mJointY.init = init;
	mJointY.max = max;
	mJointY.cur = init;
}

double JointNode::RestrictRotateAngle( char axis, double angle ) const
{
	double newAngle;
	switch( axis )
	{
    	case 'x':
    		newAngle = mJointX.cur + angle;
    		if( newAngle > mJointX.max )
    		{
    			angle = mJointX.max - mJointX.cur;
    		}
    		else if( newAngle < mJointX.min )
    		{
    			angle = mJointX.min - mJointX.cur;
    		}
    		break;
    	case 'y':
    		newAngle = mJointY.cur + angle;
    		if( newAngle > mJointY.max )
    		{
    			angle = mJointY.max - mJointY.cur;
    		}
    		else if( newAngle < mJointY.min )
    		{
    			angle = mJointY.min - mJointY.cur;
    		}
    		break;
    	default:
    		break;
	}
	return angle;
}

GeometryNode::GeometryNode( const std::string& name, Primitive* primitive ) :
		SceneNode( name ),
		mTexture( NULL ),
		mMaterial( NULL ),
		mInitMaterial( NULL ),
		mPrimitive( primitive )
{}

GeometryNode::~GeometryNode()
{}

bool GeometryNode::IsGeometry() const
{
	return true;
}

void GeometryNode::WalkGl( bool picking ) const
{
	glPushMatrix();
	glMultMatrixd( mTrans.transpose().begin() );

	if( picking )
	{
		glPushName( mId );
	}

	// apply material
	mMaterial->apply_gl();

	// apply texture if one exists
	if( mTexture )
	{
		glEnable( GL_TEXTURE_2D );
		mTexture->Initialize();
	}

	// draw primitive
	mPrimitive->Draw();

	if( mTexture )
	{
		glDisable( GL_TEXTURE_2D );
	}

	if( picking )
	{
		glPopName();
	}

	glPopMatrix();
}

SceneNode* GeometryNode::SelectNode( unsigned int* stackptr )
{
	return NULL;
}

void GeometryNode::Highlight()
{
	if( mMaterial != mInitMaterial )
	{
		mMaterial = mInitMaterial;
	}
	else
	{
		Material* selectMat = new PhongMaterial( Colour(0.0, 1.0, 0.0), Colour(0.0, 1.0, 0.0), 10 );
		mMaterial = selectMat;
	}
	mMaterial->apply_gl();
}

void GeometryNode::ResetJoints()
{}
