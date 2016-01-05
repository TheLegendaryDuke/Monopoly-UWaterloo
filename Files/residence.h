#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include "place.h"

class Residence:public Place {
  int rent; // base rent of the place
public:
  /*
    dtor
  */
  ~Residence();
  /*
    ctor
  */
  Residence(std::string name, int cost, int rent);
  /*
    returns the base rent of the rez
  */
  int getRent();
  /*
    returns the owner of the rez
  */
  Player *getOwner();
  /*
    sets the owner of the rez
  */
  void setOwner(Player *player);
};

#endif
