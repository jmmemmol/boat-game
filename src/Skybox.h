/*
 * Skybox.h
 *
 *  Created on: Sep 8, 2013
 *      Author: Jenna
 */

#ifndef SKYBOX_H_
#define SKYBOX_H_

#include "Texture.h"
#include <vector>

class Skybox {
public:
	Skybox();
	virtual ~Skybox();

	virtual void Draw();

protected:

private:
	vector<Texture> mTextures;
	vector<string> mImageNames;
	int mImageWidth;
	int mImageHeight;
	GLuint mDisplayList;
};

#endif /* SKYBOX_H_ */
