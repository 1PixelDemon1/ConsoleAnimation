#pragma once

#include <vector>
#include <iostream>
#include <windows.h>

#include "Point.h"
#include "Screen.h"

class Animation
{
private:

	std::vector<Point::Point> points;
	const HANDLE hcon{};
	char sym;
	int32_t moves;

	void SetPos(Point::Point point) const;

public:
	Animation(Point::Point startPoint, char sym_, int32_t moves_) : hcon{ GetStdHandle(STD_OUTPUT_HANDLE) }, sym{ sym_ }, moves{ moves_ } {
		points.push_back(startPoint);
	}

	Animation(Point::Point startPoint, char sym_ = '#') : Animation(startPoint, sym, 15) {}
	
	Animation(int32_t x, int32_t y, char sym_ = '#', int32_t moves_ = 15) : Animation({x, y, Point::START, 0}, sym_, moves_) {}

	Animation() : Animation({ 0, 0, Point::START, 0 }, '#', 15) {}

	~Animation() {
		points.clear();
	}
	
	void init(Point::Point startPoint, char sym_ = '#', int32_t moves_ = 15);

	void init(int32_t x, int32_t y, char sym_ = '#', int32_t moves_ = 15);
	
	void print() const;
	
	void print(Screen& screen) const;

	void print(std::ostream& out) const;

	void move();

	friend std::ostream& operator<<(std::ostream& out, const Animation& animation);



};

