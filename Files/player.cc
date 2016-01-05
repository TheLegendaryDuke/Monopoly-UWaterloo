#include "player.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rurcup.h"

using namespace std;

Player::Player() {
  name = "";
  numCups = 0;
  numProperty = 0;
  numResidence = 0;
  numGym = 0;
  this->property = NULL;
  money = 1500;
  inTims = false;
  turnsInTims = 0;
  cups = new RURCup*[4];
  for (int i=0; i<4; i++) {
	cups[i] = NULL;
  }
}

Player::~Player() {
  for(int i = 0; i < 4; i++) {
    if(cups[i]) {
      delete cups[i];
    }
  }
  delete[] property;
  delete[] cups;
}



int Player::getNumCups() {
  return numCups;
}



RURCup* Player::useCup() {
  if(cups[numCups - 1]) {
    numCups--;
    RURCup* cup = cups[numCups];
    cups[numCups] = NULL;
    return cup;
  }else {
    return NULL;
  }
}



void Player::removeProperty(Place* p, string type) {
  bool found = false;
  for(int i = 0; i < numProperty; i++) {
    if(property[i] == p) {
      found = true;
    }
    if(found && i < numProperty - 1) {
      property[i] = property[i + 1];
    }
  }
  if(found) {
    numProperty--;
  }
  if(found && type == "residence") {
    numResidence--;
  }
  if(found && type == "gym") {
    numGym--;
  }
  Place **temp = new Place*[numProperty];
  for(int i = 0; i < numProperty; i++) {
    temp[i] = property[i];
  }
  delete[] property;
  property = temp;
}



bool Player::gainCup() {
  RURCup* cup = RURCup::getCup();
  if(cup) {
    cups[numCups] = cup;
    numCups++;
    return true;
  }
  return false;
}



void Player::setName(string n) {
  this->name = n;
}



void Player::setMoney(int amount) {
  this->money = amount;
}



string Player::getName() {
  return this->name;
}



void Player::addProperty(Place *properties, string type = "") {
  Place **temp = new Place*[numProperty + 1];
  for(int i = 0; i < numProperty; i++) {
    temp[i] = property[i];
  }
  delete[] property;
  property = temp;
  property[numProperty] = properties;
  numProperty++;
  if (type == "residence") numResidence++;
  if (type == "gym") numGym++;
}



Place** Player::allProperty() {
  return this->property;
}



int Player::getMoney() {
  return this->money;
}


string Player::getProperty() {
  string propertyList;
  int i=0;
  while(numProperty != 0) {
	propertyList.append(this->property[i]->getName());
	i++;
	if(i >= numProperty) break;
	propertyList.append("\n");
  }

  return propertyList;
}


int Player::getNumProperty() {
  return this->numProperty;
}


int Player::getNumResidence() {
  return this->numResidence;
}


int Player::getNumGym() {
  return this->numGym;
}


void Player::goToTims() {
  this->inTims = true;
  this->turnsInTims = 1;
}


bool Player::isInTims() {
  return inTims;
}


int Player::getTurns() {
  return turnsInTims;
}


void Player::stall() {
  if (inTims) this->turnsInTims++;
}


void Player::getOutTims() {
  this->inTims = false;
  this->turnsInTims = 0;
}
