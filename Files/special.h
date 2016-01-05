#ifndef __SPECIAL_H__
#define __SPECIAL_H__
#include "place.h"

class Special:public Place {
  public:
  ~Special(); //dtor
  int getCost(); //cost's accessor(returns 0)
  Special(std::string name);// ctor
  void setOwner(Player*);// sets the owner of the place(does nothing)
};

#endif
