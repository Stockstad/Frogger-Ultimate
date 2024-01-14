#ifndef FROGGER_EXITSTATE_H
#define FROGGER_EXITSTATE_H

#include "State.h"

/**
 * @class ExitState
 * @brief Handles the closure of a game.
 * When a player dies or when they complete all levels. Exit state is ran.
 */
class ExitState : public State {
public:
    ExitState();

    /**
     * @brief Updates the state. I.e. displays it and handles user input.
     */
    void update() override;

    ~ExitState() override;
};


#endif //FROGGER_EXITSTATE_H
