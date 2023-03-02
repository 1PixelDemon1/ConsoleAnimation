#include <iostream>
#include <vector>
#include "Animation.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;

void getSize(int32_t& width, int32_t& height) {
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);	
	width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}


int main()
{
	POINT p;

	std::vector<Animation> animations{};
	int32_t sizex;
	int32_t sizey;

	getSize(sizex, sizey);

	Screen screen(sizex, sizey);


	while (true) {
		for (auto& point : animations)
		{
			point.move();
			point.print(screen);
		}
		if (GetKeyState(VK_SPACE) & 0x8000) {
			getSize(sizex, sizey);
			screen.reload(sizex, sizey, true);
		}
		if (GetKeyState(VK_RBUTTON) < 0) {
			GetCursorPos(&p);			
			animations.push_back(Animation{p.x / 8, p.y / 16, '*', 12});
			Sleep(10);
		}

		screen.clear();
		
		Sleep(10);
		system("cls");
	}

}