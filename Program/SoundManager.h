//
// Created by linus on 2023-12-07.
//

#ifndef FROGGER_SOUNDMANAGER_H
#define FROGGER_SOUNDMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

/**
 * @class SoundManager
 * @brief Handles sound in the game.
 *
 * Built around the singleton design pattern. Allows only one instance of the class via the GetInstance() function.
 */
class SoundManager {

public:

    void play_menu_music();

    void stop_menu_music();

    void play_playing_music();

    void stop_playing_music();

    void play_frog_jump_sound();

    void play_frog_death_sound();

    void play_at_home_sound();

    void play_nope_sound();

    /**
     * @brief Creates an instance of the SoundManager class.
     * @returns Returns a reference to an instance of the SoundManager.
     */
    static SoundManager &get_instance();

private:
    sf::Sound FrogJumpSound;
    sf::Sound FrogDeathSound;
    sf::Sound AtHomeSound;
    sf::Sound NopeSound;
    sf::Music MenuMusic;
    sf::Music PlayingMusic;
    sf::SoundBuffer JumpBuffer;
    sf::SoundBuffer DeathBuffer;
    sf::SoundBuffer AtHomeBuffer;
    sf::SoundBuffer NopeBuffer;

    SoundManager() = default;

    ~SoundManager() = default;

};


#endif //FROGGER_SOUNDMANAGER_H
