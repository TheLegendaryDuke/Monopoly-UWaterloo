#ifndef __GYM_H__
#define __GYM_H__
#include "place.h"

class Player;
class Gym:public Place {
public:
  /*
    dtor
  */
  ~Gym();
  /*
    returns the owner of the place
  */
  Player* getOwner();
  /*
    return the name of the place
  */
  void setOwner(Player*);
  /*
    ctor
  */
  Gym(std::string name, int cost);
};
#endif
