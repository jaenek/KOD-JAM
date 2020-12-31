#include "church.hpp"

const char* messages[4] = {
	"You wake up in a familiar looking church.\n"
	"You've seen it before, in your dreams.\n"
	"Suddenly, a voice echoes through the building.\n",

	"\t\"Welcome my child, you are finally awake\"\n",

	"You look around, wondering where is the voice coming from.\n"
	"Before you can respond, the voice says:\n",

	"\"Fear not my child because thy is my prophet,\n"
	"choosen to save the world from the darkness\n"
	"that surrounds this town, it is your duty to save it.\n"
	"In order to do that thy shall have to get to the deepest level\n"
	"of the minesand and recover the ancient artifact.\n"
	"I can repel the darkness as long as you can provide me with gold,\n"
	"which is the source of my power because that's how religion works.\n"
	"Now go into the mines, find your way to the lower levels\n"
	"and SAVE YOUR WORLD.\"\n"
};

church::church(dwarf& player) :
	leave_church(430, 585, 200, 75, "Back to town", 20, GRAY, WHITE, BROWN, WHITE, DARKBROWN, WHITE, 0, 0),
	pay_and_pray(775, 685, 200, 75, "Pay and pray", 20, GRAY, WHITE, BROWN, WHITE, DARKBROWN, WHITE, &player, 0, 0),
	player(player)
{}

void church::update()
{

	leave_church.update();
	pay_and_pray.update();

	pay_and_pray.pray();
	
}

void church::draw()
{
	if (leave_church.first_visit)
	{
		frame_counter++;

		DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);
		//DrawText(TextSubtext(message, 0, frame_counter / 10), 210, 160, 20, MAROON);
		if (frame_counter < 480)
			DrawText(TextSubtext(messages[0], 0, frame_counter / 3), 110, 160, 30, BLACK);
		else if (frame_counter < 660)
			DrawText(TextSubtext(messages[1], 0, (frame_counter - 480) / 3), 110, 160, 30, BLACK);
		else if (frame_counter < 1080)
			DrawText(TextSubtext(messages[2], 0, (frame_counter - 660) / 3), 110, 160, 30, BLACK);
		else
			DrawText(TextSubtext(messages[3], 0, (frame_counter - 1080) / 3), 110, 160, 30, BLACK);
	}
	else
	{
		//background
		DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);

		//buttons
		leave_church.draw();
		pay_and_pray.draw();
	}

	//text
	const char* text = "CHURCH";
	DrawText(text, (window_width - MeasureText(text, 40)) / 2, 50, 30, DARKBROWN);
}
