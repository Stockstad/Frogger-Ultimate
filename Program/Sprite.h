#ifndef FROGGER_SPRITE_H
#define FROGGER_SPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * @class Sprite
 * @brief Handles Textures and Sprites for each object.
 *
 * Sprite is the base class for GameObject, and includes the relevant functions and variables to create sprites.
 */
class Sprite {
public:
    /**
     *
     * @param FilePath A file path to the texture.
     */
    explicit Sprite(const std::string &FilePath);

    ~Sprite() = default;

    sf::Sprite &GetSprite();


protected:
    /**
     * @brief The sprite's texture.
     */
    sf::Texture ObjectTexture;

/**
 * @brief Loads the texture from the filepath into the Sprite.
 * @param FilePath A file path to the texture.
 */
    void LoadTexture(const std::string &FilePath);

    /**
 * @brief The ObjectSprite saved in this variable.
 */
    sf::Sprite ObjectSprite;

};


#endif //FROGGER_SPRITE_H