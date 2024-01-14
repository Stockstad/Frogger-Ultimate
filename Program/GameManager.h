#ifndef FROGGER_GAMEMANAGER_H
#define FROGGER_GAMEMANAGER_H
#include <vector>
#include <memory>
#include "GameObject.h"
#include "State.h"
#include "SoundManager.h"

/**
 * @class GameManager
 * @brief The overarching superclass of the game.
 *
 * Creates the game and keeps track of a few global, static variables. Also handles the update of States.
 */
class GameManager {
public:
    static const int WindowWidth{1024};
    static const int WindowHeight{768};
    /**
     * @brief The window in which the game is rendered.
     */
    static sf::RenderWindow Window;
    /**
     * @brief File path to the file where scores are saved.
     */
    static std::string ScoresFile;
    static bool GameOver;

    GameManager() = delete;

    /**
     * @brief Called when starting the program. Calls on MenuState and UpdateState.
     */
    static void start();

    /**
     * @brief Renders the CurrentState.
     */
    static void update_state();

    static void create_game_state();

    static void create_menu_state();

    static void create_exit_state();

    static void check_collision();

    /**
     * @brief Gets a SoundManager instance (singleton
     * @return A reference to a static instance of SoundManager
     */
    static SoundManager &get_instance();

    static int get_current_level();

    static void set_current_level(int NewLevel);

private:
    static int CurrentLevel;
    static std::unique_ptr<State> CurrentState;

};


#endif //FROGGER_GAMEMANAGER_H
