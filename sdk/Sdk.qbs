import qbs.FileInfo

StaticLibrary {
	name: "harmony-qt-sdk"

	files: [
		"*.cpp",
	]

	install: true
	installDir: "lib64"

	cpp.cppFlags: ['-Werror=return-type']
	cpp.cxxLanguageVersion: "c++20"

	Depends { name: "cpp" }
	Depends { name: "vendored_protobuf" }
	Depends { name: "croutons" }
	Depends { name: "HarmonyProtocol" }
	Depends { name: "Qt"; submodules: ["network", "concurrent", "websockets"] }

	Export {
		Depends { name: "cpp" }
		Depends { name: "vendored_protobuf" }
		Depends { name: "croutons" }
		Depends { name: "HarmonyProtocol" }
		Depends { name: "Qt"; submodules: ["network", "concurrent", "websockets"] }

		cpp.cxxLanguageVersion: "c++20"
		cpp.includePaths: [exportingProduct.sourceDirectory, exportingProduct.sourceDirectory + "/gen"]
		prefixMapping: [{
			prefix: exportingProduct.sourceDirectory,
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
		qbs.install: product.install
		qbs.installDir: "include/chometz"
	}
}
