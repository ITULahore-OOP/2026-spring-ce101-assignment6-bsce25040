#ifndef HERO_H
#define HERO_H
#include <string>

// base class for all types of heroes
class Hero {
    std::string heroName;
    int health;
    int basePower;

public:
    Hero(std::string name, int hp, int pwr);
    ~Hero();
    std::string getName() const;
    int getHealth() const;
    int getPower() const;
    void takeDamage(int dmg);
    bool operator>(const Hero &other) const;
    int operator+(const Hero &other) const;
};

#endif