#include "Knight.h"

// constructor
Knight::Knight(std::string name, int hp, int pwr, int rating, int bonus) : Warrior(name, hp ,pwr, rating) {
    chargeBonus = bonus;
}

// getters
int Knight::getChargeBonus() {
    return chargeBonus;
}

// calculating burst damage (special move)
int Knight::calculateBurstDamage() {
    return getPower() + chargeBonus;
}


