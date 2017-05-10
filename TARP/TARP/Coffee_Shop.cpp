#include "Coffee_Shop.h"

const std::string Coffee_Shop::Items[2]{ "", "" };

Coffee_Shop::Coffee_Shop() : Space() {}

int Coffee_Shop::Special(char name[], char drink[], std::string player_name, Player* player) {

	Menu menu;
	// Player player;

	/* Store choice 1 of user */
	int coffee_choice_1;
	menu.coffee_menu(name, drink);
	std::cin >> coffee_choice_1;

	/* Determine next step based on user choice */
	int coffee_choice_2;
	switch (coffee_choice_1) {

	case 1: 
		menu.pick_up_20();
		std::cout << std::endl;
		player->input_item(Items[0]);
		player->display_backpack_content();
		break;
	case 2:
		menu.order_drink(drink);
		std::cin >> coffee_choice_2;
		break;
	default:
		break;
	}

	switch (coffee_choice_2) {

	case 1:
		menu.pick_up_penny();
		player->input_item(Items[1]);
		player->display_backpack_content;
		break;

	case 2:
		menu.take_sip(drink);
		break;

	default:
		break;
	}
	return 0;
}