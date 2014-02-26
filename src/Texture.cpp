/*
 * Texture.cpp
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#include "Texture.h"

Texture::Texture(string file_path) :
	mId(0),
	mFilePath(file_path),
	mImage(NULL)

{
}

Texture::~Texture()
{
  // Nothing to do here right now.
}

bool Texture::Load()
{
	mImage = IMG_Load(mFilePath.c_str());
	if(!mImage)
	{
		cerr << "ERROR: Texture - " << IMG_GetError() << endl;
		return(false);
	}
	glGenTextures(1, &mId);

	return(true);
}

void Texture::Initialize(bool replace)
{
	// set up texture and texture environment before use
	glBindTexture(GL_TEXTURE_2D, mId);
	if(replace)
	{
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
	else
	{
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mImage->w, mImage->h,
				 0, GL_RGBA, GL_UNSIGNED_BYTE, mImage->pixels);
}

