#pragma once
#include "Armor.h"
class Helmet : public Armor
{
public:
	Helmet(const std::string& name, const std::string& description, int defenseBoost);
	~Helmet() override = default;
};