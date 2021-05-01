QtApplication {
	type: ["application", "autotest"]

	files: [
		"*.cpp",
		"*.h",
	]

	Depends { name: "Qt"; submodules: ["testlib"] }
	Depends { name: "protobuf" }
	Depends { name: "harmony-qt-sdk" }
}
