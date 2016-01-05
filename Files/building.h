#ifndef __BUILDING_H__
#define __BUILDING_H__
#include "place.h"

class Player;

class Building:public Place {
  std::string block;                    //the monopoly block the building belongs to
  int tuition[6]; 			//the tuition of the building at different levels
public:
  /*
    dtor
  */
  ~Building();
  /*
    returns the owner of the property
  */
  Player* getOwner();
  /* 
    returns the monopoly block the blding belongs to
  */
  std::string getBlock();
  /*
    ctor
  */
  Building(std::string name,std::string block, int cost, int improveCost, int l0, int l1, int l2, int l3, int l4, int l5);
  /*
    returns the improvement cost
  */
  int getImproveCost();
  /*
    returns the level of the building
  */
  int getLevel();
  /*
    sets the level of the building
  */
  void setLevel(int lvl);
  /*
    returns the current tuition of the building
  */
  int getTuition();
  /*
    sets the owner of the building
  */
  void setOwner(Player*);
  /* 
    sets prev owner
  */
  void setPrevOwner(Player *);
  /*
    gets prev owner
  */
  Player* getPrevOwner();
};

#endif
