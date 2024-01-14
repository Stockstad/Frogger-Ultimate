#include "Turtle.h"
#include "GameManager.h"
#include <iostream>


Turtle::Turtle(const std::string &FP, const int X, const int Y, const int S, const bool R) : GameObject(FP, X, Y, S),
                                                                                             Reversed(R) {
    ObjectSprite.setScale(0.06f, 0.06f);
    if (Reversed) {
        ObjectSprite.setScale(-0.06f, 0.06f);
    }


}


void Turtle::update(const float dt) {
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

void Turtle::collided(GameObject *Other) {
    Other->set_parented(true);
    sf::Vector2f TurtlePosition = ObjectSprite.getPosition();
    sf::Vector2f TurtleScale = ObjectSprite.getScale();

    sf::FloatRect TurtleBounds(TurtlePosition.x - 0.5f * TurtleScale.x * ObjectSprite.getLocalBounds().width,
                               TurtlePosition.y - 0.5f * TurtleScale.y * ObjectSprite.getLocalBounds().height,
                               TurtleScale.x * ObjectSprite.getLocalBounds().width,
                               TurtleScale.y * ObjectSprite.getLocalBounds().height);

    sf::FloatRect PlayerBounds = Other->GetSprite().getGlobalBounds();

    sf::Vector2f playerOffset(0.5f * (TurtleBounds.width - PlayerBounds.width),
                              0.5f * (TurtleBounds.height - PlayerBounds.height));

    Other->GetSprite().setPosition(TurtlePosition + playerOffset);
    Other->position.x = TurtlePosition.x + playerOffset.x;
    Other->position.y = TurtlePosition.y + playerOffset.y;


}



Turtle::~Turtle() = default;
