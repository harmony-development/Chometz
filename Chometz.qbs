Project {
	references: [
		"sdk/Sdk.qbs",
		"protocol/Protocol.qbs",
		"test/Test.qbs",
		"vendor/protobuf.qbs",
		"vendor/croutons/croutons.qbs",
	]

	AutotestRunner { name: "chometz-tests" }
}
