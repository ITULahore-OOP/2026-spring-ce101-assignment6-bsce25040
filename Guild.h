#ifndef GUILD_H
#define GUILD_H


#include <string>
#include <iostream>
#include "Hero.h"
using namespace std;

//  a class which HAS heroes 
class Guild {
    std::string guildName;
    Hero* roster[15];
    int memberCount;

public:
    Guild(std::string name);
    ~Guild();
    int calculateTotalGuildPower();
    void displayGuildStats();
    void operator+=(Hero*);
    friend ostream& operator<<(ostream&, Guild&);

    // a helper i need for main
    int searchByName(string name);
};

#endif