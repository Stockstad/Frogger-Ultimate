#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "GameManager.h"
#include "MenuState.h"
#include "Text.h"


MenuState::MenuState() = default;

bool UIController{true};
sf::Text Selector;
std::vector<std::string> Scores;




void MenuState::update() {
    while (!GameClosed) {
        GameManager::Window.clear();

        sf::Text Title = Text::create_text(96, sf::Vector2f(GameManager::WindowWidth / 2, 100), "Frogger Ultimate");
        sf::Text StartGame = Text::create_text(32, sf::Vector2f(GameManager::WindowWidth / 2, 400), "Start Game");
        sf::Text QuitGame = Text::create_text(32, sf::Vector2f(GameManager::WindowWidth / 2, 500), "Quit Game");
        Selector = Text::create_text(32, sf::Vector2f(GameManager::WindowWidth / 2, 100), ">>                       <<");
        Selector.setPosition(GameManager::WindowWidth / 2, 500 - (UIController * 100));

        sf::FloatRect TitleRect = Title.getLocalBounds();
        sf::FloatRect StartRect = StartGame.getLocalBounds();
        //sf::FloatRect ScoreRect = HighScores.getLocalBounds();
        sf::FloatRect QuitRect = QuitGame.getLocalBounds();
        sf::FloatRect SelectRect = Selector.getLocalBounds();

        Title.setOrigin(TitleRect.left + TitleRect.width / 2.0f, TitleRect.top + TitleRect.height / 2.0f);
        StartGame.setOrigin(StartRect.left + StartRect.width / 2.0f, StartRect.top + StartRect.height / 2.0f);
        QuitGame.setOrigin(QuitRect.left + QuitRect.width / 2.0f, QuitRect.top + QuitRect.height / 2.0f);
        Selector.setOrigin(SelectRect.left + SelectRect.width / 2.0f, SelectRect.top + SelectRect.height / 2.0f);

        GameManager::Window.draw(Title);
        GameManager::Window.draw(StartGame);
        GameManager::Window.draw(QuitGame);
        GameManager::Window.draw(Selector);

        std::ifstream ifs;


        ifs.open(GameManager::ScoresFile);
        if (ifs.is_open()) {
            std::string templine;
            int line_count{0};
            while (getline(ifs, templine)) {
                Scores.push_back(templine);
                ++line_count;
            }
            line_count = std::min(5, line_count); // Make sure we only display 5 at most.
            for (size_t i{0}; i != line_count; i++) {
                sf::Text ScoreHolder = Text::create_text(24, sf::Vector2f(GameManager::WindowWidth / 8, 300 + 50 * i),
                                                        Scores[i]);
                GameManager::Window.draw(ScoreHolder);
            }

        }
        GameManager::Window.display();

        sf::Event event;
        while (GameManager::Window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    UIController = !UIController;
                }
                if (event.key.code == sf::Keyboard::W) {
                    UIController = !UIController;
                }

                if (event.key.code == sf::Keyboard::Enter) {
                    if (UIController) {
                        // Start Game selected
                        GameManager::create_game_state();
                        GameManager::update_state();
                        break;
                    } else {
                        // Quit Game selected
                        GameClosed = true;
                        std::exit(0);
                    }
                }
            }
        }
    }
}


MenuState::~MenuState() = default;


