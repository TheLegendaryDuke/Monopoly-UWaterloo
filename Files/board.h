#ifndef __BOARD_H__
#define __BOARD_H__
#include <string>

class Place;
class Player;
class Controller;

class Board {
  Place* campus[40];		//campus board
  int numPlayer;		//numbers of players in the game
  Player **players;		//list of all players
  int *playerPlaces;		//the current place of all players
  int currentPlayer;		//index of player in current turn
  int nextPlayer;		//index of player in next turn
  Controller *cl;		//the controller
  bool anyLoss;			//someone dropped out
  
  /*
  * Create all players
  */
  void createPlayer(const int &numPlayer);
  /*
  * Player buy the propery, or start an auction
  */
  void buyOrAuction(std::string type);
  /*
  * Collect money from players
  */
  bool collectMoney(const int &totalAmount, std::string type, std::string owed);
  /*
  * Use player's selectd way to levae Tims, if player left return true
  */
  bool leaveTims(const int &whichWay);
  /*
  * Return true if the player owns all buildings in a monopoly block
  */
  bool ownsAll(std::string name, std::string block); 
  /*
  * Find the place index on campus according to the name 
  */
  int findPlace(std::string placeName);
  /*
  * Drop out the player who has lose
  */
  void dropOut();
  
  
  public:
	Board();		//default constrctor
	~Board();		//destrctor
        
	/*
	* accessors used by controller to inquire about the state of the game
	*/
	std::string getPlayerName(const int &n);
	std::string getPlaceName(const int &n);
  	int getNumPlayers();
  	std::string getName(const int &n);
  	int getPlayerMoney(const int &n);
  	int getPlayerCups(const int &n);
  	int getPosn(const int &n);
  	std::string getPlaceOwner(const int n);
  	int getPlaceLevel(const int &n);


	/*
	* Intended to be called by Controller
	*/
	void init(const int &numPlayer, Controller* cl);
	/*
	* Move the current player according to dices
	*/
	void move(const int &diceA, const int &diceB);
	/*
	* Upgrade the building (buy improvements)
	*/
	void upgrade(int numLevel);
	/*
	* Sell improvements
	*/
	int sell(std::string name, int numLevel);
	/*
	*  A player won an auction and purchase the property
	*/
	void wonBid(std::string playerName, int finalPrice, std::string propertyName);
	/*
	*  Give the control to next player
	*/
	void next();
	/*
	* Trade money or property betweent two players, return 1 if trade
	* is succeseful
	*/
	bool trade(std::string name, std::string give, std::string receive);
	/*
	* Mortgage the property, rerurn the amount of mortgage
	*/
	int mortgage(std::string propertyName);
	/*
	* Unmortgage the property, return 1 if succeseful
	*/
	bool unmortgage(std::string propertyName);
	/*
	* Declare a bankrupt
	*/
	void bankrupt(std::string owed);
	/*
	* Display the assets of current player
	*/
	void asset();
	/*
	* Save the current state of game
	*/
	void save(std::string fileName);
	/*
	* Load the game state
	*/
	void load(std::string load, Controller *cl);
	/*
	* The player is sent to DC TIMS Line
	*/
	void goToTims();
	/*
	* Check if player is in DC Tims Line
	*/
	bool isInTims();
	/*
	* Check if anyone win the game
	*/
	std::string win();
	/*
	* Check if the place is a residence, Gym, or others
	*/
	std::string rezOrGym(std::string name);
	/*
	* Check if anyone has dropped out from the game
	*/
	bool anyoneLoss();
};

#endif
