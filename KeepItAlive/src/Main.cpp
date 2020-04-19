#include "Game.h"

int main()
{
    Game* game = new Game();

    game->start();
    game->close();

    return 0;
}