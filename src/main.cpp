#include "game/Game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // load default font
    Globals::Text::loadFont(Globals::Text::DEFAULT_FONT, "src/assets/OpenSans.ttf");
    Globals::Text::loadFont(Globals::Text::DEFAULT_FONT_ITALIC, "src/assets/OpenSansItalic.ttf");


    Game& game { Game::getGame() };
    game.start();

    return EXIT_SUCCESS;
}
