#ifndef Star_Wars_h
#define Star_Wars_h

//Headers used in _h but also _cpp
#include <stdio.h>

#include "Space.h"

class Star_Wars : public Space {

public:
	Star_Wars();
	int Special(char name[], char drink[], std::string player_name, Player *player);

private:
	static const std::string Items[3]; // = { "Lightsaber", "Yoda's Code", "Blue Sphere of Light"};
	static const std::string Character[3]; // = {"R2D2", "Yoda", "Sith"};
};


#endif // !Star_Wars_h