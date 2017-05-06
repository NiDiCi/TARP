#ifndef ROOM_H
#define ROOM_H


#include <iostream>
#include <string>
#include "Player.h"


using namespace std;

class Room
{
private:
	string id;
	string name;
	string desc;
	string north;
	string south;
	string east;
	string west;
	OrderedArray<string> inventory;

public:

	Room()
	{
		id = 0;
		name = "";
		desc = "";
		north = "";
		south = "";
		east = "";
		west = "";
	}

	void removeItem(string id)
	{
		inventory.remove(inventory.searchBinary(id));
	}

	void setID(string p_id)
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
	void setNorth(string roomid)
	{
		north = roomid;
	}

	void setSouth(string roomid)
	{
		south = roomid;
	}

	void setEast(string roomid)
	{
		east = roomid;
	}

	void setWest(string roomid)
	{
		west = roomid;
	}

	string getID()
	{
		return id;
	}

	string getNorth()
	{
		return north;
	}

	string getSouth()
	{
		return south;
	}
	string getEast()
	{
		return east;
	}
	string getWest()
	{
		return west;
	}

	void addItem(string p_id)
	{
		inventory.push(p_id);
	}

	void printInventory()
	{
		Item item = Item();
		cout << "Items" << endl;
		for (int i = 1; i < inventory.getSize(); i++)
		{
			cout << endl;
			cout << i << endl;
			item.getItem(inventory[i]);
			item.printItem();
		}
	}

	void getRoom(string id)
	{
		ifstream infile("Rooms.txt");
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
					//North
					infile >> garbage;
					getline(infile, line);
					this->setNorth(line);
					//South
					infile >> garbage;
					getline(infile, line);
					this->setSouth(line);
					//East
					infile >> garbage;
					getline(infile, line);
					this->setEast(line);

					//West
					infile >> garbage;
					getline(infile, line);
					this->setWest(line);

					//Inventory
					getline(infile, line, ':');
					string result;
					while (getline(infile, result, ','))
					{
						this->addItem(result);
					}


				}
			}
		}
	}

	void printRoom()
	{
		cout << "Name: " << name << endl;
		cout << "Description: " << desc << endl;
		cout << "North: " << north << endl;
		cout << "South: " << south << endl;
		cout << "East: " << east << endl;
		cout << "West: " << west << endl;
		this->printInventory();
	}

};
#endif