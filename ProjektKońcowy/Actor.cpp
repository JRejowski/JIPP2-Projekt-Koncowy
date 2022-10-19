//
// Created by Yonasz on 22.01.2022.
//

#include "Actor.h"

bool Actor::czyZyje() const {
    if(hp<=0) {
        return false;
    }
    else return true;
}

void Actor::setHP(int hp) {
    this->hp=hp;
}
int Actor::getHP() const {
    return hp;
}

bool Actor::czyJestMana() const {
    if(mana<=0){
        return false;
    }
    else return true;

}


int Actor::getDmg() const {
    int randDMG = 0;
    randDMG = rand()%(maxDmg-minDmg+1)+minDmg;
    return randDMG;
}



int Actor::getDmgSpell() const {
    int randDMGspell = 0;
    randDMGspell = rand()%(maxDmgSpell-minDmgSpell+1)+minDmgSpell;
    return randDMGspell;
}

int Actor::getMana() const {
    return mana;
}

void Actor::setMana(int mana) {
    this->mana=mana;
}

Actor::Actor(const string& name, int hp, int mana, int minDmg, int maxDmg, int minDmgSpell, int maxDmgSpell)
	: name(name),hp(hp),mana(mana),minDmg(minDmg),maxDmg(maxDmg),minDmgSpell(minDmgSpell),maxDmgSpell(maxDmgSpell) {

}

void Actor::restart() {
    hp = 100;
    mana = 100;
}

const string Actor::operator*() const
{
    return name;
}

