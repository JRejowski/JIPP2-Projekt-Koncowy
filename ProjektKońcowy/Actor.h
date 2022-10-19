//
// Created by Yonasz on 22.01.2022.
//

#ifndef JIPP2_ACTOR_H
#define JIPP2_ACTOR_H

#include <string>
#include <stdlib.h>

using namespace std;

class Actor {
public:
    /**
     * Constructor
     * @param name - Actor's name
     * @param hp - Health points
     * @param mana - Mana points
     * @param minDmg - minimum damage that will be dealt
     * @param maxDmg - maximum damage that will be dealt
     * @param minDmgSpell - minimum magic damage that will be dealt
     * @param maxDmgSpell - maximum magic damage that will be dealt
     */
    Actor(const string& name,int hp,int mana,int minDmg, int maxDmg, int minDmgSpell, int maxDmgSpell);
    /**
     * Function to check if actor is alive
     * @return true if actor is alive, false when it's dead
     */
    bool czyZyje() const;
    /**
     * function to check if player have mana
     * @return true if there is mana, false when there isn't
     */
    bool czyJestMana() const;
    /**
     * calculates the damage that will be dealt (using rand() function)
     * @return amount of damage that will be dealt
     */
    int getDmg() const;
    /**
     * calculates the damage that will be dealt with mana (using rand() function)
     * @return amount of magic damage that will be dealt
     */
    int getDmgSpell() const;

    /**
     * getter to hp
     * @return hp
     */
    int getHP() const;
    /**
     * setter to hp
     * @param hp - hp value to be set
     */
    void setHP(int hp);

    /**
     * getter to mana
     * @return mana
     */
    int getMana() const;
    /**
     * setter to mana
     * @param mana - mana value to be set
     */
    void setMana(int mana);

    /**
     * function that restores players hp and mana
     */
    void restart();

    /**
     * operator that is used to show name
     * @return actor's name
     */
    const string operator*() const;

private:
    string name;
    int hp;
    int mana;
    int minDmg;
    int maxDmg;
    int maxDmgSpell;
    int minDmgSpell;
};


#endif //JIPP2_ACTOR_H
