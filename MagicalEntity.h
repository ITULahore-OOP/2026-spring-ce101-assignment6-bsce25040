#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H
#include <string>

// abstract class
class MagicalEntity {
    int manaPool;
    int spellPower;

public:
    MagicalEntity(int mana, int pwr);
    int getMana() const;
    int getSpellPower() const;
};

#endif