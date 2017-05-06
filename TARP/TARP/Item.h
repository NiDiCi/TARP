#ifndef ITEM_H
#define ITEM_H

#include<fstream>
#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	int id;
	string name;
	string desc;
	int cost;
	int health;
	int maxhealth;
	int damage;
	int defence;
	int speed;

public:
	Item()
	{
		id = 0;
		name = "default";
		desc = "Default";
		cost = 0;
		health = 0;
		damage = 0;
		defence = 0;
		speed = 0;
	}

	void setId(int p_id)
	{
		id = p_id;
	}

	void setName(string p_name)
	{
		name = p_name;
	}

	void setDesc(string p_desc)
	{
		desc = p_desc;
	}

	void setCost(int p_cost)
	{
		cost = p_cost;
	}

	void setHealth(int p_health)
	{
		health = p_health;
	}

	void setDamage(int p_damage)
	{
		damage = p_damage;
	}

	void setDefence(int p_defence)
	{
		id = p_defence;
	}

	void setSpeed(int p_speed)
	{
		speed = p_speed;
	}

	int getId()
	{
		return id;
	}

	string getName()
	{
		return name;
	}

	string getDesc()
	{
		return desc;
	}

	int getHealth()
	{
		return health;
	}
	int getCost()
	{
		return cost;
	}

	int getDamage()
	{
		return damage;
	}

	int getDefence()
	{
		return defence;
	}

	int getSpeed()
	{
		return speed;
	}

	void getItem(string id)
	{

		ifstream infile("Item.txt");
		string line;
		string garbage;
		string value;

		if (infile)  // same as if(infile.good())
		{
			while (getline(infile, line))  // same as while (getline( infile, line ).good())
			{
				if (line == "ID: " + id)
				{
					//Name
					infile >> garbage;
					getline(infile, line);
					this->setName(line);
					//Description
					infile >> garbage;
					getline(infile, line);
					this->setDesc(line);
					//Cost
					infile >> garbage;
					getline(infile, line);
					this->setCost(atoi(line.c_str()));
					//Health
					infile >> garbage;
					getline(infile, line);
					this->setHealth(atoi(line.c_str()));
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
				}
			}
		}
		infile.close();
	}


	void printItem()
	{
		cout << "Name: " << name << endl;
		cout << "Description: " << desc << endl;
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
		cout << "Defence: " << defence << endl;
		cout << "Speed: " << speed << endl;
	}
};
#endif