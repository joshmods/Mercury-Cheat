/*
 * InfoPanel.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: nullifiedcat
 */

/*
#include "../../common.h"
#include "../../cvwrapper.h"
#include "imgui.h"
#include "InfoPanel.hpp"

namespace menu { namespace im {

// User settings
CatVar enabled(CV_SWITCH, "info_panel_enabled", "0", "Enable Info Panel");
CatVar aimbot_enabled(CV_SWITCH, "info_panel_aimbot", "0", "Show Aimbot");
CatVar aimkey_enabled(CV_SWITCH, "info_panel_aimkey_toggle", "0", "Show Aimkey Toggle");
	
// Main ImGui menu creator
void RenderInfoPanel() {
	
	// Check if info menu is enabled
	if (!enabled) return;
	
	// Check if in-game
	if (!g_IEngine->IsInGame()) return;
	
	// Menu creation stuff pasted from playerlist
	if (ImGui::Begin("Info Panel")) {
		ImGui::SetWindowSize(ImVec2(0, 0));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 1));
		
		// The main meat of the info panel
		if (aimbot_enabled) AddInfoItem(EInfo::AIMBOT, 169); 
		if (aimkey_enabled) AddInfoItem(EInfo::AIMKEY, 269); 
		

		ImGui::PopStyleVar();
	}
	ImGui::End();
}

// Function to add individual items to menu
void AddInfoItem(EInfo info_type, int id) {
	
	// Dont know what this does but i just use some numbers with 69 to make it somewhat different
	ImGui::PushID(id);
	
	// Switch based on into_type
	switch (info_type) {
	case EInfo::AIMBOT:
		ImGui::Text(format("Aimbot: ", GetCatVar("aimbot_enabled") ? "enabled" : "disabled").c_str());
		break;
	case EInfo::AIMKEY:
		ImGui::Text(format("Todo, get toggle mode from aimkey").c_str());	
		break;
	};
	
	// Dont know what this does but im expecting i would need it
	ImGui::PopID();
}

// Helper function ripped from schema.cpp due to ussues if i tri to use it directly from there
CatVar* GetCatVar(const std::string name) {
	for (auto var : CatVarList()) {
		if (var->name == name) return var;
	}
	return nullptr;
}
	
}}*/