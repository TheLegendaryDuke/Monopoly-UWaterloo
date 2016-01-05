#include "building.h"
#include <iostream>

using namespace std;

Building::Building(string name, string block, int cost, int improveCost, int l0, int l1, int l2, int l3, int l4, int l5): Place(name, cost, 0, improveCost), block(block) {
  tuition[0] = l0;
  tuition[1] = l1;
  tuition[2] = l2;
  tuition[3] = l3;
  tuition[4] = l4;
  tuition[5] = l5;
}
Player* Building::getPrevOwner() {
  return prevOwner;
}
void Building::setPrevOwner(Player *p) {
  prevOwner = p;
}
Player* Building::getOwner() {
  return owner;
}
int Building::getTuition() {
  return tuition[level];
}
string Building::getBlock() {
  return block;
}
void Building::setLevel(int lvl) {
  if(lvl > 5 || lvl < 0) {
    cerr << "Invalid level, input an integer between 0 and 5" << endl;
  }
  level = lvl;
}
void Building::setOwner(Player *player) {
    owner = player;
}
int Building::getLevel() {
  return level;
}
Building::~Building() { 
  for (int i=0; i<6; i++) {
	tuition[i] = 0;
  } 
}
