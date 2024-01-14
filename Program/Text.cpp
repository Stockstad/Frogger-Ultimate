#include <iostream>
#include "Text.h"

sf::Font Text::MyFont;

sf::Text Text::create_text(int const &CharSize, sf::Vector2f const &pos, std::string const &StrText) {
    sf::Text MyText;
    //sf::Font MyFont;

    if (!Text::MyFont.loadFromFile("Raleway-Regular.ttf")) {
        std::cerr << "Couldn't load font file" << std::endl;
    }
    MyText.setStyle(sf::Text::Bold);
    MyText.setFont(Text::MyFont);
    MyText.setCharacterSize(CharSize);
    MyText.setString(StrText);
    MyText.setPosition(pos);

    return MyText;

}
