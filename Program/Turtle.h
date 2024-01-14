#ifndef FROGGER_Turtle_H
#define FROGGER_Turtle_H

#include "GameObject.h"
#include "Player.h"

/**
 * @class Turtle
 * @brief An object the player can stand on in the river.
 *
 * The turtle is the object that is in the river. It gives the player a safe space to stay on but it moves together with the player.
 */
class Turtle : public GameObject {
public:
/**
 *
 * @param FP A File Path to the texture.
 * @param X Position X.
 * @param Y Position Y.
 * @param S Speed.
 * @param R Reversed. If set to true the turtle swims from right to left.
 */
    Turtle(const std::string &FP, int X, int Y, int S, bool R);

    ~Turtle() override;

    /**
 * @brief Updates the state of the Turtle.
 * @param dt Time since last frame update.
 */
    void update(float dt) override;

    /**
     * @brief Handles the event of collision with a turtle.
     * @param Other The object it collided with.
     */
    void collided(GameObject *Other) override;


private:
    bool Reversed;



};


#endif //FROGGER_Turtle_H
