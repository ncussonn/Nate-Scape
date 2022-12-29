// Combat Library for NateScape

using namespace std;

#include <iostream>
#include <cstdio>
#include <unordered_map>


// Generic Class Template
class Class {

    // Access Specifiers
    private:
        // Private Attributes and Methods
               
    public:
        // Public Attributes and Methods

};

// base/super creature class
class Creature {

    // Access Specifiers
    private:
        // Private Atributes and Methods
        int hitpoints;
        int attack;
        int defense;
    
    public:

        // Constructor
        Creature(int hp, int atk, int def) {
            hitpoints = hp;
            attack = atk;
            defense = def;
        }

        // change hitpoints
        void modifyHP(int change){
            hitpoints += change;
            // hitpoints cannot be negative
            if(hitpoints <= 0) {
                hitpoints = 0;
            }
        }

        // change attack
        void modifyAttack(int change){
            attack += change;
            // attack cannot be negative
            if(attack <= 0) {
                attack = 0;
            }
        }

        // change defense
        void modifyDefense(int change){
            defense += change;
        }

        // get hitpoints
        int getHitpoints() {
            cout << hitpoints << endl;
            return hitpoints;
        }

        // get attack
        int getAttack() {
            cout << attack << endl;
            return attack;
        }

        // get defense
        int getDefense() {
            cout << defense << endl;
            return defense;
        }
}

// Skeleton (5 hp, 3 atk, 0 def)
class Skeleton: public Creature(5, 3, 0) {

}

// Goblin (10 hp, 2 atk, 1 def)
class Goblin: public Creature(10, 2, 1) {

}

// Orc (15 hp, 1 atk, 2 def)
class Orc: public Creature(15, 1, 2) {

}

// Troll (20 hp, 0 atk, 3 def)
class Troll: public Creature(20, 0, 3) {

}
