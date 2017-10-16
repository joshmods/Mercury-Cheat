/*
 * GUI.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: xConModz
 */

#include "GUI.h"

#include "../common.h"
#include "../sdk.h"

void GUIVisibleCallback(IConVar* var, const char* pOldValue, float flOldValue) {
	g_IInputSystem->SetCursorPosition(draw::width / 2, draw::height / 2);
	g_ISurface->SetCursor(vgui::CursorCode::dc_none);
	if (gui_visible) {
		g_ISurface->UnlockCursor();
		g_ISurface->SetCursorAlwaysVisible(true);
	} else {
		g_ISurface->LockCursor();
		g_ISurface->SetCursorAlwaysVisible(false);
	}
}

CatVar gui_visible(CV_SWITCH, "gui_visible", "0", "GUI Active", "GUI switch (bind it to a key!)");

CatGUI::CatGUI() {}

CatGUI::~CatGUI() {}

bool CatGUI::Visible() {
	return gui_visible;
}

CatVar gui_color_r(CV_INT, "gui_color_r", "255", "Main GUI color (red)", "Defines red component of main gui color", 0, 255);
CatVar gui_color_g(CV_INT, "gui_color_g", "105", "Main GUI color (green)", "Defines green component of main gui color", 0, 255);
CatVar gui_color_b(CV_INT, "gui_color_b", "180", "Main GUI color (blue)", "Defines blue component of main gui color", 0, 255);

CatVar gui_debug(CV_SWITCH, "gui_debug", "0", "Debug GUI");

static CatVar gui_rainbow(CV_SWITCH, "gui_rainbow", "0", "Rainbow GUI", "RGB all the things!!!");
rgba_t GUIColor() {
	return gui_rainbow ? colors::RainbowCurrent() : colors::FromRGBA8(int(gui_color_r), int(gui_color_g), int(gui_color_b), 255);
}

void CatGUI::Setup() {
	gui_visible.OnRegister([](CatVar* var) {
		var->convar->InstallChangeCallback(GUIVisibleCallback);
	});
}

void CatGUI::Update() {
	int nx = g_IInputSystem->GetAnalogValue(AnalogCode_t::MOUSE_X);
	int ny = g_IInputSystem->GetAnalogValue(AnalogCode_t::MOUSE_Y);

	mouse_dx = nx - m_iMouseX;
	mouse_dy = ny - m_iMouseY;

	m_iMouseX = nx;
	m_iMouseY = ny;

	try {
		int new_scroll = g_IInputSystem->GetAnalogValue(AnalogCode_t::MOUSE_WHEEL);
		if (last_scroll_value < new_scroll) {
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_DOWN] = false;
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_UP] = true;
		} else if (last_scroll_value > new_scroll) {
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_DOWN] = true;
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_UP] = false;
		} else {
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_DOWN] = false;
			m_bPressedState[ButtonCode_t::MOUSE_WHEEL_UP] = false;
		}

		last_scroll_value = new_scroll;
		for (int i = 0; i < ButtonCode_t::BUTTON_CODE_COUNT; i++) {
			bool down = false, changed = false;
			if (i != ButtonCode_t::MOUSE_WHEEL_DOWN && i != ButtonCode_t::MOUSE_WHEEL_UP) {
				down = g_IInputSystem->IsButtonDown(ButtonCode_t(i));
				changed = m_bPressedState[i] != down;
			} else {
				down = m_bPressedState[i];
				changed = down;
			}
			if (changed && down) m_iPressedFrame[i] = g_GlobalVars->framecount;
			m_bPressedState[i] = down;
			if (m_bKeysInit) {
				if (changed) {
					if (gui_debug) {
						logging::Info("Key %d changed, now %d", i, down);
					}
					if (i == ButtonCode_t::MOUSE_LEFT) {
						if (Visible()) {
							// Mouse is pressed.
						}
					} else if (down) {
						if ((i == ButtonCode_t::KEY_INSERT || i == ButtonCode_t::KEY_F11)) {
							if (gui_debug) {
								logging::Info("GUI key pressed");
							}
							gui_visible = !gui_visible;
						}
					}
				}
			}
		}

		if (!m_bKeysInit) m_bKeysInit = 1;
	} catch (std::exception& ex) {
		logging::Info("ERROR: %s", ex.what());
	}

}

bool CatGUI::ConsumesKey(ButtonCode_t key) {
	static const std::vector<ButtonCode_t> keys_noconsume({KEY_ESCAPE, KEY_BACKQUOTE});
	for (const auto& i : keys_noconsume) {
		if (i == key) return false;
	}
	return Visible();
}

CatGUI* g_pGUI = 0;
