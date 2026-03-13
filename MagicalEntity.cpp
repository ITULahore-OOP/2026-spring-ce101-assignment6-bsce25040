#include "MagicalEntity.h"

// constructor
MagicalEntity::MagicalEntity(int mana, int pwr) {
    manaPool = mana;
    spellPower = pwr;
}

// getters
int MagicalEntity::getMana() const {
    return manaPool;
}
int MagicalEntity::getSpellPower() const {
    return spellPower;
}