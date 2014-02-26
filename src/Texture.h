/*
 * Texture.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>
#include <GLUT/glut.h>
#include <SDL2_image/SDL_image.h>

using namespace std;

class Texture {
public:
	Texture(string file_path);
	virtual ~Texture();

	bool Load();
	void Initialize(bool replace = true);

protected:

private:
	GLuint mId;

	string mFilePath;
	SDL_Surface* mImage;
};

#endif /* TEXTURE_H_ */
