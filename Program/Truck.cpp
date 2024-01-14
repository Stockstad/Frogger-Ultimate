#include "Truck.h"
#include "GameManager.h"



Truck::Truck(const std::string &FP, const int X, const int Y, const int S, const bool R) : GameObject(FP, X, Y, S),
                                                                                           Reversed(R) {

    ObjectSprite.setScale(0.09f, 0.09f);
    if (Reversed) {
        ObjectSprite.setScale(-0.09f, 0.09f);
    }

}


void Truck::update(const float dt) {
    if (Reversed) {
        if (ObjectSprite.getPosition().x < 0 - ObjectSprite.getGlobalBounds().width / 2) {
            ObjectSprite.setPosition(GameManager::WindowWidth + ObjectSprite.getGlobalBounds().width / 2,
                                     ObjectSprite.getPosition().y);
        } else {
            ObjectSprite.move(-Speed * dt, 0);
        }
    } else {
        if (ObjectSprite.getPosition().x > GameManager::WindowWidth + ObjectSprite.getGlobalBounds().width / 2) {
            ObjectSprite.setPosition(0 - ObjectSprite.getGlobalBounds().width / 2, ObjectSprite.getPosition().y);
        } else {
            ObjectSprite.move(Speed * dt, 0);
        }
    }
    clock.restart();

}


Truck::~Truck() = default;

