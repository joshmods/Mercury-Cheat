/*
 * removecond.hpp
 *
 *  Created on: Jun 5, 2017
 *      Author: nullifiedcat
 */

#pragma once

class KeyValues;
class CachedEntity;

namespace ac { namespace removecond {

struct ac_data {
	float stime;
	int detections;
	unsigned long last_accusation;
};

void ResetEverything();
void ResetPlayer(int idx);

void Init();
void Update(CachedEntity* player);
void Event(KeyValues* event);

}}

