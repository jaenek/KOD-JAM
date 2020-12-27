#include <raylib.h>

class grid_cell : Rectangle {
public:
	grid_cell(float x, float y, float width, float height, Color color)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->color = color;
	}

	virtual void draw()
	{
		DrawRectangleRec(*this, color);
	}

private:
	Color color;
};