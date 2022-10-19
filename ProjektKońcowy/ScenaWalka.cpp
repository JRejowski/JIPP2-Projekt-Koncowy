//
// Created by Yonasz on 22.01.2022.
//

#include <iostream>
#include "ScenaWalka.h"
#include "Actor.h"

void ScenaWalka::drukujStaty() const {
    cout<<*(*player)<<"\t\t\t"<<*(*enemy)<<endl;
    cout<<"Zycie: "<<player->getHP()<<"\t\t"<<"Zycie: "<<enemy->getHP()<<endl;
    cout<<"Mana:  "<<player->getMana()<<"\t\t"<<"Mana:  "<<enemy->getMana()<<endl;
}

void ScenaWalka::drukujRaport() const {
    cout<<"Zadales przeciwnikowi "<<lastPlayerDmg<<" obrazen!\n";
    cout<<"Przeciwnik zadal tobie "<<lastEnemyDmg<<" obrazen!\n";
}

DamageType ScenaWalka::drukujOpcje() const {
    int x=0;
    cout<<"Co chcesz zrobic?\n";
    cout<<"1.Atak fizyczny\n";
    cout<<"2.Atak magiczny\n";
    cin>>x;
	return x == 1 ? DamageType::Physical : DamageType::Magical;
}

bool ScenaWalka::walka(const DamageType i) {

    const int x = player->getHP();
    const int y = enemy->getHP();

    if(i == DamageType::Physical) 
	{
        lastPlayerDmg = player->getDmg();
        enemy->setHP(y-lastPlayerDmg);
		if (enemy->czyZyje() == false)
        {
            drukujStaty();
            cout<<"Zadales przeciwnikowi "<<lastPlayerDmg<<" obrazen!\n";
            cout<<"Przeciwnik pokonany!"<<endl;
            player->restart();
            return false;
        }
    }
    if(i == DamageType::Magical)
    {

		if (player->czyJestMana() == true)
        {
            lastPlayerDmg = player->getDmgSpell();
            enemy->setHP(y - lastPlayerDmg);
            player->setMana(player->getMana()-50);
        }
        else
        {
            cout<<"Nie masz many! Uzywasz ataku fizycznego!\n";
            lastPlayerDmg = player->getDmg();
            enemy->setHP(y - lastPlayerDmg);
        }

		if (enemy->czyZyje() == false)
        {
            drukujStaty();
            cout<<"Zadales przeciwnikowi "<<lastPlayerDmg<<" obrazen!\n";
            cout<<"Przeciwnik pokonany!"<<endl;
            player->restart();
            return false;
        }
    }
	lastEnemyDmg = enemy->getDmg();
	player->setHP(x - lastEnemyDmg);
	if (player->czyZyje() == false)
	{
		drukujStaty();
		drukujRaport();
		throw 1;
		return false;
	}
    return true;


}


bool ScenaWalka::update() {
    drukujStaty();
    if (numerTury > 1) drukujRaport();
    DamageType x = drukujOpcje();
    numerTury++;
    if(!walka(x)) return false;
    else return true;
}

ScenaWalka::ScenaWalka(Actor *p, string name, int hp, int mana, int minDmg, int maxDmg, int minDmgSpell, int maxDmgSpell) {
    this->player=p;
    enemy = new Actor(name, hp, mana, minDmg, maxDmg, minDmgSpell, maxDmgSpell);
}

ScenaWalka::~ScenaWalka()
{
    delete enemy;
}



