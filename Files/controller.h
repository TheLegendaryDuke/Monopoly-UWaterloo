#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__
#include <string>
#include "board.h"
#include "textdisplay.h"

using std::string;

class TextDisplay;

class Controller {
  Board *board;//the game board
  TextDisplay *td;// textdisplay
  bool rolled;// if the current player has rolled

  //View *gd;
public:
  /*
    functions called by view for information about the current state of game
  */
  string getPlaceName(int);
  int getNumPlayers();
  string getPlayerName(int);
  int getPlayerMoney(int);
  int getPlayerCups(int);
  int getPosn(int);
  string getPlaceOwner(int);
  int getPlaceLevel(int);

  /*
    sets the rolled flag
  */
  void setRolled(bool);  
  /*
    asks the player if they want to unmort a property right away
  */
  bool unmort(string);
  /*
    dtor
  */
  ~Controller();
  /*
    play the game
  */
  void play(string, string);
  /*
    prompt the player on a payment
  */
  void pay(int, string);
  /*
    asks the player what to choose
  */
  bool tuitionOrWorth();
  /*
    asks the player what to do at Tims line
  */
  int rollPayCup(bool);
  /*
    checks if the string is a valid name
  */
  bool valid(string);
  /*
    do an auction
  */
  void auction(string);
  /*
    used by board to request for the name of a player
  */
  int requestPlayerName(int n);
  /*
    init a new game
  */
  void init();
  /*
    roll a dice
  */
  int roll();
  /*
    make a move
  */
  void move();
  /*
    does the player want to buy the property?
  */
  bool buy();
  /*
    returns the amount the player gets from a mortgage or 0 if mortgage fails
  */
  int mortgage();
  /*
    get the way of payment should there be not enough money
  */
  int noMoney(int);
};

#endif  
