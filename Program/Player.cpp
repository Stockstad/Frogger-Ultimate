#include "Player.h"
#include "GameManager.h"
#include "Turtle.h"
#include "Home.h"
#include <iostream>
#include "GameState.h"

int Player::Score{0};

Player::Player(const std::string &FP, const int X, const int Y, const int S) : GameObject(FP, X, Y, S) {

    ObjectSprite.setScale(0.07f, 0.07f);
}


void Player::update(const float dt) { //
    sf::Event event;
    while (GameManager::Window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            GameManager::get_instance().play_frog_jump_sound();
            float JumpDistance = 4096.f;

            if (event.key.code == sf::Keyboard::W) {
                change_position(0, -JumpDistance, dt);
            }
            if (event.key.code == sf::Keyboard::S) {
                change_position(0, JumpDistance, dt);
            }
            if (event.key.code == sf::Keyboard::D) {
                change_position(JumpDistance, 0, dt);
            }
            if (event.key.code == sf::Keyboard::A) {
                change_position(-JumpDistance, 0, dt);
            }
            validate_position();
        }
    }

    if (position.x > GameManager::WindowWidth || position.x < 0) {
        death();

    }


}

void Player::death() {
    GameManager::get_instance().play_frog_death_sound();
    position.x = GameManager::WindowWidth / 2;
    position.y = GameManager::WindowHeight - ObjectSprite.getGlobalBounds().height;
    ObjectSprite.setPosition(position);
    Lives--;

}

void Player::collided(GameObject *Other) {
    if (this == Other)
    {
        return;
    }
    death();

}




void Player::change_position(const float x, const float y, const float dt) {
    position.x += x * dt;
    position.y += y * dt;

    validate_position();
}

void Player::validate_position() {
    IsParented = false; //Set to false here to reset any changes given by another object.

    if (position.x < 0) {
        position.x = 0;
    }
    if (position.y < 0) {
        position.y = 0;
    }
    if (position.x > GameManager::WindowWidth - ObjectSprite.getGlobalBounds().width) {
        if (!IsParented) {
            position.x = GameManager::WindowWidth - ObjectSprite.getGlobalBounds().width;
        }

    }
    if (position.y > GameManager::WindowHeight - ObjectSprite.getGlobalBounds().height) {
        if (!IsParented) {
            position.y = GameManager::WindowHeight - ObjectSprite.getGlobalBounds().height;
        }

    }
    ObjectSprite.setPosition(position);

    if (position.y < (GameManager::WindowHeight / 2) - 50) {
        GameManager::check_collision();
        if (!IsParented) {
            death();
        }

    }


}




int Player::get_lives() const {
    return Lives;
}

int Player::get_score() const {
    return Score;
}

void Player::add_score(const int S) {
    Score += S;
}

void Player::reset_score() {
    Score = 0;
}


Player::~Player() = default;
