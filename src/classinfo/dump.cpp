/*
 * dump.cpp
 *
 *  Created on: May 13, 2017
 *      Author: nullifiedcat
 */

#include "dump.hpp"
#include "../common.h"

static CatCommand do_dump("debug_dump_classes", "Dump classes", PerformClassDump);

void PerformClassDump() {
	ClientClass* cc = g_IBaseClient->GetAllClasses();
	FILE* cd = fopen("/tmp/cathook-classdump.txt", "w");
	if (cd) {
		while (cc) {
			fprintf(cd, "[%d] %s\n", cc->m_ClassID, cc->GetName());
			cc = cc->m_pNext;
		}
		fclose(cd);
	}
}

static CatCommand populate_dynamic("debug_populate_dynamic", "Populate dynamic class table", []() {
	client_classes::dynamic_list.Populate();
});
