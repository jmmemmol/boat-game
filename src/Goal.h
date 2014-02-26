/*
 * Goal.h
 *
 *  Created on: Sep 7, 2013
 *      Author: Jenna
 */

#ifndef GOAL_H_
#define GOAL_H_

#include "Entity.h"
#include "Buoy.h"

class Goal : public Entity {
public:
	Goal();
	Goal( Buoy* left, Buoy* right );
	virtual ~Goal();

	virtual void Draw();

	void Highlight();
	bool HasPassed( Entity* ent );
	bool CheckCollision( Entity* ent );

protected:

private:
	Buoy* mLeftBuoy;
	Buoy* mRightBuoy;
};

#endif /* GOAL_H_ */
