/*
 * Schema.hpp
 *
 *  Created on: May 20, 2017
 *      Author: nullifiedcat
 */

#ifndef SCHEMA_HPP_
#define SCHEMA_HPP_

#include "../json.hpp"

#include "../../beforecheaders.h"
#include <vector>
#include <memory>
#include <fstream>
#include "../../aftercheaders.h"

class CatVar;

namespace menu { namespace im {

enum ListEntryType {
	DUMMY,
	VARIABLE,
	SUBLIST,
	LABEL
};

struct ListEntry_Dummy {
	const ListEntryType type { DUMMY };
};

struct ListEntry_Variable {
	const ListEntryType type { VARIABLE };
	nlohmann::json data {};
	CatVar& var;

	inline ListEntry_Variable(CatVar& v) : var(v) {}
};

struct ListEntry_List {
	const ListEntryType type { SUBLIST };
	nlohmann::json data {};
	std::string name;
	std::vector<std::auto_ptr<ListEntry_Dummy>> entries {};

	inline ListEntry_List() {};
};

struct ListEntry_Label {
	const ListEntryType type { LABEL };
	std::string text;

	inline ListEntry_Label(const std::string& text) : text(text) {};
};

ListEntry_Dummy* FromJson(nlohmann::json json);
void PopulateList(nlohmann::json json, ListEntry_List* out);

extern std::vector<ListEntry_List*> main_list_array;

}}

#endif /* SCHEMA_HPP_ */
