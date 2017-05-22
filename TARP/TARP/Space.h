
/* Short explanition of why this is a abstract class without it having the keyword
 * First a A non-member function can access the private and protected members of a
 * class if it is declared a friend of that class (its a form of inheritance).
 * A Virtual Function is  makes its class a polymorphic base class. Derived classes
 * can override virtual functions. Virtual functions called through base class
 * pointers/references will be resolved at run-time. On the other hand we also have
 * Pure Virtual Functions A pure virtual function implicitly makes the class it is
 * defined for abstract (unlike in Java where you have a keyword to explicitly
 * declare the class abstract). Abstract classes cannot be instantiated. Derived
 * classes need to override/implement all inherited pure virtual functions. If they
 * do not, they too will become abstract.
 * * * */

// this is include gaurds
#ifndef Space_h
#define Space_h

//Headers used in _h but also _cpp
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Player.h"
#include "Menu.h"

/* Abstract class */
class Space {

	friend class Map;
	friend class Player;

public:

	Space();

	/* Pure virtual function */
	virtual int Special(char name[], char drink[], std::string player_name, Player *player) = 0;
};
#endif // !Space_h