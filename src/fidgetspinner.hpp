/*
 * fidgetspinner.hpp
 *
 *  Created on: Jul 4, 2017
 *      Author: nullifiedcat
 */

#pragma once

#include "common.h"
#include "atlas.hpp"

class CatVar;

extern CatVar enable_spinner;
extern std::vector<textures::AtlasTexture> spinner_states;

void InitSpinner();
void DrawSpinner();
