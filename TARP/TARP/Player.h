#ifndef PLAYER_H
#define PLAYER_H

#include<fstream>
#include<ostream>
#include <iostream>
#include <string>
#include "OrderedArray.h"
#include "Item.h"

using namespace std;

class Player
{
private:
	string name;
	int health;
	int gold;
	int maxhealth;
	int damage;
	int defence;
	int speed;
	int level;
	int exp;
	int maxexp;
	int points;
	OrderedArray<string> inventory;

public:
	Player()
	{
		name = "Default";
		maxhealth = 100;
		health = 100;
		gold = 0;
		damage = 0;
		defence = 0;
		speed = 0;
		level = 1;
		exp = 0;
		maxexp = 100;
		points = 20;
	}

	string getName()
	{
		return name;
	}
	int getGold()
	{
		return gold;
	}
	void setName(string p_name)
	{
		name = p_name;
	}
	void setGold(int p_gold)
	{
		gold = p_gold;
	}
	void setHealth(int p_health)
	{
		health = p_health;
	}
	void setMaxHealth(int p_maxhealth)
	{
		maxhealth = p_maxhealth;
	}
	void setDamage(int p_damage)
	{
		damage = p_damage;
	}
	void setDefence(int p_defence)
	{
		defence = p_defence;
	}
	void setSpeed(int p_speed)
	{
		speed = p_speed;
	}
	void setLevel(int p_level)
	{
		level = p_level;
	}

	void setExp(int p_exp)
	{
		exp = p_exp;
	}
	void setMaxExp(int p_maxexp)
	{
		maxexp = p_maxexp;
	}
	void setPoints(int p_point)
	{
		points = p_point;
	}
	void increaseGold(int p_gold)
	{
		gold += p_gold;
	}

	void spendGold(int p_gold)
	{
		gold -= p_gold;
	}

	void createChar()
	{
		cout << "Welcome warrior. Now customise your character to how you would like. You have 20 points to apply." << endl;
		applyPoints();
	}

	void increaseExp(int exp)
	{
		exp = exp + exp;
		if (exp >= maxexp)
		{
			levelUp();
		}
	}

	void levelUp()
	{
		level++;
		exp = 0;
		maxexp = maxexp + 20;
		points = points + 5;
		cout << "Concrats you have leveled up. You must go to the in to apply your skill points." << endl;
	}

	void applyPoints()
	{
		int upgrade = 0;

		while (points != 0)
		{
			cout << "Points: " << points << endl;
			cout << "------------------------" << endl;
			cout << "1. Health: " << health << endl;
			cout << "2. Damage: " << damage << endl;
			cout << "3. Defence: " << defence << endl;
			cout << "4. Speed: " << speed << endl;

			cin >> upgrade;
			if (upgrade == 1)
			{
				health = health + 20;
				maxhealth = maxhealth + 20;
				points--;
			}
			else if (upgrade == 2)
			{
				damage = damage + 5;
				points--;
			}
			else if (upgrade == 3)
			{
				defence = defence + 5;
				points--;
			}
			else if (upgrade == 4)
			{
				speed = speed + 5;
				points--;
			}
			else
			{
				cout << "Error try again" << endl;
			}
		}
	}
	void viewStats()
	{
		cout << "Name: " << name << endl;
		cout << "Gold: " << gold << endl;
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
		cout << "Defence: " << defence << endl;
		cout << "Speed: " << speed << endl;
		cout << "Level: " << level << endl;
		cout << "Experience: " << exp << endl;
		cout << "Points to Spend: " << points << endl;
	}

	void rest()
	{
		health = maxhealth;
	}

	void takeDamage(int damage)
	{
		health -= damage;
	}

	void addItem(string id)
	{
		inventory.push(id);
	}

	void printInventory()
	{
		Item item = Item();
		for (int i = 1; i < inventory.getSize(); i++)
		{
			item.getItem(inventory[i]);
			item.printItem();
		}
	}

	void savePlayer() {
		string filename = getName() + ".txt";
		cout << filename << endl;
		ofstream ofile(filename);
		ofile << "Name: " << name << endl;
		ofile << "Gold: " << gold << endl;
		ofile << "Health: " << health << endl;
		ofile << "MaxHealth: " << maxhealth << endl;
		ofile << "Damage: " << damage << endl;
		ofile << "Defence: " << defence << endl;
		ofile << "Speed: " << speed << endl;
		ofile << "Level: " << level << endl;
		ofile << "Experience: " << exp << endl;
		ofile << "MaxExperience: " << maxexp << endl;
		ofile << "Points: " << points << endl;
		ofile << "Inventory: ";
		for (int i = 0; i <= inventory.getSize(); i++)
		{
			ofile << inventory[i] << ",";
		}
	}


	void loadPlayer(string username) {
		string filename = username + ".txt";
		cout << filename << endl;
		ifstream infile(filename);
		string line;
		string garbage;
		if (infile)  // same as if(infile.good())
		{
			while (getline(infile, line))  // same as while (getline( infile, line ).good())
			{
				//Name
				infile >> garbage;
				getline(infile, line);
				this->setName(line);
				//Gold
				infile >> garbage;
				getline(infile, line);
				this->setGold(atoi(line.c_str()));
				//Health
				infile >> garbage;
				getline(infile, line);
				this->setHealth(atoi(line.c_str()));

				//Health
				infile >> garbage;
				getline(infile, line);
				this->setMaxHealth(atoi(line.c_str()));
				//Damage
				infile >> garbage;
				getline(infile, line);
				this->setDamage(atoi(line.c_str()));
				//Defence
				infile >> garbage;
				getline(infile, line);
				this->setDefence(atoi(line.c_str()));
				//Speed
				infile >> garbage;
				getline(infile, line);
				this->setSpeed(atoi(line.c_str()));
				//Level
				infile >> garbage;
				getline(infile, line);
				this->setLevel(atoi(line.c_str()));
				//Exp
				infile >> garbage;
				getline(infile, line);
				this->setExp(atoi(line.c_str()));

				//Exp
				infile >> garbage;
				getline(infile, line);
				this->setMaxExp(atoi(line.c_str()));

				//Exp
				infile >> garbage;
				getline(infile, line);
				this->setPoints(atoi(line.c_str()));
				//Inventory
				getline(infile, line, ':');
				string result;
				while (getline(infile, result, ','))
				{
					this->addItem(result);
				}



			}
		}
	};

#endif