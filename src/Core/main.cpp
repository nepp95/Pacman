#include "Core/Game.h"

int main(int argc, char *argv[])
{
    // Create a game instance
    auto game = new Game();

    // Run the game
    game->Run();

    // Cleanup after ourselves
    delete game;

    // And we're done!
    return 0;
}