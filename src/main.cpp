#include "game/Game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // load default font
    // if (!Globals::DEFAULT_FONT.loadFromFile("OpenSans.ttf"))
    // {
    //     std::cerr << "Couldn't load font\n";
    //     return EXIT_FAILURE;
    // }

    Game& game { Game::getGame() };
    game.start();

    return EXIT_SUCCESS;
}
