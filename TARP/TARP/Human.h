

#include <string>

class player {

public:
	player(std::string name, std::string area, int level, int exp) {
	};
	void setName(std::string name);
	void setArea(std::string area);

	void setLevel(int level);
	int getlevel();

	void setExp() { exp = (getlevel() * 35); };
	int getExp();

	void setReqExp();
	int getReqExp();

	void setMaxHealth(double playerMaxhealth);
	void setHealth(double playerHealth);
	double getHealth();
	double getMaxHealth();

	void setDamage();
	int getdamage();

private:
	std::string playerName;
	std::string playerArea;
	int playerlevel;
	int exp;
	double playerHealth;
	double playerMaxHealth;
	int playerDamage;
	int expReq;

};