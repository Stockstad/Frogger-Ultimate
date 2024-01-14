#ifndef FROGGER_HOME_H
#define FROGGER_HOME_H

#include "GameObject.h"
#include "Player.h"

/**
 * @class Home
 * @brief The Player's end goal.
 *
 * Handles creation, drawing and updating of the Homes. Also handles the special collision.
 */
class Home : public GameObject {
public:
/**
 *
 * @param FP File path for the texture.
 * @param X Position X.
 * @param Y Position Y.
 * @param S Speed. In most cases always 0.
 */
    Home(const std::string &FP, int X, int Y, int S = 0);

    ~Home() override;

    /**
     * @brief Updates the state of the Home.
     * @param dt Time since last frame update.
     */
    void update(float dt) override;
/**
 * @brief Handles a collision with said object.
 * @param Other The object that collided with it.
 */
    void collided(GameObject *Other) override;



private:
    bool IsEmpty;

};


#endif //FROGGER_HOME_H
