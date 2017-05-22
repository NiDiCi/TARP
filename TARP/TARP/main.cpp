#include "Menu.h"
#include "Player.h"
#include "Map.h"
#include "Space.h"
#include "Center.h"
#include "Coffee_Shop.h"
#include "Star_Wars.h"
#include "Harry_Potter.h"
#include "Dr_Seuss.h"
#include "Blank.h"

#include <fstream>
#include <sstream>
#include <string>

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <time.h>

int main() {
	Menu menu;
	int menu_choice;
	do {

		menu_choice = menu.game_menu();

		if (menu_choice == 1) {
			/* Timer setup */
			clock_t end;
			end = clock() + 900;
			clock();

			/* Game setup */
			do {

			} while (clock() <= end);

		}
		else if (menu_choice == 2) {

			std::cout << "Program Ended!" << std::endl;
		}
		else {

			std::cout << "Please select the number corresponding to the action you wish to complete." << std::endl;
		}

	} while (menu_choice != 2);

	return 0;
}