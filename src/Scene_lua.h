/*
 * Scenelua.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef SCENE_LUA_H_
#define SCENE_LUA_H_

#include <string>
#include "Scene.h"

SceneNode* import_lua(const std::string& filename);

#endif /* SCENE_LUA_H_ */
