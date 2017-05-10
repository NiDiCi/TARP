#include "Menu.h"

int Menu::game_menu() {

	int menu;
	std::cout << "Please choose what you would like to do." << std::endl;
	std::cout << "1: Start the game." << std::endl;
	std::cout << "2: Exit." << std::endl;
	std::cin >> menu;
	return menu;
}

void Menu::coffee_menu(char name[], char drink[]) {

	std::cout << "" << std::endl;
	std::cout << "" << name << "" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "You have walked into " << name << " to get a " << drink << " on a cold winter day." << std::endl;
	std::cout << "You see a $20 bill on the ground. You choose to..." << std::endl;
	std::cout << "\t 1: Pick up the $20 bill." << std::endl;
	std::cout << "\t 2: Ignore the $20 bill and order your " << drink << "." << std::endl;
}

void Menu::pick_up_20() {

	std::cout << "You bend down to pick up the $20 bill. As soon as you lift it" << std::endl;
	std::cout << "off the ground, you see the ground you're standing on shift." << std::endl;
	std::cout << "Suddenly the floor under your feet disappears and you're sliding" << std::endl;
	std::cout << "downwards at a frightening speed!" << std::endl;

}

void Menu::order_drink(char drink[]) {

	std::cout << "You ignore the $20 bill on the floor and move toward the Barista at the counter." << std::endl;
	std::cout << "You: I would like a " << drink << ", please." << std::endl;
	std::cout << "Barista: Anything else?" << std::endl;
	std::cout << "You shake your head 'no' while you pull your wallet out of your pocket." << std::endl;
	std::cout << "Barista: That'll be $2.49. " << std::endl;
	std::cout << "You pay three dollars. The Barista hands you your " << drink << std::endl;
	std::cout << "and change, but a penny falls to the floor. You..." << std::endl;
	std::cout << "\t 1: Pick up the 0.1." << std::endl;
	std::cout << "\t 2: Take a sip of your deliciously warm " << drink << "." << std::endl;
}

void Menu::pick_up_penny() {

	std::cout << "You bend down to pick up the useless penny. As soon as you lift it" << std::endl;
	std::cout << "off the ground, you see the ground you're standing on shift." << std::endl;
	std::cout << "Suddenly the floor under your feet disappears and you're sliding" << std::endl;
	std::cout << "downwards at a frightening speed!" << std::endl;
}

void Menu::take_sip(char drink[]) {

	std::cout << "You lift the delightful " << drink << " to your mouth and take an indulgent sip." << std::endl;
	std::cout << "A stranger walking past you in ridiculously mismatched clothes bumps" << std::endl;
	std::cout << "your shoulder and you drop your cup! Suddenly the floor " << std::endl;
	std::cout << "under your feet disappears and you're sliding downwards at a frightening speed!" << std::endl;
}

void Menu::center_menu(std::string player_name) {

	std::cout << "" << std::endl;
	std::cout << "                                  Center                                  " << std::endl;
	std::cout << "" << std::endl;

	std::cout << "You fall into a round room with four doors and a statue. There is a bright" << std::endl;
	std::cout << "light shining over the statue that sheds some light onto the remainder of the room." << std::endl;
	std::cout << "You hear a loud rumbling  coming from the statue and, in a moment, it's speaking." << std::endl;
	std::cout << "Oracle: " << player_name << ", you've had quite some luck today!" << std::endl;
	std::cout << "\t Now, your intellect shall be tested. In order to return to" << std::endl;
	std::cout << "\t the outside world, you must solve riddles and puzzles. These" << std::endl;
	std::cout << "\t will lead you to the hidden spheres in every room. Collect 4" << std::endl;
	std::cout << "\t spheres and return them to me to attain your freedom." << std::endl << std::endl;
	std::cout << "You will use your backpack to store your items." << std::endl;
	std::cout << "You can only store 5 items in your backpack at one time." << std::endl << std::endl;
}

