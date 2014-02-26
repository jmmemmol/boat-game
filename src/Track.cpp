/*
 * Track.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#include "Track.h"

#include <math.h>
#include "Scene_lua.h"

Track::Track() :
	mFileName("data/track.lua")
{
	mRoot = import_lua(mFileName);
	if (!mRoot)
	{
		cerr << "ERROR: Track - Could not load " << mFileName << endl;
		return;
	}

	// set up display list
	mDisplayList = glGenLists(1);
	glNewList(mDisplayList, GL_COMPILE);
	mRoot->WalkGl(false);
	glEndList();
}

Track::~Track()
{
  // Nothing to do here right now.
}

void Track::Draw()
{
	glPushMatrix();
	glCallList(mDisplayList);
	glPopMatrix();
}

Point2D Track::GetMinPoint()
{
	return(Point2D());
}

Point2D Track::GetMaxPoint()
{
	return(Point2D());
}

bool Track::CheckCollision(Entity* ent)
{
	/*Point2D entMinPos = ent->GetMinPoint();
	Point2D entMaxPos = ent->GetMaxPoint();

	// check collision with inner cylinder
	Point2D innerCenter(0.0, -195);
	// check if center is within rectangle
	if(innerCenter[0] > entMinPos[0] && innerCenter[0] < entMaxPos[0] &&
	   innerCenter[1] > entMinPos[1] && innerCenter[1] < entMaxPos[1])
	{
		return(true);
	}
	// otherwise check if distance to any corner of entity is closer than the radius
	double dist1 = sqrt(pow(entMinPos[0] - innerCenter[0], 2) + pow(entMinPos[1] - innerCenter[1], 2));
	double dist2 = sqrt(pow(entMinPos[0] - innerCenter[0], 2) + pow(entMaxPos[1] - innerCenter[1], 2));
	double dist3 = sqrt(pow(entMaxPos[0] - innerCenter[0], 2) + pow(entMaxPos[1] - innerCenter[1], 2));
	double dist4 = sqrt(pow(entMaxPos[0] - innerCenter[0], 2) + pow(entMinPos[1] - innerCenter[1], 2));
	if(dist1 < 150 || dist2 < 150 || dist3 < 150 || dist4 < 150)
	{
		return(true);
	}

	// check collision with outer cylinder
	Point2D outerCenter(0.0, -200);

	// check if distance to any corner of entity is closer than the radius
	dist1 = sqrt(pow(entMinPos[0] - outerCenter[0], 2) + pow(entMinPos[1] - outerCenter[1], 2));
	dist2 = sqrt(pow(entMinPos[0] - outerCenter[0], 2) + pow(entMaxPos[1] - outerCenter[1], 2));
	dist3 = sqrt(pow(entMaxPos[0] - outerCenter[0], 2) + pow(entMaxPos[1] - outerCenter[1], 2));
	dist4 = sqrt(pow(entMaxPos[0] - outerCenter[0], 2) + pow(entMinPos[1] - outerCenter[1], 2));
	if(dist1 < 200 || dist2 < 200 || dist3 < 200 || dist4 < 200)
	{
		return(false);
	}
	return(true); // entity is not within outer wall*/
	return false;
}
