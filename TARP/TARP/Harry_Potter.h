#ifndef Harry_potter_h
#define Harry_potter_h

#include <stdio.h>
#include "Space.h"

class Harry : public Space
{
public:
	Harry();
	int Special(char name[], char drink[], std::string player_name, Player* player);

private:
	static const std::string Items[3]; //= {"Password", "Alohamora Spell", "Red Sphere of Light"};
	static const std::string Characters[2]; //= {"Portraits", "Hermione"};
};

#endif // !Harry_potter_h