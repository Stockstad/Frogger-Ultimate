#ifndef FROGGER_GAMESTATE_H
#define FROGGER_GAMESTATE_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameObject.h"
#include "Player.h"

/**
 * @class GameState
 * @brief Handles the playing part of the game
 *
 * Controls the flow of objects, and keeps track of time, score and everything gameplay related.
 */
class GameState : public State {

public:
    GameState();

    ~GameState() override;

    /**
     * @brief Controls the main game loop and updates all objects accordingly.
     * Calls all objects Update() function and Draw() function.
     */
    void update() override;

    /**
     * @brief Vector containing the GameObjects. Public so it can be accessed by different objects for collision checking.
     */
    static std::vector<std::unique_ptr<GameObject>> Objects;

    /**
     * @brief Generates a new vector of objects depending on the level
     * @param LevelSelect The level to create. If level doesn't exists, calls GameOver().
     */
    void init_game(int LevelSelect) override;

    /**
     * @brief Returns the time left according to the clock.
     * @return The time left in seconds before time runs out.
     */
    float get_time_left() const;

    /**
     * @brief Ends the game and therefor clears the vector of objects and goes to ExitState. Also saves score.
     */
    void game_over();

private:
    sf::Time dt;
    Player *p{nullptr};
    sf::RectangleShape River;
    sf::Text text;
    sf::Text ScoreText;
    sf::Text LevelText;
    sf::Text TimeText;

    float TimeLeft{60.0f};

    static void delete_game();

    static void create_home_lane();

    void create_player();

    static void create_turtle_lane(int N, int Y, int S, bool R);

    static void create_truck_lane(int N, int Y, int S, bool R);
};

#endif // FROGGER_GAMESTATE_H