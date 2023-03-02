#include "Animation.h"

void Animation::init(Point::Point startPoint, char sym_, int32_t moves_) {	
	points.clear();
	points.push_back(startPoint);
	sym = sym_;
	moves = moves_;
}
void Animation::init(int32_t x, int32_t y, char sym_, int32_t moves_) {	
	points.clear();
	points.push_back({x, y, Point::START, 0});
	sym = sym_;
	moves = moves_;
}

void Animation::SetPos(Point::Point point) const {
	SetConsoleCursorPosition(hcon, { (short)point.x, (short)point.y });
}



void Animation::print(std::ostream& out) const {
	for (auto point : points) {
		SetPos(point);
		out << sym;
	}

}

void Animation::print() const {
	Animation::print(std::cout);
}

void Animation::print(Screen& screen) const {
	for (auto point : points) {
		screen.writeToPos(point, sym);		
	}
	screen.print();
}

void Animation::move() {
	int32_t size = points.size();

	for (size_t i = 0; i < size; i++)
	{
		Point::Point point = points[i];
		if (point.moves > moves) break;
		switch (point.direction)
		{
		case Point::LEFT:
			points.push_back({ point.x - 1, point.y, Point::LEFT, point.moves + 1 });
			points.push_back({ point.x , point.y + 1, Point::DOWN, point.moves + 1 });
			points.push_back({ point.x , point.y - 1, Point::UP, point.moves + 1 });
			break;
		case Point::RIGHT:
			points.push_back({ point.x + 1, point.y, Point::RIGHT, point.moves + 1 });
			points.push_back({ point.x , point.y + 1, Point::DOWN, point.moves + 1 });
			points.push_back({ point.x , point.y - 1, Point::UP, point.moves + 1 });
			break;
		case Point::UP:		
			points.push_back({ point.x , point.y - 1, Point::UP, point.moves + 1 });
			break;
		case Point::DOWN:
			points.push_back({ point.x , point.y + 1, Point::DOWN, point.moves + 1 });
			break;
		case Point::START:
			points.push_back({ point.x + 1, point.y, Point::RIGHT, point.moves + 1 });
			points.push_back({ point.x - 1, point.y, Point::LEFT, point.moves + 1 });
			break;

		default:
			break;
		}		
	}
	points.erase(points.begin(), points.begin() + size);

}

std::ostream& operator<< (std::ostream& out, const Animation& animation) {	
	animation.print(out);
	return out;	
}

