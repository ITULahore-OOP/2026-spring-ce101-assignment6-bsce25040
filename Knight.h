#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>
#include "Warrior.h"

// inherits from warrior (multi-level inheritance)
class Knight : public Warrior {
    int chargeBonus;

public:
    Knight(std::string name, int hp, int pwr, int rating, int bonus);
    int getChargeBonus();
    int calculateBurstDamage();
    
};

#endif