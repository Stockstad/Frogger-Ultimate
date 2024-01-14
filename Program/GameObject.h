#ifndef FROGGER_GAMEOBJECT_H
#define FROGGER_GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sprite.h"

/**
 * @class GameObject
 * @brief Base for Objects.
 *
 * Each object in the game is a subclass of GameObject.
 */
class GameObject : public Sprite {
public:

    GameObject(const std::string &filePath, int X, int Y, int S);

    virtual ~GameObject() = 0;

    virtual void update(float dt) = 0;

    /**
     * @brief Signals to an object that it should die.
     * By default, nothing happens. This logic can be implemented in a subclass.
     */
    virtual void death();

    /**s
     * @brief Call to be invoked when collision is detected.
     * @param Other The object which the current object collided with.
     * By default it calls the death-function of Other.
     */
    virtual void collided(GameObject *Other);

    /**
     * @brief Draws the object to the screen.
     *
     */
    void draw() const;

    /**
     * @breif Sets state for IsParented.
     * @param setter What to set to.
     */
    void set_parented(bool setter);



    /**
     * @brief Holds the time between last frame update.
     */
    sf::Clock clock;
    /**
     * @brief Position of the object.
     */
    sf::Vector2f position;




protected:
    int PosX;
    int PosY;
    int Speed;
    bool IsParented{};


};


#endif //FROGGER_GAMEOBJECT_H
