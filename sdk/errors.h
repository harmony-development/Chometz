#pragma once

namespace Chometz
{

enum Errors
{

	// The database failed, preventing Chometz from functioning
	// as expected
	DatabaseInitFailure,

	// The database failed to perform a query, preventing Chometz
	// from functioning as expected
	DatabaseQueryFailure,

};

};
