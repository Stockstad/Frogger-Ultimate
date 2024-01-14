#include <iostream>
#include "SoundManager.h"



void SoundManager::play_menu_music()  {
    if (!MenuMusic.openFromFile("Assets/OrangeSunshine.ogg")) {
        std::cerr << "Failed to load music" << std::endl;
    } else {
        MenuMusic.play();
        std::cerr << "Loaded music" << std::endl;
    }
}


void SoundManager::stop_menu_music()  {
    MenuMusic.stop();
}

void SoundManager::play_playing_music() {
    if (!PlayingMusic.openFromFile("Assets/StationSound.ogg")) {
        std::cerr << "Failed to load music" << std::endl;
    } else {
        PlayingMusic.play();
        std::cerr << "Loaded music" << std::endl;
    }

}

void SoundManager::stop_playing_music() {
    PlayingMusic.stop();

}

SoundManager &SoundManager::get_instance()  {
    static SoundManager SM;
    return SM;
}

void SoundManager::play_frog_jump_sound()  {
    JumpBuffer.loadFromFile("Assets/FrogSound.wav");
    FrogJumpSound.setBuffer(JumpBuffer);
    FrogJumpSound.play();

}

void SoundManager::play_frog_death_sound()  {
    DeathBuffer.loadFromFile("Assets/FrogDeath.ogg");
    FrogDeathSound.setBuffer(DeathBuffer);
    FrogDeathSound.play();

}

void SoundManager::play_at_home_sound() {
    AtHomeBuffer.loadFromFile("Assets/Yay.wav");
    AtHomeSound.setBuffer(AtHomeBuffer);
    AtHomeSound.play();


}

void SoundManager::play_nope_sound() {
    NopeBuffer.loadFromFile("Assets/Nope.ogg");
    NopeSound.setBuffer(NopeBuffer);
    NopeSound.play();


}

