#include "Guild.h"

// constructor
Guild::Guild(std::string name) {
    guildName = name;
    memberCount = 0;

    for(int i = 0; i < 15; i++) roster[i] = nullptr;
}

// destructor
Guild::~Guild() {
    // for(int i = 0; i < memberCount; i++) delete roster[i];           cant do this for some reason, test cases get corrupted otherwise, try it
    cout << "The guild " << guildName << " has been disbanded!" << endl;
}

// calculating total power
int Guild::calculateTotalGuildPower() {
    int totalPWR = 0;
    for(int i = 0; i < memberCount; i++)
        totalPWR += roster[i]->getPower();
    return totalPWR;
}

// display guild stats
void Guild::displayGuildStats() {
    cout << "Guild Name: " << guildName << endl;
    cout << "Total Members: " << memberCount << "/15" << endl;
    cout << "Total Guild Power: " << calculateTotalGuildPower() << endl;
}

//operator overloading for +=
void Guild::operator+=(Hero* h) {
    if(memberCount > 14) {
        cout << "Guild is at full capacity!" << endl;
        return;
    }
    roster[memberCount] = h;
    memberCount++;
}

// operator overloading for output streams <<           ostream type operator overloaders need to be friended
ostream& operator<<(ostream& os, Guild &g) {
    os << "Guild: " << g.guildName << endl;
    os << "Members: " << g.memberCount << endl;
    for(int i = 0; i < g.memberCount; i++) {
        os << "- " << g.roster[i]->getName() << " (Power: " << g.roster[i]->getPower() << ")" << endl;
    }
    return os;
}

// helper
int Guild::searchByName(string name) {
    for(int i = 0; i < memberCount; i++) {
        if(roster[i]->getName() == name) return i; 
    }

    return -1;
}