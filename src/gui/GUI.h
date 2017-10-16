/*
 * GUI.h
 *
 *  Created on: Jan 25, 2017
 *      Author: nullifiedcat
 */

#ifndef GUI_H_
#define GUI_H_

class IWidget;
class CatVar;

#include "../common.h"

extern CatVar gui_color_r;
extern CatVar gui_color_g;
extern CatVar gui_color_b;
extern CatVar gui_debug;
rgba_t GUIColor();

extern CatVar gui_visible;

class CatGUI {
public:
	CatGUI();
	~CatGUI();

	bool Visible();
	void Update();
	void Setup();
	bool ConsumesKey(ButtonCode_t key);

	int  last_scroll_value;
	bool m_bShowTooltip;
	bool m_bConsumeKeys;
	bool m_bKeysInit;
	bool m_bPressedState[ButtonCode_t::BUTTON_CODE_COUNT];
	int  m_iPressedFrame[ButtonCode_t::BUTTON_CODE_COUNT];
	int  m_iMouseX;
	int  m_iMouseY;
	int  mouse_dx;
	int  mouse_dy;
};

extern CatGUI* g_pGUI;

#endif /* GUI_H_ */
