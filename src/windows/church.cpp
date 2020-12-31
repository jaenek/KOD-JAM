#include "church.hpp"

church::church():
	leave_church((window_width - 200) / 2, 550, 200, 100, "Back to town", 20, GRAY, WHITE, BROWN, WHITE, DARKBROWN, WHITE, 0, 0)
{	}

void church::update()
{
	leave_church.update();
	
}

void church::draw()
{
	//background
	DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);

	//buttons
	leave_church.draw();
	

	//text
	const char* text = "CHURCH";
	DrawText(text, (window_width - MeasureText(text, 40)) / 2, 50, 30, DARKBROWN);


}
