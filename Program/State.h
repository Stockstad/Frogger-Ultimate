#ifndef FROGGER_STATE_H
#define FROGGER_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/**
 * @class State
 * @brief Base class for the states.
 *
 * Handles what kind of state the Game is in. Controlled by GameManager. A pointer to a state is saved in GameManager.
 */
class State {
public:
    virtual void update() = 0;

    /**
     * @brief Generates a vector for a game with the given level.
     * @param LevelSelect A selection for a level. If level doesn't exist, ends the game.
     * If called from other instance than from a GameState, nothing happens.
     */
    virtual void init_game(int LevelSelect);

    virtual ~State() = 0;


};


#endif //FROGGER_STATE_H
