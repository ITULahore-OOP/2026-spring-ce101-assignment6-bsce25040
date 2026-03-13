#include "Warrior.h"

// constructor
Warrior::Warrior(std::string name, int hp, int pwr, int rating) : Hero(name, hp, pwr) {
    armorRating = rating;
}

// getter
int Warrior::getArmor() const {
    return armorRating;
}

// since warrior is wearing armor so his health is as following
int Warrior::calculateEffectiveHealth() {
    return getHealth() + (armorRating*2);
}


