#include "windows/main_window.hpp"

Vector2 mouse_position = { 100.f, 100.f };
window_type draw_window = window_type::CHURCH;

int main() {
	main_window game;
	game.loop();
	return 0;
}
