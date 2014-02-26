/*
 * Track.h
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#ifndef TRACK_H_
#define TRACK_H_

#include "Entity.h"
#include "Scene.h"

class Track : public Entity {
public:
  	Track();
  	virtual ~Track();

	virtual void Draw();

	virtual Point2D GetMinPoint();
	virtual Point2D GetMaxPoint();

	bool CheckCollision(Entity* ent);

protected:

private:
	SceneNode* mRoot;
	string mFileName;
	GLuint mDisplayList;
};

#endif /* TRACK_H_ */
