#ifndef FROGGER_PLAYER_H
#define FROGGER_PLAYER_H

#include "GameObject.h"

/**
 * @class Player
 * @brief The Player of the game.
 *
 * Handles creation, rendering, and updating of the Player. Also handles user input and calls on collision functions from other subclasses to GameObject.
 */
class Player : public GameObject {
public:

/**
 *
 * @param FP A file path to a texture.
 * @param X Starting position X.
 * @param Y Starting position Y.
 * @param S Speed.
 */
    Player(const std::string &FP, int X, int Y, int S);

    ~Player() override;

    /**
     * @brief Handles user input and updates the player accordingly.
     * @param dt Time since last frame update.
     */
    void update(float dt) override;

    /**
     * @brief Handles the event when something collides with a player.
     * @param Other A pointer to the collided-with object.
     */
    void collided(GameObject *Other) override;

/**
 * @brief Handles the player's death.
 */
    void death() override;

    /**
    * @brief Handles player death.
    */

    int get_lives() const;

    int get_score() const;

    /**
     * @brief Adds score to the player.
     */
    void add_score(int S);

    void reset_score();

private:
    /**
     * @brief Changes the player's position.
     * @param x Position X.
     * @param y Position Y.
     * @param dt Time since last frame.
     */
    void change_position(float x, float y, float dt);



    /**
     * @brief Validates the player's position. If outside of map etc. it calls on Death().
     */
    void validate_position();


    static int Score;
    int Lives{3};


};


#endif //FROGGER_PLAYER_H
