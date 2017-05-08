

#ifndef Space_h
#define Space_h

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Player.h"
#include "Menu.h"

class Space {

	friend class Map;
	friend class Player;

public:
	Space();

	//Pure virtual function
	virtual int Special(char name[], char drink[], std::string player_name, Player *player) = 0;
};

#endif // !Space_h