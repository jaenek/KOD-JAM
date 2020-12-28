#include "equipment.hpp"

equipment::equipment()
{
	_gold = 0;
	_torches = 20;
	_pickaxe = 50;
	_food = 10;
	_hp = 10;
}

bool equipment::place_torch()
{
	if (!_torches)
		return false;//triggeruje jakiú düwiÍk typu z≥a odpowiedü w familiadzie

	_torches--;

	for (int x = posX - 2; x <= posX + 2; x++)
	{
		for (int y = posY - 2; y <= posY + 2; y++)
		{
			if ()
		}
	}
}

bool use_pickaxe()
{

}