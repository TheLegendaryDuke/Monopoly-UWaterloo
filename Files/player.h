#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "rurcup.h"
#include <string>
#include "place.h"

class Player {
  std::string name;			//name of player
  int numProperty;			//how many properties the player has
  int numResidence;			//how many residences the player has
  int numGym;				//how many gyms the player has
  Place **property;			//player's properties
  int money;				//player's money
  bool inTims;				//is player in DC Tims Line
  int turnsInTims;			//turns in DC Tims Line
  RURCup **cups;                        //all the cups the player owns
  int numCups;                          //numer of cups the player owns

  public:
	Player();			//default constructor
	~Player();			//destructor

        /*
          gives the player one more cup
        */
        bool gainCup();
        /*
          removes a property
        */
        void removeProperty(Place* p, std::string type);
        /*
          returns the number of cups the player has
        */
        int getNumCups();
        /*
          returns a cup pointer to count as the player used a cup
        */
        RURCup* useCup();
	/*
	* Set the name of player
	*/
	void setName(std::string name);
	/*
	* Set the amount of money the player has
	*/
	void setMoney(int amount);
	/*
	* Set the properties the player has
	*/
	void addProperty(Place *properties, std::string type);
	/*
	* Get a list of properties the player has
	*/
	Place** allProperty();
	/*
	* Get the amount of money the player has
	*/
	int getMoney();
	/*
	* Get all the properties the player has
	*/
	std::string getProperty();
	/*
	* Get how many properties the player has
	*/
	int getNumProperty();
	/*
	* Get how many residences the player has
	*/
	int getNumResidence();
	/*
	* Get how many gyms the player has
	*/
	int getNumGym();
	/*
	* The player is in DC Tims Line
	*/
	void goToTims();
	/*
	* Count how many turns the player has been in DC Tims Line
	*/
	void stall();
	/*
	* Return true if the player is in DC Tims Line
	*/
	bool isInTims();
	/*
	* Get the number of turns the player have been in DC Tims Line
	*/
	int getTurns();
	/*
	* The player has got out from DC Tims Line
	*/
	void getOutTims();
        /*
          return the name of the player
        */
        std::string getName();
};

#endif
