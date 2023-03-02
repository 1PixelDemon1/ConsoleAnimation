#pragma once
#include <windows.h>
#include <algorithm>
#include <iostream>
#include "Point.h"


class Screen {

	int32_t width;			
	int32_t height;			
	wchar_t* screen;
	HANDLE hcon;
	DWORD dwBytesWritten;

	public:

	Screen(int32_t screenW, int32_t screenH) :width{ screenW }, height{ screenH }, hcon{ 
		GetStdHandle(STD_OUTPUT_HANDLE) } {
		screen = new wchar_t[width * height];
		clear();
	}

	~Screen() {
		delete[] screen;
	}

	void writeToPos(Point::Point point, wchar_t sym = L'#');
	int32_t getPoint(Point::Point point);
	void clear();
	void print();

	void reload(int32_t screenW, int32_t screenH, bool clear_ = false);
};