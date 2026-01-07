#include "Warrior.h"
Warrior::Warrior(const std::string& name)
	: Player(name, 150, 20, 10) // Example base stats for a Warrior
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
void Warrior::levelUp()
{
	Player::levelUp(); // Call base class levelUp
	// Additional Warrior-specific increases
	int extraHP = 15;
	int extraAttack = 3;
	int extraDefense = 2;
	maxHP += extraHP;
	attack += extraAttack;
	defense += extraDefense;
	currentHP = maxHP; // Heal to full on level up
}
// Info
std::string Warrior::toString()
{
	return "Class: Warrior\n" + Player::toString();
}