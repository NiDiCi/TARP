#ifndef Blank_h
#define Blank_h

#include <stdio.h>
#include "Space.h"

class Blank : public Space {

public:
	Blank();
	int Special(char name[], char drink[], std::string player_name, Player *player);

private:
	static const std::string Items[5]; // = {"Raptor Talon", "Red Apple", "One Ring", "Glass Shoe", "White Sphere of Light"};
	static const std::string Characters[4]; // = {"Ian Malcolm", "Snow White", "Aragorn", "Cinderella"};
};
#endif // !Blank_h