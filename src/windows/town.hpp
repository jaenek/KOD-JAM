#pragma once

#include <raylib.h>

#include "window.hpp"
#include "../buttons/navigate_buttons.hpp"

class town : window
{
private:
	go_shop_btn go_shop;
	go_mine_btn go_mine;
	go_church_btn go_church;


	Image image = LoadImage("assets/Miasto-Dzien.png");   // Loaded in CPU memory (RAM)
	Texture2D texture = LoadTextureFromImage(image);

public:
	town();

	void update();

	void draw();
};

