#include "Item.h"
#include "Player.h"
#include "Room.h"
int main()
{
	Room room1 = Room();
	room1.getRoom("1");
	room1.printRoom();
	cin.ignore();
	bool done = false;
	while (!done)
	{
		string choice;
		welcome();
		cin >> choice;
		while (choice != "3")
		{
			if (choice == "1")
			{
				login();
			}
			else if (choice == "2")
			{
				newGame();
			}
			else if (choice == "3")
			{
				done = true;
			}
			else
			{
				cout << "Invalid choice." << endl;
			}
		}
	}
}

void welcome()
{
	cout << "Welcome to gate defence." << endl;
	cout << "Main Menu" << endl;
	cout << "1. Log into an existing account" << endl;
	cout << "2. Create New User" << endl;
	cout << "3. Exit" << endl;
}

void getDetails()
{
	string username;
	string password;
	cout << "UserName: ";
	cin >> username;
	cout << endl;
	cout << "Password: ";
	cin >> password;
	cout << endl;
	login(username, password);
}


void login(string username, string password) {

	string filename = "login.txt";

	ifstream infile(filename);
	string line;
	string garbage;
	if (infile)  // same as if(infile.good())
	{
		while (getline(infile, line))  // same as while (getline( infile, line ).good())
		{
			if (line == "Username: " + username)
			{
				//Username
				infile >> garbage;
				getline(infile, line);
				string un = line;
				//Password
				infile >> garbage;
				getline(infile, line);
				string pw = line;

				if (username == un && password == pw)
				{
					startGame(username);
				}
			}
		}
	}
}


void createCharacter()
{
	string username;
	string password;

	cout << "Please enter the username you wish to use" << endl;
	cin >> username;

	cout << "Please enter the password you wish to use" << endl;
	cin >> password;

	string filename = "login.txt";
	bool exists = false;
	ifstream infile(filename);
	string line;
	if (infile)  // same as if(infile.good())
	{
		while (getline(infile, line))  // same as while (getline( infile, line ).good())
		{
			if (line == "Username: " + username)
			{
				cout << "Name already exists" << endl;
				exists = true;
			}
		}
		if (exists == false)
		{
			registerUser(username, password);
			newGame(username);
		}
	}
}

void registerUser(string username, string password)
{
	string filename = username + ".txt";
	cout << filename << endl;
	ofstream ofile(filename);
	ofile << "Username: " << username << endl;
	ofile << "Password: " << password << endl;
}

void newGame(string username)
{
	Player p1 = Player();
	p1.setName(username);
	cout << "Welcome " << username << "Welcome to the kingdom of Fioria.\n You have come to Fioria to become a great warrior by helping to defend against hells gate which is always under attack by dark and hidious monsters.\n Now why don't you tell me how you're previous training has paid off" << endl;
	cin.ignore();
	p1.applyPoints();
	string choice;
	while (choice != "no" || choice != "1")
	{
		cout << "Are you sure you are happy with these choices?" << endl;
		cin >> choice;
		if (choice == "1" || choice == "yes" || choice == "y")
		{
			p1.savePlayer();
			cout << "Very well lets continue.";
			startGame(username);

		}
		else if (choice != "no" || choice != "1" || choice != "n")
		{
			cout << "Very well lets try this again." << endl;
			p1.applyPoints();
		}
		else
		{
			cout << "Invalid Choice." << endl;
		}
	}
}

