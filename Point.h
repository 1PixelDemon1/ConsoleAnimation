#pragma once
#include <cstdint>

namespace Point {

	enum Direction {LEFT, UP, RIGHT, DOWN, START = -1};

	struct Point {
		int32_t x;
		int32_t y;
		Direction direction;
		int32_t moves;
	};

}