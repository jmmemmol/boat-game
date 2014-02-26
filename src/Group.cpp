/*
 * Group.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Group.h"
#include "Entity.h"

#include <iostream>
#include <algorithm>
#include "Algebra.h"

Group::Group()
{
}

Group::~Group()
{
  // Nothing to do here right now.
}

void Group::AddMember( Entity* ent )
{
	mMembers.push_back( ent );
}

void Group::RemoveMember( Entity* ent )
{
	vector<Entity*>::iterator it = find( mMembers.begin(), mMembers.end(), ent );
	if( it != mMembers.end() )
	{
		mMembers.erase( it );
	}
}

void Group::Update( double delta )
{
	for( unsigned int i = 0; i < mMembers.size(); i++ )
	{
		mMembers[i]->Update( delta );
	}
}

void Group::Draw()
{
	for( unsigned int i = 0; i < mMembers.size(); i++ )
	{
		mMembers[i]->Draw();
	}
}

Entity* Group::GetMember( int index ) const
{
	if( index < (int)mMembers.size() )
	{
		return mMembers[index];
	}
	return NULL;
}
