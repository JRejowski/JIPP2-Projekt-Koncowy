//
// Created by Yonasz on 23.01.2022.
//

#include <iostream>
#include <fstream>
#include "ScenaWalka.h"
#include "ScenaDialog.h"
#include "Actor.h"
#include "Game.h"

void Game::koniecGry() {
    cout<<"Gratulacje, udalo ci sie ukonczyc gre!\n";
}

Game::~Game()
{

    for (auto scena : sceny)
    {
        if(scena!=nullptr)
        delete scena;
    }
    if(player!=nullptr)
    delete player;
}

void Game::load() {

    player= new Actor("Student",100,100,10,30,40,50);

    ScenaDialog<string>* s1 = new ScenaDialog<string>;
    ScenaWalka* s2 = new ScenaWalka(player, "Tas", 50, 100, 5, 15, 10, 10);
    ScenaDialog<string>* s3 = new ScenaDialog<string>;
    ScenaWalka* s4 = new ScenaWalka(player,"Systemowy Olo", 70, 100, 10, 20, 10, 10);
    ScenaDialog<string>* s5 = new ScenaDialog<string>;
    ScenaWalka* s6 = new ScenaWalka(player,"TOmasz RUSak", 100, 100, 20, 25, 10, 10);
    ScenaDialog<string>* s7 = new ScenaDialog<string>;
    ScenaWalka* s8 = new ScenaWalka(player,"Krzysztof Jarzyna", 250, 100, 1, 5, 10, 10);
    ScenaDialog<string>* s9 = new ScenaDialog<string>;

    ifstream fp;
    fp.open("Sceny.txt");

    string linia;
    do
    {
        getline(fp,linia);
        s1->addLine(linia);
    } while (linia!="");
    do
    {
        getline(fp,linia);
        s3->addLine(linia);
    } while (linia!="");
    do
    {
        getline(fp,linia);
        s5->addLine(linia);
    } while (linia!="");
    do
    {
        getline(fp,linia);
        s7->addLine(linia);
    } while (linia!="");
    do
    {
        getline(fp,linia);
        s9->addLine(linia);
    } while (linia!="");

    sceny.push_back(s1);
    sceny.push_back(s2);
    sceny.push_back(s3);
    sceny.push_back(s4);
    sceny.push_back(s5);
    sceny.push_back(s6);
    sceny.push_back(s7);
    sceny.push_back(s8);
    sceny.push_back(s9);

    fp.close();
}

void Game::load(int param)
{
    if (param == 0)
    {
        player = new Actor("Student", 100, 100, 10, 30, 40, 50);
        
        ScenaWalka* s2 = new ScenaWalka(player, "Tas", 50, 100, 5, 15, 10, 10);
        ScenaWalka* s4 = new ScenaWalka(player, "Systemowy Olo", 70, 100, 10, 20, 10, 10);
        ScenaWalka* s6 = new ScenaWalka(player, "TOmasz RUSak", 100, 100, 20, 25, 10, 10);
        ScenaWalka* s8 = new ScenaWalka(player, "Krzysztof Jarzyna", 250, 100, 1, 5, 10, 10);

        sceny.push_back(s2);
        sceny.push_back(s4);
        sceny.push_back(s6);
        sceny.push_back(s8);
    }
    else
    {
        player = new Actor("Student", 100, 100, 10, 30, 40, 50);


		ScenaDialog<string>* s1 = new ScenaDialog<string>;
		ScenaDialog<string>* s3 = new ScenaDialog<string>;
		ScenaDialog<string>* s5 = new ScenaDialog<string>;
		ScenaDialog<string>* s7 = new ScenaDialog<string>;
		ScenaDialog<string>* s9 = new ScenaDialog<string>;

        ifstream fp;
        fp.open("Sceny.txt");
        string linia;
        do
        {
            getline(fp, linia);
            s1->addLine(linia);
        } while (linia != "");
        do
        {
            getline(fp, linia);
            s3->addLine(linia);
        } while (linia != "");
        do
        {
            getline(fp, linia);
            s5->addLine(linia);
        } while (linia != "");
        do
        {
            getline(fp, linia);
            s7->addLine(linia);
        } while (linia != "");
        do
        {
            getline(fp, linia);
            s9->addLine(linia);
        } while (linia != "");

        sceny.push_back(s1);
        sceny.push_back(s3);
        sceny.push_back(s5);
        sceny.push_back(s7);
        sceny.push_back(s9);

        fp.close();
    }
}

void Game::update() {

    int ktoraScena = 0;
	try {
		while(ktoraScena<sceny.size())
		{
			if(sceny[ktoraScena]->update()!= true)
			{
			 ktoraScena++;
			}

		}
	}
	catch (...) {
		// ded
		cout << "Zostales pokonany!" << endl;
	}
}

void Game::run() {

    update();
    koniecGry();
}
