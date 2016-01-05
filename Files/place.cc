#include "place.h"

using namespace std;


int Place::getRent() {return 0;}
string Place::getBlock() {return "";}
Player* Place::getOwner() {return NULL;}
void Place::setLevel(int lvl = 0) {level = lvl;}
int Place::getTuition() {return 0;}

Place::Place(string name, int cost, int lvl, int improvC): name(name), cost(cost), owner(NULL), prevOwner(NULL), improveCost(improvC), level(lvl) {}
int Place::getLevel() {
  return 0;
}
int Place::getImproveCost() {
  return improveCost;
}
string Place::getName() {
  return name;
}
int Place::getCost() {
  return cost;
}
Player* Place::getPrevOwner() {
  return prevOwner;
}
void Place::setPrevOwner(Player* p) {
  prevOwner = p;
}
void Place::setOwner(Player* p) {
  owner = p;
}
Place::~Place() {}
