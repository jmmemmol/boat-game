/*
 * Entity.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Entity.h"

Entity::Entity() :
	mPosition( Point3D() ),
	mNormal( Vector3D(0.0, 0.0, 1.0) ),
	mTrans( Matrix4x4() )
{}

Entity::~Entity()
{}

void Entity::Update( double delta )
{}

void Entity::Draw()
{}

Entity* Entity::CheckCollision( Group group )
{
	for( int i = 0; i < group.Size(); i++ )
	{
		// get min and max points of 2 entities
		Entity* ent2 = group.GetMember( i );

		// check for bounding box collision
	}
	return NULL;
}

bool Entity::CheckCollision( Entity* entity )
{
	// stub for specific entity collision check
	return false;
}
