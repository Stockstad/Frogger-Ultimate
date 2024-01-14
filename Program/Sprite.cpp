#include <iostream>
#include "Sprite.h"
Sprite::Sprite(const std::string &FilePath) {
    LoadTexture(FilePath);
}

/** @brief Loads a texture and sets the associated sprite with that texture.
* @param FilePath A file path to the texutre.
* @return returns nothing.
*/
void Sprite::LoadTexture(const std::string &FilePath) {
    if (!ObjectTexture.loadFromFile(FilePath)) {
        std::cout << "Failed loading texture of type " << FilePath << std::endl;
    }
    ObjectSprite.setTexture(ObjectTexture);


}

sf::Sprite &Sprite::GetSprite() {
    return ObjectSprite;
}




