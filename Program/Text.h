#ifndef FROGGER_TEXT_H
#define FROGGER_TEXT_H

#include <string>
#include "SFML/Graphics.hpp"

/**
 * @class Text
 * @brief Handles labels in the game.
 */
class Text {
public:
    static sf::Text create_text(int const &CharSize, sf::Vector2f const &pos, std::string const &StrText);

private:
    static sf::Font MyFont;
    std::string FontName;
    std::string DesiredText;


};


#endif //FROGGER_TEXT_H
