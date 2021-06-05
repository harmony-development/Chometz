Project {
	references: [
		"sdk/Sdk.qbs",
		//"test/Test.qbs",
		"vendor/protobuf.qbs",
	]

	AutotestRunner { name: "chometz-tests" }
}
