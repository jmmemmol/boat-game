/*
 * Water.h
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#ifndef WATER_H_
#define WATER_H_

#include "Entity.h"
#include "Texture.h"
#include <GLUT/glut.h>

class Water : public Entity {
public:
	Water();
	Water(Texture* tex);
	virtual ~Water();

	virtual void Update(double delta);
	virtual void Draw();

protected:

private:
	GLuint mDisplayList;
	Texture* mTexture;
};

#endif /* WATER_H_ */
