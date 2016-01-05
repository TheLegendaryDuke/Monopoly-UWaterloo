#include "gym.h"
#include <iostream>

using namespace std;

Gym::~Gym() {}
Player* Gym::getOwner() {
  return owner;
}
void Gym::setOwner(Player *player) {
    owner = player;
}
Gym::Gym(string name, int cost):Place(name, cost, 0, 0) {}

