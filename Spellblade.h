#ifndef SPELLBLADE_H
#define SPELLBLADE_H

#include "Warrior.h"
#include "MagicalEntity.h"

// multiple inheritances from warrior and magical entity
class Spellblade : public Warrior, public MagicalEntity {
    public:
    Spellblade(std::string name, int hp, int pwr, int rating, int mana, int spellPWR);
    int calculateHybridDamage();
    
};

#endif