void startGame(string username)
{
	Player p1 = Player();
	p1.loadPlayer(username);

	Room r1 = Room();
	r1.getRoom("1");
	bool done = false;
	while (!done)
	{
		string selection = "";
		cout << "What would you like to do? Say help if you wish to see the available commands";
		cin >> selection;

		string firstword = ParseWord(selection, 0);

		if (firstword == "north")
		{
			if (r1.getNorth() == "0")
			{
				cout << "There is nothing there." << endl;
			}
			else
			{
				r1.setID(r1.getNorth());
				r1.getRoom(r1.getNorth());
			}
		}
		else if (firstword == "east")
		{
			if (r1.getEast() == "0")
			{
				cout << "There is nothing there." << endl;
			}
			else
			{
				r1.setID(r1.getEast());
				r1.getRoom(r1.getEast());
			}
		}
		else if (firstword == "west")
		{
			if (r1.getWest() == "0")
			{
				cout << "There is nothing there." << endl;
			}
			else
			{
				r1.setID(r1.getWest());
				r1.getRoom(r1.getWest());
			}
		}
		else if (firstword == "south")
		{
			if (r1.getSouth() == "0")
			{
				cout << "There is nothing there." << endl;
			}
			else
			{
				r1.setID(r1.getSouth());
				r1.getRoom(r1.getSouth());
			}
		}
		else if (firstword == "battle")
		{
			if (r1.getID() == "3")
			{
				fight();
			}
			else
			{
				cout << "There is no one here to fight. Head over to the wall if you wish to start a fight." << endl;
			}
		}
		else if (firstword == "rest")
		{
			if (r1.getID() == "2")
			{
				cout << "Welcome " << p1.getName() << ". Please rest and enjoy you're sleep" << endl;
				p1.rest();
				p1.applyPoints();
			}
			else
			{
				cout << "You cannot rest here you must visit the inn in order to do that." << endl;
			}
		}
		else if (firstword == "buy")
		{
			if (r1.getID() == "4")
			{
				Item i1 = Item();
				string secondword = ParseWord(selection, 2);
				if (secondword == "potion")
				{
					i1.getItem("1");
					if (p1.getGold() >= i1.getCost())
					{
						p1.spendGold(i1.getCost());
						p1.addItem("1");
						cout << "You have spent " << i1.getCost() << " on a potion." << endl;
						cout << "Your Current balance is " << p1.getGold() << endl;
					}
					else
					{
						cout << "You do not have enough money to purchase this item. Earn money by fighting at the wall and defending our kingdom." << endl;
					}
				}
				else if (secondword == "sword")
				{
					i1.getItem("2");
					if (p1.getGold() >= i1.getCost())
					{

						p1.spendGold(i1.getCost());
						p1.addItem("2");
						cout << "You have spent " << i1.getCost() << " on a sword." << endl;
						cout << "Your Current balance is " << p1.getGold() << endl;
					}
					else
					{
						cout << "You do not have enough money to purchase this item. Earn money by fighting at the wall and defending our kingdom." << endl;
					}
				}
				else if (secondword == "sheild")
				{
					i1.getItem("3");
					if (p1.getGold() >= i1.getCost())
					{

						p1.spendGold(i1.getCost());
						p1.addItem("3");
						cout << "You have spent " << i1.getCost() << " on a sheild." << endl;
						cout << "Your Current balance is " << p1.getGold() << endl;
					}
					else
					{
						cout << "You do not have enough money to purchase this item. Earn money by fighting at the wall and defending our kingdom." << endl;
					}
				}
				else if (secondword == "boots")
				{
					i1.getItem("4");
					if (p1.getGold() >= i1.getCost())
					{

						p1.spendGold(i1.getCost());
						p1.addItem("4");
						cout << "You have spent " << i1.getCost() << " on boots." << endl;
						cout << "Your Current balance is " << p1.getGold() << endl;
					}
					else
					{
						cout << "You do not have enough money to purchase this item. Earn money by fighting at the wall and defending our kingdom." << endl;
					}
				}
			}
			else
			{
				cout << "There is nothing to buy here go to the shop to purchase items." << endl;
			}
		}
		else if (firstword == "help")
		{
			help();
		}
		else if (firstword == "exit")
		{
			done = true;
		}
		else
		{
			cout << "This command does not exist" << endl;
		}
	}

}

void help()
{
	cout << "Command:\tDescription:" << endl;
	cout << "north\tMoves player north." << endl;
	cout << "south\tMoves player south." << endl;
	cout << "east\tMoves player east." << endl;
	cout << "west\tMoves player west." << endl;
	cout << "fight\tStarts a battle if your at the gates." << endl;
	cout << "rest\tLets you rest and spend points you got by leveling up." << endl;
	cout << "buy 'itemname'\tBuys the item name you specified." << endl;
	cout << "exit\tLogs you out of the game and brings you back to the main menu." << endl;
}

string ParseWord(string selection, int index) {
	const std::string WHITESPACE = " \t\n\r";
	//wss = white space start
	int wss = selection.find_first_not_of(WHITESPACE);
	while (index > 0)
	{
		index--;
		//find the beginning of the next word and the whitespace at the end
		wss = selection.find_first_of(WHITESPACE, wss);
		wss = selection.find_first_not_of(WHITESPACE, wss);
	}
	//find the end of the word
	int wse = selection.find_first_of(WHITESPACE, wss);
	if (wss == std::string::npos) {
		wss = 0;
		wse = 0;
	}
	return selection.substr(wss, wse - wss);
}