#include "Helmet.h"
Helmet::Helmet(const std::string& name, const std::string& description, int defenseBoost)
    : Armor(name, description, defenseBoost, 1)
{
}