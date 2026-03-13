#include "Hero.h"
#include <iostream>

// constructor
Hero::Hero(std::string name, int hp, int pwr) {
    heroName = name;
    health = hp;
    basePower = pwr;
}

// destructor
Hero::~Hero() {
    std::cout << heroName << " has been destructed.\n";
}


// getters
std::string Hero::getName() const {
    return heroName;
}
int Hero::getHealth() const {
    return health;
}
int Hero::getPower() const {
    return basePower;
}



// subtract dmg from hp
void Hero::takeDamage(int damage) {
    // edge case
    if(health - damage <= 0) {
        health = 0;
        return;
    }
    health -= damage;
}

bool Hero::operator>(const Hero &other) const {
    return basePower > other.getPower();
}
int Hero::operator+(const Hero &other) const {
    return health + other.getHealth();
}