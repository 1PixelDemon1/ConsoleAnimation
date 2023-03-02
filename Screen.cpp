#include "Screen.h"

int32_t Screen::getPoint(Point::Point point) {
	int32_t position = point.y * width + point.x;
	if (position < 0 || position >= width * height) return -1;
	return position;
}

void Screen::print() {
	WriteConsoleOutputCharacter(hcon, screen, width * height, { 0,0 }, &dwBytesWritten);	
}

	
void Screen::writeToPos(Point::Point point, wchar_t sym) {	
	int32_t res{ Screen::getPoint(point) };
	if (!~res) return;
	screen[res] = sym;
}

void Screen::clear() {
	std::fill_n(screen, height * width, L' ');
}

void Screen::reload(int32_t screenW, int32_t screenH, bool clear_)
{
	delete[] screen;
	width = screenW;
	height = screenH;
	screen = new wchar_t[width * height];
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	if (clear_) clear();
}
