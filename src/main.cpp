#include "Globals.hpp"
#include "game/Game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // load default font
    Globals::Text::loadFonts();

    Game& game { Game::getGame() };
    game.start();

    return EXIT_SUCCESS;
}
