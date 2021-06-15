import qbs.FileInfo

StaticLibrary {
	name: "harmony-qt-sdk"

	files: [
		"*.cpp",
		// "*.h",
		"gen/*/*/*.cpp",
		"gen/*/*/*.cc",
		// "gen/*/*/*.h",
	]

	cpp.includePaths: ["gen"]
	cpp.cppFlags: ['-Werror=return-type']
	cpp.cxxLanguageVersion: "c++20"

	Depends { name: "cpp" }
	Depends { name: "vendored_protobuf" }
	Depends { name: "croutons" }
	Depends { name: "Qt"; submodules: ["network", "concurrent", "websockets"] }

	Export {
		Depends { name: "cpp" }
		Depends { name: "vendored_protobuf" }
		Depends { name: "croutons" }
		Depends { name: "Qt"; submodules: ["network", "concurrent", "websockets"] }

		cpp.cxxLanguageVersion: "c++20"
		cpp.includePaths: [product.sourceDirectory, product.sourceDirectory + "/gen"]
		prefixMapping: [{
			prefix: product.sourceDirectory,
			replacement: FileInfo.joinPaths(qbs.installPrefix, "include")
		}]
	}

	Depends { name: "Exporter.qbs" }
	Depends { name: "Exporter.pkgconfig" }
	Exporter.pkgconfig.versionEntry: "0.1"

	Group {
		name: "API Headers"
		files: ["*.h"]
		excludeFiles: ["*_p.h"]
		qbs.install: true
		qbs.installDir: "include/chometz"
	}
	Group { name: "Generated API Headers"; files: ["gen/auth/v1/*.h"]; qbs.install: true; qbs.installDir: "include/chometz/auth/v1" }
	Group { name: "Generated API Headers"; files: ["gen/chat/v1/*.h"]; qbs.install: true; qbs.installDir: "include/chometz/chat/v1" }
	Group { name: "Generated API Headers"; files: ["gen/harmonytypes/v1/*.h"]; qbs.install: true; qbs.installDir: "include/chometz/harmonytypes/v1" }
	Group { name: "Generated API Headers"; files: ["gen/mediaproxy/v1/*.h"]; qbs.install: true; qbs.installDir: "include/chometz/mediaproxy/v1" }
	Group { name: "Generated API Headers"; files: ["gen/voice/v1/*.h"]; qbs.install: true; qbs.installDir: "include/chometz/voice/v1" }
}
