#ifndef Map_h
#define Map_h

//Headers used in _h but also _cpp
#include <stdio.h>
#include <iostream>

#include "Space.h"

class World {

	//Create map
	struct Map
	{
		Space* area;
		struct Map *pointer_1;
		struct Map *pointer_2;
		struct Map *pointer_3;
		struct Map *pointer_4;
		struct Map *pointer_5;
	};

public:
	World();
	void add(Space* coffee, Space* center, Space* star, Space* harry, Space* seuss, Space* blank);
	void set_current_location();
	Space* get_current_location();

private:
	Map *current_location;
	Map *center_w;
	Map *star_w;
	Map *harry_p;
	Map *dr_s;
	Map *blnk;

	Map *start;
	Map *end;
};

#endif // !Map_h