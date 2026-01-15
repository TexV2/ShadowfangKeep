#pragma once
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

class Player;
template <typename T>
class Inventory {
private:
    std::vector<T> items;
    std::vector<T> equippedItems;

public:
    Inventory() = default;
    ~Inventory() = default;

    void add(const T& item) { items.push_back(item); }

    void remove(size_t index) { items.erase(items.begin() + index); }

    void equip(T item, Player& player)
    {
        if (!item) return;

        // Ta bort item från inventory
        for (size_t i = 0; i < items.size(); ++i)
        {
            if (items[i] == item)
            {
                items.erase(items.begin() + i);
                break;
            }
        }

        // Om slot redan är equipad byt ut
        for (size_t i = 0; i < equippedItems.size(); ++i)
        {
            if (equippedItems[i]->getSlot() == item->getSlot())
            {
                auto replacedName = equippedItems[i]->getName();

                equippedItems[i]->unequipItem(player);

                // Lägg tillbaka gamla i inventory
                items.push_back(equippedItems[i]);

                equippedItems[i] = item;
                equippedItems[i]->equipItem(player);

                std::cout << "Replaced " << replacedName
                    << " with " << item->getName()
                    << " in slot " << item->getSlot() << "\n";
                return;
            }
        }

		// Bara equipapa om slot är tom
        equippedItems.push_back(item);
        item->equipItem(player);

        std::cout << "Equipped " << item->getName()
            << " in slot " << item->getSlot() << "\n";
    }

    void clearAndDelete()
    {
        for (auto* p : items) delete p;
        for (auto* p : equippedItems) delete p;
        items.clear();
        equippedItems.clear();
    }

    const T& get(size_t index) const { return items.at(index); }

    int getIndex(const std::string& name) {
        for (size_t i = 0; i < items.size(); ++i)
            if (items[i]->getName() == name) return static_cast<int>(i);
        return -1;
    }

    size_t size() const { 
        return items.size(); 
    }
};