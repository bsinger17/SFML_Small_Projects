#include "Game.h"


int main()
{

    //initialize srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game myGame;


    while (myGame.running())
    {

        //update
        myGame.update();

        //render
        myGame.render();
    }

    return 0;
}