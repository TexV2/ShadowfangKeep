#include "Warrior.h"
Warrior::Warrior(const std::string& name)
	: Player(name, 150, 20, 10, 1) // Example base stats for a Warrior
{
	this->asciiArt = R"(  
  / \
  | |
  |.|
  |.|
  |:|      __
,_|:|_,   /  )
  (Oo    / _I_
   +\ \  || __|
      \ \||___|
        \ /.:.\-\
         |.:. /-----\
         |___|::oOo::|
         /   |:<_T_>:|
        |_____\ ::: /
         | |  \ \:/
         | |   | |
         \ /   | \___
         / |   \_____\
         `-')" "\n";
}
Warrior::~Warrior()
{
}
// Override levelUp to provide Warrior-specific stat increases

// Info
std::string Warrior::toString()
{
	return "Class: Warrior\n" + Player::toString();
}