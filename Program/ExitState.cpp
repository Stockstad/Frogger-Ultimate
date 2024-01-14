#include "ExitState.h"
#include "GameManager.h"
#include "Text.h"

ExitState::ExitState() = default;


void ExitState::update() {
    bool GameEnded = false;
    while (!GameEnded) {
        GameManager::Window.clear();

        sf::Text GameOver = Text::create_text(32, sf::Vector2f(GameManager::WindowWidth / 2, 100), "GAME OVER");
        GameManager::Window.draw(GameOver);

        GameManager::Window.display();

        sf::Event event;
        while (GameManager::Window.pollEvent(event)) {
            if (event.type == event.KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    GameManager::create_menu_state();
                    GameManager::update_state();
                    GameEnded = true;


                }
            }
        }

    }
}


ExitState::~ExitState() = default;
