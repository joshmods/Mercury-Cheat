/*
 * removecond.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: nullifiedcat
 */

#include "removecond.hpp"
#include "../../common.h"

namespace ac { namespace removecond {

static CatVar removecond_detect(CV_SWITCH, "ac_removecond", "0", "Detect RemoveCond");
static CatVar removecond_timer(CV_FLOAT, "ac_removecond_timer", "1.1", "RemoveCond timer");

ac_data data_table[32] {};

void ResetEverything() {
	memset(data_table, 0, sizeof(ac_data) * 32);
}

void ResetPlayer(int idx) {
	memset(&data_table[idx - 1], 0, sizeof(ac_data));
}

void Init() {
	ResetEverything();
}

void Update(CachedEntity* player) {
	if (!removecond_detect) return;
	auto& d = data_table[player->m_IDX - 1];
	if (CE_GOOD(player)) {
		float simtime = player->var<float>(netvar.m_flSimulationTime);
		if (player->var<float>(netvar.m_flSimulationTime) != d.stime) {
			if (d.stime && (simtime - d.stime > float(removecond_timer))) {
				d.detections++;
				if (tickcount - d.last_accusation > 60 * 30 || !d.last_accusation) {
					hacks::shared::anticheat::Accuse(player->m_IDX, "Crithack/Removecond", format("Detections: ", d.detections, " dt: ", simtime - d.stime));
					d.last_accusation = tickcount;
				}
			}
		}
		d.stime = simtime;
		if (CE_BYTE(player, netvar.iLifeState)) d.stime = 0.0f;
	} else {
		d.stime = 0.0f;
	}
}

void Event(KeyValues* event) {

}

}}
