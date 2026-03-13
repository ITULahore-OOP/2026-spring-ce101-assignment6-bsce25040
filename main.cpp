#include <iostream>
#include <string>
#include "Warrior.h"
#include "SpellBlade.h"
#include "Hero.h"
#include "Knight.h"
#include "MagicalEntity.h"
#include "Guild.h"
#include "colorcodes.h"

const int maxCapacity = 15;



int main() {
    int heroCount = 0;
    Hero** heapHeroes = new Hero*[maxCapacity];      // to manage the new heroes that we add to the guild
    cout << BLUE << "===============================\n            GUILD\n===============================\n" << RESET;
    string guildName;
    cout << "Enter guild name: "; cin >> guildName;
    Guild guild(guildName);

    int choice;
    bool exit = false;

    do {    // main menu
        cout << CYAN << "===============================\n           MAIN MENU\n===============================\n" << RESET;
        cout << YELLOW << "1. " << RESET << "Add a normal Hero\n";
        cout << YELLOW << "2. " << RESET << "Add Warrior\n";
        cout << YELLOW << "3. " << RESET << "Add Knight\n";
        cout << YELLOW << "4. " << RESET << "Add Spellblade\n";
        cout << YELLOW << "5. " << RESET << "Display Guild Stats\n";
        cout << YELLOW << "6. " << RESET << "Display Guild Roster\n";
        cout << YELLOW << "7. " << RESET << "Start a Duel\n";
        cout << YELLOW << "8. " << RESET << "Compare Two Heroes\n";
        cout << RED    << "0. " << RESET << "Disband Guild\n";
        cout << CYAN << "===============================" << RESET << endl;
        cout << "Select an option: ";
        
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore();
        }

        // dummy variables for creating heroes
        string name;
        int hp, pwr, armor, bonus, mana, spellPWR;

        switch(choice) {
            // ADD NORMAL HERO
            case 1: {
                cout << "Enter Name: "; cin >> name;
                cout << "Enter HP: "; cin >> hp;
                cout << "Enter Power: "; cin >> pwr;
                Hero* newHero = new Hero(name, hp, pwr);
                heapHeroes[heroCount++] = newHero;   // adding hero to the array that we will use to delete all heroes
                guild += newHero;         // adding the hero to the guild
                cout << GREEN << newHero->getName() << "joined the guild!" << RESET << endl;
                break;
            }
            // ADD WARRIOR
            case 2: {
                cout << "Enter Name: "; cin >> name;
                cout << "Enter HP: "; cin >> hp;
                cout << "Enter Power: "; cin >> pwr;
                cout << "Enter Armor Rating: "; cin >> armor;
                Warrior* newWarrior = new Warrior(name, hp, pwr, armor);
                guild += newWarrior;
                heapHeroes[heroCount++] = newWarrior;
                cout << GREEN << newWarrior->getName() << " joined the guild!" << RESET << endl;
                break;
            }
            // ADD KNIGHT
            case 3: {
                cout << "Enter Name: "; cin >> name;
                cout << "Enter HP: "; cin >> hp;
                cout << "Enter Power: "; cin >> pwr;
                cout << "Enter Armor Rating: "; cin >> armor;
                cout << "Enter Charge Bonus: "; cin >> bonus;
                Knight* newKnight = new Knight(name, hp ,pwr, armor, bonus);
                guild += newKnight;
                heapHeroes[heroCount++] = newKnight;
                cout << GREEN << newKnight->getName() << "joined the guild!" << RESET << endl;
                break;
            }
            // ADD SPELLBLADE
            case 4: {
                cout << "Enter Name: "; cin >> name;
                cout << "Enter HP: "; cin >> hp;
                cout << "Enter Power: "; cin >> pwr;
                cout << "Enter Armor Rating: "; cin >> armor;
                cout << "Enter Spell Power: "; cin >> spellPWR;
                cout << "Enter Mana: "; cin >> mana;
                Spellblade* newSpellblade = new Spellblade(name, hp ,pwr, armor, mana, spellPWR);
                guild += newSpellblade;
                heapHeroes[heroCount++] = newSpellblade;
                cout << GREEN << newSpellblade->getName() << "joined the guild!" << RESET << endl;
                break;
            }
            // DISPLAYING GUILD STATS
            case 5: {
                cout << MAGENTA << "==================\n     GUILD STATS\n==================" << RESET << endl;
                guild.displayGuildStats();
                break;
            }
            // DISPLAYING GUILD ROSTER
            case 6: {
                cout << MAGENTA << "==================\n     GUILD ROSTER\n==================" << RESET << endl;
                cout << guild;
                break;
            }
            // DUEL BETWEEN TWO HEROES
            case 7: {
                if(heroCount < 2) {
                    cout << RED << "You two heroes to start a duel!" << RESET << endl;
                    break;
                }
                cout << CYAN << "Available Heroes: " << RESET << endl << guild;
                string name1, name2;
                int hero1ID, hero2ID;
                cout << "\nEnter attacker's name: "; cin >> name1;
                cout << "Enter opponent's name: "; cin >> name2;
                hero1ID = guild.searchByName(name1);
                hero2ID = guild.searchByName(name2);
                if(hero1ID == -1 || hero2ID == -1) {
                    cout << RED << "Hero name not found." << RESET << endl;
                    break;
                }

                Hero* attacker = heapHeroes[hero1ID];
                Hero* opponent = heapHeroes[hero2ID];

                cout << RED << attacker->getName() << " attacks " << opponent->getName() << " for " << attacker->getPower() << " damage." << RESET << endl;
                opponent->takeDamage(attacker->getPower());
                cout << BLUE << opponent->getName() << "'s remaining HP: " << opponent->getHealth() << RESET << endl;

                delete attacker;
                delete opponent;

                break;
            }
            // COMPARISON BETWEEN TWO HEROES
            case 8: {
                if(heroCount < 2) {
                    cout << RED << "You two heroes to start a comparison!" << RESET << endl;
                    break;
                }
                cout << CYAN << "Available Heroes: " << RESET << endl << guild;
                string name1, name2;
                int hero1ID, hero2ID;
                cout << "\nEnter first hero's name: "; cin >> name1;
                cout << "Enter second hero's name: "; cin >> name2;
                hero1ID = guild.searchByName(name1);
                hero2ID = guild.searchByName(name2);
                if(hero1ID == -1 || hero2ID == -1) {
                    cout << RED << "Hero name not found." << RESET << endl;
                    break;
                }

                Hero* hero1 = heapHeroes[hero1ID];
                Hero* hero2 = heapHeroes[hero2ID];

                if(*hero1 > *hero2) cout << BLUE << hero1->getName() << " has more base power." << RESET << endl;
                else if(*hero2 > *hero1) cout << BLUE << hero2->getName() << " has more base power." << RESET << endl;
                else cout << BLUE << "Both have equal power." << RESET << endl;
                break;

                delete hero1;
                delete hero2;
            }
            // EXIT
            case 0: {
                exit = true;
                break;
            }
            

        }
    }while(!exit);

    cout << GREEN << "PROGRAM TERMINATED!" << RESET <<endl;

    return 0;
}