#include <fstream>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MenuState.h"
#include "ExitState.h"
#include "GameManager.h"



//float GameManager::TimeLeft = 30.0;
std::unique_ptr<State> GameManager::CurrentState;
sf::RenderWindow GameManager::Window;
std::string GameManager::ScoresFile;

bool GameManager::GameOver = false;
int GameManager::CurrentLevel = 1;


void GameManager::start() {
    Window.create(sf::VideoMode(WindowWidth, WindowHeight), "Frogger Lite");
    Window.setFramerateLimit(60);
    Window.setKeyRepeatEnabled(false);
    GameManager::ScoresFile = "scores.txt";
    create_menu_state();
    update_state();

}

void GameManager::update_state() {
    sf::Event event;
    while (Window.pollEvent(event)) {

        if (event.type == sf::Event::Closed) {
            Window.close();
            return;
        }
    }

    CurrentState->update();
}

void GameManager::create_game_state() {
    GameManager::get_instance().stop_menu_music();
    GameManager::get_instance().play_playing_music();
    CurrentState = std::make_unique<GameState>();
    CurrentState->init_game(CurrentLevel);


}

void GameManager::create_menu_state() {
    GameManager::get_instance().play_menu_music();
    CurrentState = std::make_unique<MenuState>();
}

void GameManager::create_exit_state() {
    set_current_level(1);
    GameManager::get_instance().stop_playing_music();
    CurrentState = std::make_unique<ExitState>();

}

void GameManager::check_collision() { //This approach has a complexity of N^2, but we think it's fine for this scale of project.
    for (auto it = GameState::Objects.begin(); it != GameState::Objects.end(); ++it) {
        for (auto jt = std::next(it); jt != GameState::Objects.end(); ++jt) {
            GameObject& ObjA = **it;
            GameObject& ObjB = **jt;

            if (ObjA.GetSprite().getGlobalBounds().intersects(ObjB.GetSprite().getGlobalBounds())) {
                ObjA.collided(&ObjB);
            }


        }
    }


}


SoundManager &GameManager::get_instance() {
    return SoundManager::get_instance();
}

int GameManager::get_current_level() {
    return CurrentLevel;
}

void GameManager::set_current_level(const int NewLevel) {
    CurrentLevel = NewLevel;
}

