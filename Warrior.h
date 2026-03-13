#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "Hero.h"

// inherits from hero
class Warrior : public Hero {
    int armorRating;

public:
    Warrior(std::string name, int hp, int pwr, int rating);
    int getArmor() const;
    int calculateEffectiveHealth();
    
};

#endif