const fs = require("fs");

var full_class_table = {};
try {
	full_class_table = JSON.parse(fs.readFileSync("full-class-table.json").toString());
} catch (e) {}

const file = fs.readFileSync(process.argv[2]).toString().split("\n");
const modname = process.argv[3];

console.log("Generating info for", modname, "from", process.argv[2]);

var classes = {};
for (var i in file) {
	var class_info = /\[(\d+)\] (\w+)/gi.exec(file[i]);	
	if (class_info) {
		full_class_table[class_info[2]] = true;
		classes[class_info[2]] = parseInt(class_info[1]);
	}
}

fs.writeFileSync("full-class-table.json", JSON.stringify(full_class_table));

var header_constexpr = `/*
	AUTO-GENERATED HEADER - DO NOT MODIFY
	CONSTEXPR HEADER FOR $mod
*/

#ifndef $mod_CONSTEXPR_AUTOGEN_HPP
#define $mod_CONSTEXPR_AUTOGEN_HPP

namespace client_classes_constexpr {
	
	class $mod {
	public:
`;

var header = `/*
	AUTO-GENERATED HEADER - DO NOT MODIFY
	NON-CONSTEXPR HEADER FOR $mod
*/

#ifndef $mod_AUTOGEN_HPP
#define $mod_AUTOGEN_HPP

namespace client_classes {
	
	class $mod {
	public:
`;

for (var clz in full_class_table) {
	var value = "0";
	if (classes[clz]) value = classes[clz];
	header_constexpr += "\t\tstatic constexpr int " + clz + " = " + value + ";\n";
	header += "\t\tint " + clz + " { " + value + " };\n";
}

header += `
	};
	
	extern $mod $mod_list;
}

#endif /* $mod_AUTOGEN_HPP */`;

header_constexpr += `
	};
}

#endif /* $mod_CONSTEXPR_AUTOGEN_HPP */`;

fs.writeFileSync("src/classinfo/" + modname + ".gen.hpp", header.replace(/\$mod/g, modname));
fs.writeFileSync("src/classinfo/" + modname + "_constexpr.gen.hpp", header_constexpr.replace(/\$mod/g, modname));


console.log(classes);
