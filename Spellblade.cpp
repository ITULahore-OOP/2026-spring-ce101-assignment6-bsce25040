#include "Spellblade.h"

// constructor
Spellblade::Spellblade(std::string name, int hp, int pwr, int rating, int mana, int spellPWR) : Warrior(name, hp, pwr, rating), MagicalEntity(mana, spellPWR) {}


// calculating hybrid damage (special move)
int Spellblade::calculateHybridDamage() {
    return getPower() + getSpellPower();
}

