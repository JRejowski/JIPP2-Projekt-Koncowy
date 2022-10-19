//
// Created by Yonasz on 22.01.2022.
//

#ifndef JIPP2_SCENAWALKA_H
#define JIPP2_SCENAWALKA_H

#include "Scena.h"
#include <string>

using namespace std;

class Actor;

enum class DamageType {
	Physical,
	Magical
};


class ScenaWalka:public Scena {
public:

    /**
     * function to update scene
     * @return - false if scene ended, true if it's still going
     */
    bool update();
    /**
     * function to show actors' Name, HP and Mana
     */
    void drukujStaty() const;
    /**
     * prints raport after each round of fight (who dealt how much damage)
     */
    void drukujRaport() const;
    /**
     * shows player the possible attacks
     * @return returns a number (1 or 2) depending which attack player chose
     */
    DamageType drukujOpcje() const;
    /**
     * function that conducts fight between player and enemy
     * @param i - specifies which kind of attack player chose
     * @return false if the fight is over, true when it's not
     */
    bool walka(const DamageType i);
    /**
     * Constructor
     * @param p - pointer to player
     * @param name - name of the enemy
     * @param hp - basic hp of the enemy
     * @param mana - basic mana of the enemy
     * @param minDmg - minimum damage that the enemy will deal
     * @param maxDmg - maximum damage that the enemy will deal
     * @param minDmgSpell - minimum magical damage that the enemy will deal
     * @param maxDmgSpell maximum magical damage that the enemy will deal
     */
    ScenaWalka(Actor *p, string name, int hp, int mana, int minDmg, int maxDmg, int minDmgSpell, int maxDmgSpell);
    /**
     * Destructor, frees the memory
     */
    ~ScenaWalka();
private:
    Actor* player;
    Actor* enemy;
    int lastPlayerDmg = 0;
    int lastEnemyDmg = 0;
    int numerTury=1;

};


#endif //JIPP2_SCENAWALKA_H
