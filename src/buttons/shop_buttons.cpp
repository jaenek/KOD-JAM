#include "shop_buttons.hpp"


void shop_buttons::add_food() {

	if (click_event) {
		if (player->_gold >= food_pirce) {

			player->_food++;
			player->_gold -= food_pirce;

			std::cout << "food_ilosc: " << player->_food << std::endl;
			std::cout << "zloto: " << player->_gold << std::endl;
		}
	}
}

void shop_buttons::add_torch() {

	if (click_event) {
		if (player->_gold >= toarch_price) {

			player->_torches++;
			player->_gold -= toarch_price;

			std::cout << "torches_ilosc: " << player->_torches << std::endl;
			std::cout << "zloto: " << player->_gold << std::endl;
		}
	}
}

void shop_buttons::upgrade_pickaxe() {

	if (click_event) {
		if (player->_gold >= pickaxe_upgrade_price) {

			player->_pickaxe++;
			player->_gold -= pickaxe_upgrade_price;

			std::cout << "kilof_ilosc: " << player->_pickaxe << std::endl;
			std::cout << "zloto: " << player->_gold << std::endl;
		}
	}
}


