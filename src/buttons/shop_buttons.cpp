#include "shop_buttons.hpp"


void shop_buttons::add_food() {

	if (click_event) {
		if (player->_gold >= food_pirce) {

			player->_food++;
			player->_gold -= food_pirce;			
		}
	}
}

void shop_buttons::add_torch() {

	if (click_event) {
		if (player->_gold >= toarch_price) {

			player->_torches++;
			player->_gold -= toarch_price;			
		}
	}
}

void shop_buttons::upgrade_pickaxe() {

	if (click_event) {
		if (player->_gold >= pickaxe_upgrade_price) {

			player->_pickaxe++;
			player->_gold -= pickaxe_upgrade_price;			
		}
	}
}


