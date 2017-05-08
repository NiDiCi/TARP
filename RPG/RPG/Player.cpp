#include "Player.h"
#include "Space.h"

Player::Player() {

	player_name = "";
	player_in_space = NULL;
	player_drink = "";
	// backpack = {};

}

void Player::set_player_name(std::string name) {

	this->player_name = name;
}

std::string Player::display_player_name() {

	return this->player_name;
}

void Player::set_player_space(Space* space_name) {

	this->player_in_space = space_name;
}

Space *Player::display_player_space() {

	return this->player_in_space;
}

void Player::input_item(std::string item) {

	if (backpack.size() == 5) {

		std::cout << "Your backpack is full! " << item << " cannot be put in your backpack." << std::endl;
	}
	else {
		backpack.push_back(item);
		std::cout << item << " has been put in your backpack!" << std::endl;
	}
}

bool Player::check_item_available(std::string item) {

	if (std::find(backpack.begin(), backpack.end(), item) != backpack.end()) {

		return true;
	}
	else
		return false;
}

int Player::remove_item(std::string item) {

	if (check_item_available(item) == true){

		std::cout << item << " has been removed from backpack." << std::endl;
		backpack.erase(std::find(backpack.begin(), backpack.end(), item));
		return 0;
	}
	else {

		std::cout << item << " is not in your backpack." << std::endl;
	}
}

void Player::display_backpack_content() {

	std::cout << "Your backpack has the following items:" << std::endl;

	for (int i = 0; i < backpack.size(); i++) {
		int n = i + 1;
		std::cout << n << ": " << backpack.at(i) << std::endl;
	}
}

int Player::check_backpack_size() {

	return backpack.size();
}