#ifndef __PLACE_H__
#define __PLACE_H__
#include <string>

class Player;

class Place {
  std::string name; //name of the place
  int cost; //cost of that place, -1 if unbuyable
  int improveCost;// cost of improving the property
protected:
  int level;// level of the property
  Player *prevOwner;// previous owner of the property(before mortgaged)
  Player *owner;//owner of the property, NULL if bank
public:
  virtual ~Place();
  /*
    For Building use only:
    the accessors of the property
  */
  virtual std::string getBlock(); 
  virtual int getRent();
  virtual Player* getOwner();
  virtual void setLevel(int);
  virtual int getTuition();
  /*
    sets the prev owner
  */
  virtual void setPrevOwner(Player*);
  /*
    returns previous owner of the place (before morted)
  */
  virtual Player *getPrevOwner();
  /*
    returns the level of the place, 0 if NA
  */
  virtual int getLevel();
  /*
    returns the improve cost of the building, 0 if NA
  */
  int getImproveCost();
  /* 
    ctor
  */
  Place(std::string,int, int, int);
  /*
    name gettor
  */
  std::string getName();
  /*
    cost gettor
  */
  virtual int getCost();
  /*
    get the owner of the place
  */
  virtual void setOwner(Player*);
};

#endif
