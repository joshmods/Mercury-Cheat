const fs = require("fs");

var full_class_table = {};
try {
	full_class_table = JSON.parse(fs.readFileSync("full-class-table.json").toString());
} catch (e) {}

console.log("Generating dummy class header");

var header = `/*
	AUTO-GENERATED HEADER - DO NOT MODIFY
	NON-CONSTEXPR HEADER FOR $mod
*/

#ifndef DUMMY_AUTOGEN_HPP
#define DUMMY_AUTOGEN_HPP

namespace client_classes {
	
	class dummy {
	public:
`;

for (var clz in full_class_table) {
	header += "\t\tint " + clz + " { 0 };\n";
}

header += `
	};
	
	extern dummy dummy_list;
}

#endif /* DUMMY_AUTOGEN_HPP */`;

fs.writeFileSync("src/classinfo/dummy.gen.hpp", header);
