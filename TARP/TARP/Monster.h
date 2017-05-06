#ifndef MONSTER_H
#define MONSTER_H

#include<fstream>
#include<ostream>
#include <iostream>
#include <string>
using namespace std;

class Monster
{
private:
	string name;
	int health;
	int gold;
	int damage;
	int defence;
	int speed;
	int exp;

public:
	Monster(string p_name, int p_gold, int p_health, int p_damage, int p_defence, int p_speed, int p_exp)
	{
		name = p_name;
		gold = p_gold;
		health = p_health;
		damage = p_damage;
		defence = p_defence;
		speed = p_speed;
		exp = p_exp;
	}

	void viewStats()
	{
		cout << "Name: " << name << endl;
		cout << "Gold: " << gold << endl;
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
		cout << "Defence: " << defence << endl;
		cout << "Speed: " << speed << endl;
		cout << "Experience: " << exp << endl;

	}

	void takeDamage(int damage)
	{
		health -= damage;
	}
};
#endif