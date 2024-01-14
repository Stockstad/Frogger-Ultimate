#ifndef FROGGER_TRUCK_H
#define FROGGER_TRUCK_H

#include "GameObject.h"

/**
 * @class Truck
 * @brief The object that is on the road.
 *
 * The main object on the road. If the player collides with one they die.
 */
class Truck : public GameObject {
public:
/**
 *
 * @param FP A File path to the texture.
 * @param X Starting position X.
 * @param Y Position Y.
 * @param S Speed.
 * @param R If set to true, the truck goes from right to left.
 */
    Truck(const std::string &FP, int X, int Y, int S, bool R);

    ~Truck() override;

    /**
     * @brief Updates the state of the truck.
     * @param dt Time since last frame update.
     */
    void update(float dt) override;


private:
    bool Reversed;


};


#endif //FROGGER_TRUCK_H
