#include "residence.h"

using namespace std;

Residence::Residence(string name, int cost, int rent): Place(name, cost, 0, 0), rent(rent) {}
void Residence::setOwner(Player *player) {
  owner = player;
}
Player* Residence::getOwner() {
  return owner;
}
int Residence::getRent() {
  return rent;
}
Residence::~Residence(){}
