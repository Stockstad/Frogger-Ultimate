#include <memory>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "GameState.h"
#include "GameManager.h"
#include "Player.h"
#include "Truck.h"
#include "Turtle.h"
#include "Home.h"
#include "Text.h"


sf::Time TargetFrameTime = sf::seconds(1.0f / 60.0f);
std::vector<std::unique_ptr<GameObject>> GameState::Objects = {};

GameState::GameState() = default;

GameState::~GameState() = default;

void GameState::update() {
    while (GameManager::Window.isOpen() && !GameManager::GameOver) {
        if (p->get_lives() == 0) {
            game_over();
            break;
        }

        if (p->get_score() == (5 * GameManager::get_current_level())) {
            //GameManager::CurrentLevel++;
            GameManager::set_current_level(GameManager::get_current_level() + 1);
            delete_game();
            init_game(GameManager::get_current_level());
        }
        sf::Time dt = Objects.at(0)->clock.getElapsedTime(); //Init dt with the first Object.

        if (dt < TargetFrameTime) {
            sf::sleep(TargetFrameTime - dt);
            dt = TargetFrameTime;
        }

        GameManager::Window.clear();
        text = Text::create_text(32, sf::Vector2f(20, 700), "Life: 0");
        ScoreText = Text::create_text(32, sf::Vector2f(850, 700), "Life: 0");
        LevelText = Text::create_text(32, sf::Vector2f(20, 50), "Level: 0");
        TimeText = Text::create_text(32, sf::Vector2f(750, 50), "Time Left: 0");

        text.setString("Lives: " + std::to_string(p->get_lives()));
        ScoreText.setString("Score: " + std::to_string(p->get_score()));
        LevelText.setString("Level: " + std::to_string(GameManager::get_current_level()));
        TimeText.setString("Time Left: " + std::to_string(static_cast<int>(GameState::get_time_left())));
        GameManager::Window.draw(River);

        for (auto &obj: Objects) {
            if (obj) {
                obj->draw();
                GameManager::check_collision();
                obj->update(dt.asSeconds());

            }
        }

        TimeLeft -= dt.asSeconds();
        if (TimeLeft <= 0) {
            game_over();
        }
        //GameManager::TimeLeft -= dt.asSeconds();
        GameManager::Window.draw(text);
        GameManager::Window.draw(ScoreText);
        GameManager::Window.draw(LevelText);
        GameManager::Window.draw(TimeText);
        GameManager::Window.display();
    }
}

float GameState::get_time_left() const {
    return TimeLeft;
}

void GameState::game_over() {


    if (p->get_score() > 0) {

        std::fstream fs;
        fs.open(GameManager::ScoresFile, std::ios::out | std::ios::app | std::ios::in);
        std::vector<int> ScoresVector;

        std::string myline;
        while (std::getline(fs, myline)) {
            int LineAsNum;
            LineAsNum = std::stoi(myline);
            ScoresVector.push_back(LineAsNum);
        }

        fs.close();

        ScoresVector.push_back(p->get_score());
        std::sort(ScoresVector.rbegin(), ScoresVector.rend());
        std::ofstream output;
        output.open(GameManager::ScoresFile, std::ios::trunc);
        for (auto &obj: ScoresVector) {

            std::string mystr = std::to_string(obj);
            output << mystr << std::endl;
        }
        output.close();


    }
    p->reset_score();
    delete_game();
    GameManager::create_exit_state();
    GameManager::update_state();

}


void GameState::init_game(const int LevelSelect) {

    sf::RectangleShape tex;
    River.setSize(sf::Vector2f(GameManager::WindowWidth, GameManager::WindowHeight / 2));
    River.setFillColor(sf::Color::Blue);
    GameManager::Window.setKeyRepeatEnabled(false);

    TimeLeft = 60.0f;

    switch (GameManager::get_current_level()) {

        case 1:
            create_turtle_lane(4, 128, 100, false);
            create_turtle_lane(4, 192, 125, true);
            create_turtle_lane(4, 256, 150, false);
            create_turtle_lane(4, 320, 175, true);

            create_truck_lane(4, 448, 150, false);
            create_truck_lane(2, 512, 175, true);
            create_truck_lane(2, 576, 125, false);
            create_truck_lane(2, 640, 100, true);

            create_home_lane();
            create_player();
            break;

        case 2:
            create_turtle_lane(2, 128, 200, false);
            create_turtle_lane(4, 192, 175, true);
            create_turtle_lane(2, 256, 150, false);
            create_turtle_lane(4, 320, 220, true);

            create_truck_lane(2, 448, 200, false);
            create_truck_lane(2, 512, 150, true);
            create_truck_lane(1, 576, 500, false);
            create_truck_lane(2, 640, 250, true);

            create_home_lane();
            create_player();

            break;

        case 3:
            create_turtle_lane(2, 128, 200, false);
            create_turtle_lane(2, 192, 175, true);
            create_turtle_lane(2, 256, 150, false);
            create_turtle_lane(4, 320, 220, true);

            create_truck_lane(2, 448, 200, false);
            create_truck_lane(4, 512, 300, true);
            create_truck_lane(2, 576, 600, false);
            create_truck_lane(2, 640, 250, true);

            create_home_lane();
            create_player();
            break;

        default:
            game_over();


    }


}

void GameState::delete_game() {
    Objects.clear();
}

void GameState::create_home_lane()  {
    std::string HomeImage = "Assets/HomeWOFrog.png";
    for (char i{0}; i != 5; i++) {
        Objects.push_back(std::make_unique<Home>(HomeImage, 120 + (180 * i), 0, 0));
    }


}

void GameState::create_player()  {
    p = new Player("Assets/frog.png", GameManager::WindowWidth / 2, GameManager::WindowHeight - 50, 0);
    Objects.push_back(std::unique_ptr<Player>(p));

}

void GameState::create_turtle_lane(const int N, const int Y, const int S, const bool R) {
    int Distance{GameManager::WindowWidth / N};

    for (int i{0}; i < GameManager::WindowWidth; i += Distance) {
        Objects.push_back(std::make_unique<Turtle>("Assets/turtle.png", i, Y, S, R));
    }


}

void GameState::create_truck_lane(const int N, const int Y, const int S, const bool R) {
    int Distance{GameManager::WindowWidth / N};

    for (int i{0}; i < GameManager::WindowWidth; i += Distance) {
        Objects.push_back(std::make_unique<Truck>("Assets/truck.png", i, Y, S, R));
    }


}


