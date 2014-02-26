/*
 * Goal.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#include "Goal.h"

#include <iostream>

Goal::Goal() :
	mLeftBuoy( NULL ),
	mRightBuoy( NULL )
{
}

Goal::Goal( Buoy* left, Buoy* right ) :
	mLeftBuoy( left ),
	mRightBuoy( right )
{
	Point3D rightPos = mRightBuoy->GetPosition();
	Point3D leftPos = mLeftBuoy->GetPosition();
	mPosition = Point3D( ( rightPos[0] + leftPos[0] ) / 2.0,
						 ( rightPos[1] + leftPos[1] ) / 2.0,
						 ( rightPos[2] + leftPos[2] ) / 2.0);
}

Goal::~Goal()
{
  // Nothing to do here right now.
}

void Goal::Highlight()
{
	mLeftBuoy->Highlight();
	mRightBuoy->Highlight();
}

bool Goal::HasPassed( Entity* ent )
{
	// get equation of line
	Point2D point1 = Point2D( mLeftBuoy->GetPosition()[0], mLeftBuoy->GetPosition()[2] );
	Point2D point2 = Point2D( mRightBuoy->GetPosition()[0], mRightBuoy->GetPosition()[2] );
	double m = ( point2[1] - point1[1] )/ ( point2[0] - point1[0] );
	double b = point1[1] - m * point1[0];

	// check if entity intersects with line
	/*Point2D entMinPos = ent->GetMinPoint();
	Point2D entMaxPos = ent->GetMaxPoint();
	double d1 = m*entMinPos[0] + b - entMinPos[1];
	double d2 = m*entMinPos[0] + b - entMaxPos[1];
	double d3 = m*entMaxPos[0] + b - entMaxPos[1];
	double d4 = m*entMaxPos[0] + b - entMinPos[1];

	if((d1 <= 0 && d2 <= 0 && d3 <= 0 && d4 <= 0) || (d1 >=0 && d2 >= 0 && d3 >= 0 && d4 >= 0))
	{
		return(false);
	}
	return(true);
	*/
	return false;
}

bool Goal::CheckCollision( Entity* ent )
{
	// get equation of line
	Point2D point1 = Point2D( mLeftBuoy->GetPosition()[0], mLeftBuoy->GetPosition()[2] );
	Point2D point2 = Point2D( mRightBuoy->GetPosition()[0], mRightBuoy->GetPosition()[2] );
	double m = ( point2[1] - point1[1] ) / ( point2[0] - point1[0] );
	double b = point1[1] - m * point1[0];

	// check if entity intersects with line
	/*Point2D entMinPos = ent->GetMinPoint();
	Point2D entMaxPos = ent->GetMaxPoint();
	double d1 = m*entMinPos[0] + b - entMinPos[1];
	double d2 = m*entMinPos[0] + b - entMaxPos[1];
	double d3 = m*entMaxPos[0] + b - entMaxPos[1];
	double d4 = m*entMaxPos[0] + b - entMinPos[1];

	// if d values are all positive or all negative then they lie on the same side of the line
	// ie. no intersection
	if((d1 <= 0 && d2 <= 0 && d3 <= 0 && d4 <= 0) || (d1 >=0 && d2 >= 0 && d3 >= 0 && d4 >= 0))
	{
		return(false);
	}

	// get equation of line between two points
	Point2D entPoint1 = Point2D(entMinPos[0], entMinPos[1]);
	Point2D entPoint2 = Point2D(entMaxPos[0], entMaxPos[1]);
	double entM = (entPoint2[1] - entPoint1[1])/(entPoint2[0] - entPoint1[0]);
	double entB = point1[1] - entM*entPoint1[0];

	// find intersection point
	double x = (b - entB)/(entM-m);
	double z = m*x+b;

	// get min and max values of end points for line segment and then check if intersection
	// point is within these values
	double minX = point1[0] < point2[0] ? point1[0] : point2[0];
	double maxX	= point1[0] < point2[0] ? point2[0] : point1[0];
	double minZ = point1[1] < point2[1] ? point1[1] : point2[1];
	double maxZ	= point1[1] < point2[1] ? point2[1] : point1[1];

	if(x > minX && x < maxX && z > minZ && z < maxZ)
	{
		return(true);
	}*/
	return(false);
}

void Goal::Draw()
{
	// draw goal line for testing
	glPushMatrix();
	glBegin( GL_LINES );
	glVertex3d( mLeftBuoy->GetPosition()[0], 2.0, mLeftBuoy->GetPosition()[2] );
	glVertex3d( mRightBuoy->GetPosition()[0], 2.0, mRightBuoy->GetPosition()[2] );
	glEnd();
	glPopMatrix();
}
