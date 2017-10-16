/*
 * HEsp.h
 *
 *  Created on: Oct 6, 2016
 *      Author: nullifiedcat
 */

#ifndef HESP_H_
#define HESP_H_

#include "../common.h"

class ConVar;
class CachedEntity;

#include "../sdk.h" // VECTOR

#include "../beforecheaders.h"
#include <array>
#include <string>
#include "../aftercheaders.h"

namespace hacks { namespace shared { namespace esp {

extern CatVar local_esp;
extern CatVar buildings;
extern CatVar enabled;
extern CatVar entity_info;
extern CatVar show_bot_id;
extern CatVar teammates;
extern CatVar item_esp;
extern CatVar item_dropped_weapons;
extern CatVar item_ammo_packs;
extern CatVar item_health_packs;
extern CatVar item_powerups;
extern CatVar item_money;
extern CatVar item_money_red;
extern CatVar entity_id;
extern CatVar tank;
extern CatVar box_esp;
extern CatVar show_distance;
extern CatVar show_name;
extern CatVar show_class;
extern CatVar show_conditions;
extern CatVar vischeck;
extern CatVar legit;
extern CatVar show_health;
extern CatVar proj_rockets;
extern CatVar proj_arrows;
extern CatVar proj_pipes;
extern CatVar proj_stickies;
extern CatVar proj_enemy;
extern CatVar proj_esp;
extern CatVar entity_model;
extern CatVar item_weapon_spawners;
extern CatVar item_adrenaline;

class ESPString {
public:
	std::string data { "" };
	rgba_t color { colors::empty };
};

class ESPData {
public:
	rgba_t color { colors::empty };
	int string_count { 0 };
	std::array<ESPString, 16> strings {};
	Vector esp_origin { 0, 0, 0 };
	Vector last_origin { 0, 0, 0 };
	bool needs_paint { false };
};

extern std::array<ESPData, 2048> data;
void ResetEntityStrings();
void AddEntityString(CachedEntity* entity, const std::string& string, const rgba_t& color = colors::empty);
void SetEntityColor(CachedEntity* entity, const rgba_t& color);

void CreateMove();
void Draw();

void __attribute__((fastcall)) DrawBox(CachedEntity* ent, const rgba_t& clr, bool healthbar, int health, int healthmax);
void __attribute__((fastcall)) ProcessEntity(CachedEntity* ent);
void __attribute__((fastcall)) ProcessEntityPT(CachedEntity* ent);

}}}

#endif /* HESP_H_ */
