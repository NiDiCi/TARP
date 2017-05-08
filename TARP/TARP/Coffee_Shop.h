#ifndef Coffee_Shop_h
#define Coffee_Shop_h

#include <stdio.h>
#include <iostream>
#include "Space.h"

class Coffee_Shop : public Space {

public:
	Coffee_Shop();
	int Special(char name[], char drink[], std::string player_name, Player* player);

private:
	static const std::string Items[2]; // = {"$20 bill", "Penny"};
};
#endif // !Coffee_Shop_h