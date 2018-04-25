#pragma once
#ifndef CONSTANTSH
#define CONSTANTSH

namespace Constants {


	const int WIN_WIDTH = 900;
	const int WIN_HALF_WIDTH = WIN_WIDTH / 2;
	const int WIN_HEIGHT = 800;
	const int WIN_HALF_HEIGHT = WIN_HEIGHT / 2;

	const float SHOT_CLOCK_TIMER = 1.3;
	const int INVADER_COUNT_PER_ROW = 8;
	const int INVADER_COUNT_ROWS = 5;
	const int INVADER_COUNT = INVADER_COUNT_PER_ROW * INVADER_COUNT_ROWS;

	const int INVADER_WIDTH = 50;
	const int INVADER_HEIGHT = 36;
}

#endif