#ifndef Player_h
#define Player_h

//Headers used in _h but also _cpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Space;
class Player {

public:
	Player();

	// Player name
	void set_player_name(std::string name);
	std::string display_player_name();

	// Player space / were player are
	void set_player_space(Space *space_name);
	Space *display_player_space();

	// Items
	void input_item(std::string item);
	std::string get_item(int item_num);
	int remove_item(std::string item);
	bool check_item_available(std::string item);

	// Backpack
	void display_backpack_content();
	int check_backpack_size();

private:
	std::string player_name;
	Space* player_in_space;
	std::string player_drink;
	std::vector<std::string> backpack;

};

#endif // !Player_h