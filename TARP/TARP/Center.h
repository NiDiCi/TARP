#ifndef Center_h
#define Center_h

//Headers used in _h but also _cpp
#include <stdio.h>
#include "Space.h"

class Center : public Space
{
public:
	Center();
	int Special(char name[], char drink[], std::string player_name, Player* player);
	void input_sphere(std::string sphere);
	void display_Oracle_container();

private:
	static const std::string Spheres[4]; //= {"Blue Sphere of Light", "Red Sphere of Light", "Yellow Sphere of Light", "White Sphere of Light"};
	std::vector<std::string> Oracle_container;

};

#endif // !Center_h