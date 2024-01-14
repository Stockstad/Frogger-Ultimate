#include "Home.h"
#include "GameManager.h"

Home::Home(const std::string &FP, int X, int Y, int S) : GameObject(FP, X, Y, S) {
    ObjectSprite.setScale(0.08f, 0.08f);
    IsEmpty = true;
}

Home::~Home() = default;


void Home::update(const float dt) {

}

void Home::collided(GameObject *Other) {
    if (IsEmpty) {
        IsEmpty = false;
        Other->set_parented(true);
        Other->position.x = GameManager::WindowWidth / 2;
        Other->position.y = GameManager::WindowHeight - Other->GetSprite().getGlobalBounds().height;
        Other->GetSprite().setPosition(position);
        LoadTexture("Assets/HomeWFrog.png");
        GameManager::get_instance().play_at_home_sound();

        if (auto *P = dynamic_cast<Player*>(Other))
        {
            P->add_score(1);
        }
    } else {
        GameManager::get_instance().play_nope_sound();
    }
}




