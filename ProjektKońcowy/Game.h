//
// Created by Yonasz on 23.01.2022.
//

#ifndef JIPP2_GAME_H
#define JIPP2_GAME_H

#include <vector>


using namespace std;

class Actor;
class Scena;

class Game {
public:

    /**
     * Function to run the entire game
     */
    void run();
    /**
     * function to load the contents of every scene
     */
    void load();
    /**
     * function to load the contents of every scene
     * @param param - is a program's starting parameter (if 1 then skips fights, if 0 skips dialogs)
     */
    void load(int param);
    /**
     * function to update susbequent scenes
     */
    void update();
    /**
     * function that congratulates player when player finishes game
     */
    void koniecGry();
    /**
     * destructor - frees the memory
     */
    ~Game();
private:

    Actor* player;
    vector<Scena*> sceny;


};

#endif //JIPP2_GAME_H
