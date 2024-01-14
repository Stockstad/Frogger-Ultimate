//
// Created by johto839 on 2023-12-06.
//

#ifndef FROGGER_MENUSTATE_H
#define FROGGER_MENUSTATE_H

#include "State.h"

/**
 * @class MenuState
 * @brief The menu state where selection is made.
 * Here the user can select different options like start and quit. The scoreboard is also displayed.
 */
class MenuState : public State {
public:
    MenuState();

    /**
     * @brief The state is updated and it handles user input.
     */
    void update() override;

    ~MenuState() override;

private:
    int MenuOptions{2};
    bool GameClosed{false};
};


#endif //FROGGER_MENUSTATE_H
