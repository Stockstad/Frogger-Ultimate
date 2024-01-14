#include <iostream>
#include "GameManager.h"
#include "GameObject.h"

GameObject::GameObject(const std::string &filePath, int X, int Y, int S) : Sprite(filePath), PosX(X), PosY(Y),
                                                                           Speed(S) {
    position.x = X;
    position.y = Y;
    ObjectSprite.setPosition(position);
    LoadTexture(filePath);
}


GameObject::~GameObject() = default;

void GameObject::draw() const {
    GameManager::Window.draw(ObjectSprite);
}

void GameObject::death() {
    //Nothing happens. Implement in subclass if desired.

}

void GameObject::collided(GameObject *Other) {

    Other->death();
}

void GameObject::set_parented(bool setter) {
    IsParented = setter;

}