void Menu::Oracle_riddle_star() {

	std::cout << "Oracle: Your first riddle will give you access to one of these 4 doors." << std::endl;
	std::cout << std::setw(60) << "I am everywhere." << std::endl;
	std::cout << std::setw(60) << "Nothing can compare." << std::endl;
	std::cout << std::setw(60) << "Run and hide and I will still be there." << std::endl;
	std::cout << std::setw(60) << "Because everything is mine to share." << std::endl;
	std::cout << std::setw(60) << "No need to seek me out." << std::endl;
	std::cout << std::setw(60) << "Though you may just run out." << std::endl;
	std::cout << std::setw(60) << "What am I?" << std::endl << std::endl;
	std::cout << "Select your answer:" << std::endl;
	std::cout << "\t 1: Time" << std::endl;
	std::cout << "\t 2: Space" << std::endl;
	std::cout << "\t 3: Air" << std::endl;
	std::cout << "\t 4: Water" << std::endl << std::endl;
}
void Menu::Oracle_riddle_harry() {

	std::cout << "Oracle: Your second riddle will give you access to a new door." << std::endl;
	std::cout << std::setw(60) << "Faster than a twitch!" << std::endl;
	std::cout << std::setw(60) << "Fly with me to the Pitch!" << std::endl;
	std::cout << std::setw(60) << "With a seeker, a keeper," << std::endl;
	std::cout << std::setw(60) << "Or a chaser, a beater," << std::endl;
	std::cout << std::setw(60) << "wizard or witch," << std::endl;
	std::cout << std::setw(60) << "I play a mean game of Quidditch." << std::endl;
	std::cout << std::setw(60) << "What am I?" << std::endl << std::endl;
	std::cout << "Select your answer:" << std::endl;
	std::cout << "\t 1: Baseball" << std::endl;
	std::cout << "\t 2: Hummingbird" << std::endl;
	std::cout << "\t 3: Broom" << std::endl;
	std::cout << "\t 4: Airplane" << std::endl << std::endl;
}

void Menu::Oracle_riddle_seuss() {

	std::cout << "Oracle: Your third riddle will give you access to a new door." << std::endl;
	std::cout << std::setw(60) << "You're wrong as the deuce" << std::endl;
	std::cout << std::setw(60) << "And you shouldn't rejoice" << std::endl;
	std::cout << std::setw(60) << "If you're calling him Seuss" << std::endl;
	std::cout << std::setw(60) << "He pronounces it Soice!" << std::endl;
	std::cout << std::setw(60) << "What does my real name rhyme with?" << std::endl;
	std::cout << "Select your answer:" << std::endl;
	std::cout << "\t 1: Couch" << std::endl;
	std::cout << "\t 2: Truce" << std::endl;
	std::cout << "\t 3: Voice" << std::endl;
	std::cout << "\t 4: Cruise" << std::endl << std::endl;
}

void Menu::Oracle_riddle_blank() {

	std::cout << "Oracle: Your final riddle will give you access to the last door." << std::endl;
	std::cout << std::setw(60) << "I'm more powerful than God." << std::endl;
	std::cout << std::setw(60) << "I'm more evil than the Devil." << std::endl;
	std::cout << std::setw(60) << "The poor have me." << std::endl;
	std::cout << std::setw(60) << "The rich need me." << std::endl;
	std::cout << std::setw(60) << "If you eat me, you will die." << std::endl;
	std::cout << std::setw(60) << "What am I?" << std::endl << std::endl;
	std::cout << "Select your answer:" << std::endl;
	std::cout << "\t 1: Money" << std::endl;
	std::cout << "\t 2: Food" << std::endl;
	std::cout << "\t 3: Air" << std::endl;
	std::cout << "\t 4: Nothing" << std::endl << std::endl;
}

void Menu::Oracle_give_sphere() {

	std::cout << "" << std::endl;
	std::cout << "Center" << std::endl;
	std::cout << "Center" << std::endl;

	std::cout << "Oracle: You have emerged from the room. Hand me the sphere you have found!" << std::endl;

	std::cout << "What action would you like to take?" << std::endl;
	std::cout << "\t 1: Give Oracle the sphere in your backpack." << std::endl;
}

void Menu::Oracle_end_menu(std::string player_name) {

	std::cout << "Center" << std::endl;

	std::cout << "Oracle: " << player_name << ", you have returned to me the four spheres." << std::endl;
	std::cout << "\t Your intellect has passed the tests. There remains one more choice" << std::endl;
	std::cout << "\t to be made. Select the blue pill to remember your journey. Select" << std::endl;
	std::cout << "\t the red pill to forget. Choose and be on your way! The door to" << std::endl;
	std::cout << "\t your freedom will disappear in 5 seconds." << std::endl << std::endl;
	std::cout << "Two pillars appear, one on your left, the other on your right." << std::endl;
	std::cout << "Behind you is your door to the outside." << std::endl << std::endl;
	std::cout << "What is your choice?" << std::endl;
	std::cout << "\t 1: Take the blue pill and remember." << std::endl;
	std::cout << "\t 2: Take the red pill and forget." << std::endl;
}