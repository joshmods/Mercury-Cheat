/*
 * CritIndicator.cpp
 *
 *  Created on: May 13, 2017
 *      Author: nullifiedcat
 */

/*#include "CritIndicator.hpp"
#include "../../common.h"

namespace menu { namespace ncc {

CatVar ci_enabled(CV_SWITCH, "gui_ncc_crit_indicator", "1", "Crit Indicator");
CatVar ci_x(CV_INT, "gui_ncc_crit_indicator_x", "400", "Crit Indicator X");
CatVar ci_y(CV_INT, "gui_ncc_crit_indicator_y", "150", "Crit Indicator Y");

CritIndicator::CritIndicator() : CBaseWidget("ncc_crit_indicator"),
	crit_normal(&_binary_crit_1_start, 64, 64),
	crit_none(&_binary_crit_2_start, 64, 64),
	crit_ready(&_binary_crit_3_start, 64, 64),
	crit_disabled(&_binary_crit_4_start, 64, 64) {
	SetOffset((int)ci_x, (int)ci_y);
	SetSize(64, 72);
}

bool CritIndicator::IsVisible() {
	return !g_Settings.bInvalid && ci_enabled && hacks::shared::misc::crit_hack_next;
}

void CritIndicator::Draw(int x, int y) {
	if (!crit_none.id) crit_none.Load();
	if (!crit_disabled.id) crit_disabled.Load();
	if (!crit_normal.id) crit_normal.Load();
	if (!crit_ready.id) crit_ready.Load();
	Texture* tx = &crit_none;
	bool critkey { false };
	bool crits { false };
	if (RandomCrits() && weapon_can_crit_last) {
		// It's safe to be 1 tick behind real values to prevent flickering.
		if (hacks::shared::misc::found_crit_number >= hacks::shared::misc::last_number - 1 && hacks::shared::misc::found_crit_weapon == RAW_ENT(LOCAL_W)) {
			tx = &crit_normal;
			if (CritKeyDown() || experimental_crit_hack.KeyDown()) {
				tx = &crit_ready;
				critkey = true;
			}
			crits = true;
		}
	} else {
		tx = &crit_disabled;
	}
	draw::DrawRect(x, y, 64, 72, colors::Transparent(colors::black));
	tx->Draw(x, y, 64, 64);
	draw::OutlineRect(x, y, 64, 72, critkey ? colors::pink : GUIColor());
	draw::DrawLine(x, y + 64, 64, 0, critkey ? colors::pink : GUIColor());
	if (crits) {
		draw::DrawRect(x + 1, y + 65,  1 + 61.0f * (hacks::shared::misc::last_bucket / 1000.0f), 6, (!crits) ? colors::Create(235, 20, 20, 255) : colors::Create(20, 235, 20, 255));
	}
}

bool CritIndicator::AlwaysVisible() {
	return IsVisible();
}

void CritIndicator::Update() {
	if (IsPressed()) {
		auto offset = GetOffset();
		offset.first += g_pGUI->mouse_dx;
		offset.second += g_pGUI->mouse_dy;
		SetOffset(offset.first, offset.second);
		ci_x = (int)offset.first;
		ci_y = (int)offset.second;
	}
}

}}*/

