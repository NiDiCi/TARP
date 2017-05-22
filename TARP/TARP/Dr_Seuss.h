#ifndef Dr_Seuss_h
#define Dr_Seuss_h

//Headers used in _h but also _cpp
#include <stdio.h>

#include "Space.h"

namespace TARP {
	class Seuss : public Space {
	public:
		Seuss();
		int Special(char name[], char drink[], std::string player_name, Player* player);

	private:
		static const std::string Items[4];// = {"Truffla-tree tuff", "Thneed", "15¢", "Yellow Sphere of Light"};
		static const std::string Characters[2];// = {"Humming Fish", "Once-ler"};
	};
}
#endif // !Dr_Seuss_h