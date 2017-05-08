#ifndef Menu_h
#define Menu_h

#include "Space.h"

//Headers used in _h but also _cpp
#include <stdio.h>
#include <string>

//Headers used in 
#include <iostream>
#include <cstdlib>
#include <iomanip>

class Menu {

	friend class Space;
public:
	int game_menu();

	void coffee_menu(char name[], char drink[]);
	void order_drink(char drink[]);
	void pick_up_20();
	void pick_up_penny();
	void take_sip(char drink[]);

	void center_menu(std::string player_name);
	void Oracle_riddle_star();
	void Oracle_riddle_harry();
	void Oracle_riddle_seuss();
	void Oracle_riddle_blank();
	void Oracle_give_sphere();
	void Oracle_end_menu(std::string player_name);

	void Star_Wars_menu();
	void Star_Wars_actions_menu();
	void Star_Wars_disp_actions(int user_choice);
	void R2D2_menu(std::string R2D2);
	void Yoda_menu(std::string Yoda);
	void Sith_menu(std::string Sith);

	void Harry_Potter_menu();
	void Harry_Potter_actions_menu();
	void Portraits_menu();
	void Hermione_menu();
	void Book_menu();
	void Box_menu();

	void Dr_Seuss_menu();
	void Dr_Seuss_actions_menu();
	void Humming_Fish_menu();
	void Once_ler_menu();

	void Blank_menu();
	void Jurassic_menu();
	void Snow_White_menu();
	void LOTR_menu();
	void Cinderella_menu();

	void Sphere_of_Light_menu();

	//friend int Special_2(char name[], char drink[], std::string player_name, Player* player);
	// friend int Special_3(char name[], char drink[], std::string player_name, Player* player);
	//friend int Special_4(char name[], char drink[], std::string player_name, Player* player);

};

#endif // !Menu_h