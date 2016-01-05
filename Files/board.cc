#include <string>
#include "board.h"
#include "controller.h"
#include "place.h"
#include "building.h"
#include "residence.h"
#include "gym.h"
#include "special.h"
#include "player.h"
#include "rurcup.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;

Board::Board() {
  campus[0] = new Special("COLLECT OSAP");
  campus[1] = new Building("AL", "Arts1", 40, 50, 2, 10, 30, 90, 160, 250);
  campus[2] = new Special("SLC");
  campus[3] = new Building("ML", "Arts1", 60, 50, 4, 20, 60, 180, 320, 450);
  campus[4] = new Special("TUITION");
  campus[5] = new Residence("MKV", 200, 25);
  campus[6] = new Building("ECH", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550);
  campus[7] = new Special("NEEDLES HALL");
  campus[8] = new Building("PAS", "Arts2", 100, 50, 6, 30, 90, 270, 400, 550);
  campus[9] = new Building("HH", "Arts2", 120, 50, 8, 40, 100, 300, 450, 600);
  campus[10] = new Special("DC Tims Line");
  campus[11] = new Building("RCH", "Eng", 140, 100, 10, 50, 150, 450, 625, 750);
  campus[12] = new Gym("PAC", 150);
  campus[13] = new Building("DWE", "Eng", 140, 100, 10, 50, 150, 450, 625, 750);
  campus[14] = new Building("CPH", "Eng", 160, 100, 12, 60, 180, 500, 700, 900);
  campus[15] = new Residence("UWP", 200, 25);
  campus[16] = new Building("LHI", "Health", 180, 100, 14, 70, 200, 550, 750, 950);
  campus[17] = new Special("SLC");
  campus[18] = new Building("BMH", "Health", 180, 100, 14, 70, 200, 550, 750, 950);
  campus[19] = new Building("OPT", "Health", 200, 100, 16, 80, 220, 600, 800, 1000);
  campus[20] = new Special("Goose Nesting");
  campus[21] = new Building("EV1", " Env", 220, 150, 18, 90, 250, 700, 875, 1050);
  campus[22] = new Special("NEEDLES HALL");
  campus[23] = new Building("EV2", "Env", 220, 150, 18, 90, 250, 700, 875, 1050);
  campus[24] = new Building("EV3", "Env", 240, 150, 20, 100, 300, 750, 925, 1100);
  campus[25] = new Residence("V1", 200, 25);
  campus[26] = new Building("PHYS", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150);
  campus[27] = new Building("B1", "Sci1", 260, 150, 22, 110, 330, 800, 975, 1150);
  campus[28] = new Gym("CIF", 150);
  campus[29] = new Building("B2", "Sci1", 280, 150, 24, 120, 360, 850, 1025, 1200);
  campus[30] = new Special("GO TO TIMS");
  campus[31] = new Building("EIT", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275);
  campus[32] = new Building("ESC", "Sci2", 300, 200, 26, 130, 390, 900, 1100, 1275);
  campus[33] = new Special("SLC");
  campus[34] = new Building("C2", "Sci2", 320, 200, 28, 150, 450, 1000, 1200, 1400);
  campus[35] = new Residence("REV", 200, 25);
  campus[36] = new Special("NEEDLES HALL");
  campus[37] = new Building("MC", "Math", 350, 200, 35, 175, 500, 1100, 1300, 1500);
  campus[38] = new Special("COOP FEE");
  campus[39] = new Building("DC", "Math", 400, 200, 50, 200, 600, 1400, 1700, 2000);

  numPlayer = 0;
  players = NULL;
  cl = NULL;
  anyLoss = false;
}

Board::~Board() {
  for (int j=0; j<numPlayer; j++) {
	delete players[j];
  }
  delete[] players;

  for(int i = 0; i < 40; i++) {
    delete campus[i];
  }

  delete[] playerPlaces;
}



int Board::getNumPlayers() {
  return numPlayer;
}


string Board::getPlayerName(const int &n) {
  return players[n]->getName();
}


int Board::getPlayerMoney(const int &n) {
  return players[n]->getMoney();
}


int Board::getPlayerCups(const int &n) {
  return players[n]->getNumCups();
}


int Board::getPosn(const int &n) {
  return playerPlaces[n];
}


string Board::getPlaceOwner(const int n) {
if(campus[n]->getOwner()) {
  return campus[n]->getOwner()->getName();
}else {
  return "";
}
}


int Board::getPlaceLevel(const int &n) {
  return campus[n]->getLevel();
}


string Board::getPlaceName(const int &n) {
  return campus[n]->getName();
}




void Board::init(const int &numPlayer, Controller *cl) {
  this->numPlayer = numPlayer;
  createPlayer(numPlayer);

  this->playerPlaces = new int[numPlayer];
  for (int i=0; i<numPlayer; i++) {
	playerPlaces[i] = 0;
  }

  this->currentPlayer = 0;
  this->nextPlayer = 1;
  this->cl = cl;
}



void Board::createPlayer(const int &numPlayer) {
  this->players = new Player *[numPlayer];
  for (int i=0; i< numPlayer; i++) {
	players[i] = new Player();
	int nameChar = cl->requestPlayerName(i);

	string name;								//determine player's name
	if (nameChar == 1) name = "Goose";
	if (nameChar == 2) name = "GRT Bus";
	if (nameChar == 3) name = "Tim Hortons Doughnut";
	if (nameChar == 4) name = "Professor";
	if (nameChar == 5) name = "Student";
	if (nameChar == 6) name = "Money";
	if (nameChar == 7) name = "Laptop";
	if (nameChar == 8) name = "Pink Tie";
	players[i]->setName(name);
  }
}



void Board::buyOrAuction(string type) {
  int currentPlaceIndex = playerPlaces[currentPlayer];
  int totalMoney = players[currentPlayer]->getMoney();
  if (cl->buy()) {								//current player wants to buy the property
	int purchaseCost = campus[currentPlaceIndex]->getCost();
	if (totalMoney < purchaseCost) {
	  cout << "You do not have enough money to purchase this porperty" << endl;
	}
	else {
	  int balance = totalMoney - purchaseCost;
	  campus[currentPlaceIndex]->setOwner(players[currentPlayer]);
	  players[currentPlayer]->setMoney(balance);
	  players[currentPlayer]->addProperty(campus[currentPlaceIndex], type);
	  cout << "Congratulations! You have purchased ";
	  cout << campus[currentPlaceIndex]->getName() << "." << endl;
	}
  }

  else {									//current player doesn't want to buy it
	cl->auction(campus[currentPlaceIndex]->getName());
  }
}



bool Board::collectMoney(const int &totalAmount, string type, string owed = "") {
  int totalMoney = players[currentPlayer]->getMoney();
  if (totalMoney >= totalAmount) {
	int balance = totalMoney - totalAmount;
	players[currentPlayer]->setMoney(balance);
	cl->pay(totalAmount, type);
	return true;
  }
  else {									//the player doesn't have enough money to pay
	int gain = cl->noMoney(totalAmount-totalMoney);
	if (gain == 0) {							//the player cannot gain any money
	  this->bankrupt(owed);
	  return false;
	}
	else {
	  while ((totalMoney+gain) < totalAmount) {				//the player cannot gain enough money
	  	int need = (totalMoney + gain) - totalAmount;
	  	int newGain = cl->noMoney(need);
	  	if (newGain == 0) {						//the player cannot gain any money anymore
		  this->bankrupt(owed);
		  return false;
	  	}
	  	gain = gain + newGain;
	  }

	  int balance = players[currentPlayer]->getMoney() - totalAmount;
	  players[currentPlayer]->setMoney(balance);
	  cl->pay(totalAmount, type);
	  return true;
	}
  }
}



bool Board::leaveTims(const int &whichWay) {
  int diceA, diceB, dices;
  bool enough = false;
  switch (whichWay) {
	case 1:									//player choosed to roll dices
		dices = cl->roll();
		diceA = dices / 10;
		diceB = dices % 10;
		if (diceA == diceB) {						//roll doubles
		  players[currentPlayer]->getOutTims();
		  move(diceA, diceB);
		  cl->setRolled(true);
		  return true;
		}
		else {
		  return false;
		}

	case 2:									//player choosed to pay $50
		enough = collectMoney(50, "the fees to get out from DC Tims Line");
		if (enough) {							//player paied $50
		  players[currentPlayer]->getOutTims();

		  dices = cl->roll();
		  diceA = dices / 10;
		  diceB = dices % 10;
		  move(diceA, diceB);
		  cl->setRolled(true);
		  return true;
		}
		else {
		  return false;
		}
	
	case 3:									//player choose to use Roll Up the Rim cup
		RURCup *use = players[currentPlayer]->useCup();
		delete use;
		players[currentPlayer]->getOutTims();

		dices = cl->roll();
		diceA = dices / 10;
		diceB = dices % 10;
		move(diceA, diceB);
		cl->setRolled(true);
		return true;
  }
}



bool Board::ownsAll(string name, string block) {
  for (int i=0; i<40; i++) {
	if (block == campus[i]->getBlock()) {
	  if (campus[i]->getOwner() == NULL || campus[i]->getOwner()->getName() != name) {
		return false;
	  }
	}
  }
  return true;
}



int Board::findPlace(string placeName) {
  for (int i=0; i<40; i++) {
	if (campus[i]->getName() == placeName) {
	  return i;
	}
  }
  return -1;
}



void Board::move(const int &diceA, const int &diceB) {
  int sum = diceA + diceB;
  int prevPlaceIndex = playerPlaces[currentPlayer];

  if ((sum < 0) && (prevPlaceIndex < (-1 * sum))) {				//players moves and passes COLLECT OSAP
	sum = prevPlaceIndex + sum;
	int newPlace = 40 + sum;
	playerPlaces[currentPlayer] = newPlace;
  } else
  if (prevPlaceIndex + sum >= 40) {
	int newPlace = (prevPlaceIndex + sum) - 40;
	playerPlaces[currentPlayer] = newPlace;
  } 
  else {									//players moves
  	playerPlaces[currentPlayer] = playerPlaces[currentPlayer] + sum;
  }

  int currentPlaceIndex = playerPlaces[currentPlayer];
  string currentPlace = campus[currentPlaceIndex]->getName();
  int totalMoney = players[currentPlayer]->getMoney();

  string direction = (sum < 0) ? "backward" : "forward";				//message to player
  int totalSteps = (sum < 0) ? (-1 * sum) : sum;
  cout << "You have moved " << totalSteps << " " << direction << ".";
  cout << "You are now on " << currentPlace << "." << endl;

  if ( ((currentPlace != "GO TO TIMS") && sum > 0 && currentPlaceIndex < prevPlaceIndex)
	|| currentPlace == "COLLECT OSAP") {					//pass COLLECT OSAP or on COLLECT OSAP
	int currentMoney = players[currentPlayer]->getMoney();
	int newMoney = currentMoney + 200;
	players[currentPlayer]->setMoney(newMoney);
	cout << "You collected $200 from OSAP!" << endl;
	if (currentPlace == "COLLECT OSAP") return;				//on COLLECT OSAP
  }


  if (currentPlace == "MKV" || currentPlace == "UWP" || currentPlace == "V1" || currentPlace == "REV") {
	if (campus[currentPlaceIndex]->getOwner() == NULL) {			//the property doesn't have an owner
	  this->buyOrAuction("residence");
	}

	else {									//the property has an owner
	  Player *owner = campus[currentPlaceIndex]->getOwner();
	  if (owner->getName() != players[currentPlayer]->getName()) {		//current player is not the owner
		int n = owner->getNumResidence();
		int totalRent = n * campus[currentPlaceIndex]->getRent();
		bool ok = this->collectMoney(totalRent, "rent", owner->getName());

		if (ok) {							//owner collects the rent
		  int collected = totalRent + owner->getMoney();
		  owner->setMoney(collected);
		}
	  }
	}
  } else

  
  if (currentPlace == "PAC" || currentPlace == "CIF") {
	if (campus[currentPlaceIndex]->getOwner() == NULL) {			//the property doesn't have an owner
	  this->buyOrAuction("gym");
	}

	else {
	  Player* owner = campus[currentPlaceIndex]->getOwner();
	  if (owner->getName() != players[currentPlayer]->getName()){		//current player is not the owner
		int totalOwn = owner->getNumGym();
		int dices = cl->roll();
		int n = 0;
		if (totalOwn == 1) {
		  n = 4;
		}
		if (totalOwn == 2) {
		  n = 10;
		}
		int totalRent = n * ((dices / 10) + (dices % 10));
		bool ok = this->collectMoney(totalRent, "rent", owner->getName());

		if (ok) {							//owner collects the rent
		  int collected = totalRent + owner->getMoney();
		  owner->setMoney(collected);
		}
	  }
	}
  } else


  if (currentPlace == "DC Tims Line") {
	int first, numCups, second, whichWay;
	bool left = false;
	if (players[currentPlayer]->isInTims()) {
	  switch (players[currentPlayer]->getTurns()) {
		case 3:
			first = cl->rollPayCup(true);

			numCups = players[currentPlayer]->getNumCups();		//check if player has any cups
			while (first == 3 && numCups == 0) {
			  cout << "You do not have any Roll Up the Rim Cup!" << endl;
			  first = cl->rollPayCup(true);
			}

			left = this->leaveTims(first);
			if (!left && first == 1) {
			  second = cl->rollPayCup(false);

			  while (second == 3 && numCups == 0) {			//check if player has any cups
				cout << "You do not have any Roll Up the Rim Cup!!!" << endl;
				second = cl->rollPayCup(false);
			  }

			  this->leaveTims(second);
			}
			break;

		default:
			whichWay = cl->rollPayCup(true);

			numCups = players[currentPlayer]->getNumCups();		//check if player has any cups
			while (whichWay == 3 && numCups == 0) {
			  cout << "You do not have any Roll Up the Rim Cup!" << endl;
			  whichWay = cl->rollPayCup(true);
			}

			left = this->leaveTims(whichWay);
			if (!left) {
			  players[currentPlayer]->stall();
			}
			else {
			  players[currentPlayer]->getOutTims();
			}
			break;			
	  }
	}
  } else


  if (currentPlace == "GO TO TIMS") {
	players[currentPlayer]->goToTims();
	playerPlaces[currentPlayer] = 10;
	cout << "You have been sent to DC Tims line." << endl;
  } else


  if (currentPlace == "Goose Nesting") {
	cout << "You have been attacked by a flock of nesting geese!!!" << endl;
  } else


  if (currentPlace == "TUITION") {
	int totalWorth = players[currentPlayer]->getMoney();
	int numProperty = players[currentPlayer]->getNumProperty();
	for (int i=0; i<numProperty; i++) {					//calculate the total worth
	  int level = players[currentPlayer]->allProperty()[i]->getLevel();
	  int improvementCost = players[currentPlayer]->allProperty()[i]->getImproveCost();
	  int printedPrice = players[currentPlayer]->allProperty()[i]->getCost();
	  totalWorth = totalWorth + (level * improvementCost) + printedPrice;
	}

	bool which = cl->tuitionOrWorth();					//ask the player
	if (which == 0) {							//player wants to pay $300 as tuition
	  collectMoney(300, "tuition");
	}
	else {									//player wants to pay 10% of total worth
	  collectMoney((0.1 * totalWorth), "tuition");
	}
  } else


  if (currentPlace == "COOP FEE") {
	collectMoney(150, "Coop Fee");
  } else


  if (currentPlace == "SLC") {
	srand(time(NULL));
	int rare = rand() % 100;
	if (rare = 33) {
	  if (players[currentPlayer]->gainCup()) {
	  	cout << "You receive a Roll Up the Rim Cup!" << endl;
	  	return;
	  }
	}

	int n = rand() % 24;
	if (n == 0 || n == 1 || n == 2) {
	  move(-3, 0);
	} else
	if (n == 3 || n == 4 | n == 5 || n == 6) {
	  move(-2, 0);
	} else 
	if (n == 7 || n == 8 || n == 9 || n == 10) {
	  move(-1, 0);
	} else
	if (n == 11 || n == 12 || n == 13) {
	  move(1, 0);
	} else
	if (n == 14 || n == 15 || n == 16 || n == 17) {
	  move(2, 0);
	} else
	if (n == 18 ||  n == 19 || n == 20 || n == 21) {
	  move(3, 0);
	} else
	if (n == 22) {
	  int steps = 30 - playerPlaces[currentPlayer];
	  move(steps, 0);
	}
	else {
	  playerPlaces[currentPlayer] = 0;
	  int collectOSAP = 200 + players[currentPlayer]->getMoney();
	  players[currentPlayer]->setMoney(collectOSAP);
	  cout << "You collected $200 from OSAP!" << endl;
	}
  } else


  if (currentPlace == "NEEDLES HALL") {
	srand(time(NULL));
	int rare = rand() % 100;
	if (rare == 52) {
	  if (players[currentPlayer]->gainCup()) {
	  	cout << "You receive a Roll Up the Rim Cup!" << endl;
	  	return;
	  }
	}

	int n = rand() % 18;
	int change;
	if (n == 0) {
	  change = -200;
	} else
	if (n == 1 || n == 2) {
	  change = -100;
	} else
	if (n == 3 || n == 4 || n == 5) {
	  change = -50;
	} else
	if (n == 6 || n == 7 || n == 8 || n == 9 || n == 10 || n == 11) {
	  change = 25;
	} else
	if (n == 12 || n == 13 || n == 14) {
	  change = 50;
	} else
	if (n == 15 || n == 16) {
	  change = 100;
	} else
	if (n == 17) {
	  change = 200;
	}

	if (change < 0) {
	  this->collectMoney((-1 * change), "toll");
	}
	else {
	  int changed = change + players[currentPlayer]->getMoney();
	  players[currentPlayer]->setMoney(changed);
	  cout << "You gained $" << change << "." << endl;
	}
  }


  else {										//Academic Buildings
	if (campus[currentPlaceIndex]->getOwner() == NULL) {				//the building has no owner
	  this->buyOrAuction("building");
	}
	else {										//the building has an owner
	  Player* owner = campus[currentPlaceIndex]->getOwner();
	  if (owner->getName() != players[currentPlayer]->getName()) {			//player is not the owner
		int tuition = campus[currentPlaceIndex]->getTuition();
		if (ownsAll(owner->getName(), campus[currentPlaceIndex]->getBlock())) {	//owner owns all buildings in a monopoly
		  tuition = 2 * tuition;
		}

		bool ok = collectMoney(tuition, "tuition", owner->getName());
		if (ok) {								//owner collects the fees
		  int collected = tuition + owner->getMoney();
		  owner->setMoney(collected);
		}
	  }
	}
  }
}



void Board::upgrade(int numLevel) {
  if (campus[playerPlaces[currentPlayer]]->getImproveCost() == 0) {			//not an academic buildings
	cout << "There is no improvement available for this property." << endl;
	return;
  } else

  if ((campus[playerPlaces[currentPlayer]]->getOwner() == NULL)				//player is not the owner
       || (players[currentPlayer]->getName() != campus[playerPlaces[currentPlayer]]->getOwner()->getName())) {
	cout << "You are not the owner of this property!" << endl;
	return;
  }

  if (! ownsAll(players[currentPlayer]->getName(), campus[playerPlaces[currentPlayer]]->getBlock())) {
	cout << "You must own all buildings in ";
	cout << campus[playerPlaces[currentPlayer]]->getBlock();
	cout << " block before purchasing any improvement." << endl;
	return;
  }

  Place* current = campus[playerPlaces[currentPlayer]];
  int improvementCost = current->getImproveCost();
  int currentLevel = current->getLevel();

  if (numLevel + currentLevel > 5) {							//mamximum of 5
	cout << "There are only five improvements available, you already have ";
	cout << currentLevel << "." << endl;
	return;
  }

  int totalCost = numLevel * improvementCost;
  int newLevel = numLevel + currentLevel;
  int totalMoney = players[currentPlayer]->getMoney();
  if (totalMoney >= totalCost) {							//player has enough money
	int balance = totalMoney - totalCost;
	players[currentPlayer]->setMoney(balance);
	current->setLevel(newLevel);
	cout << "Congradultations! You have bought " << numLevel;
	cout << ((numLevel > 1) ? " improvements" : " improvement");
	cout << "." << endl;
  }
  else {										//player doesn't have enough money
	cout << "You do not have enough money to buy " << numLevel;
	cout << ((numLevel > 1) ? " improvements" : " improvement");
	cout << "." << endl;
  }

  if (current->getLevel() == 5) {
	cout << current->getName() << " now has a working WAP." << endl;
  }
}



int Board::sell(string name, int numLevel) {
  int target = findPlace(name);
  if (campus[target]->getImproveCost() == 0) {						//not an academic buildings
	cout << "This is not an academic building, there is no improvement for you to sell" << endl;
	return 0;
  } else

  if ((campus[target]->getOwner() == NULL)						//player is not the owner
       || (players[currentPlayer]->getName() != campus[target]->getOwner()->getName())) {
	cout << "You are not the owner of this property!" << endl;
	return 0;
  } else

  if (campus[target]->getLevel() == 0) {
	cout << "You have not yet bought any improvement for this property." << endl;
	return 0;
  }

  int currentLevel = campus[target]->getLevel();
  if (numLevel > currentLevel) {
	cout << "You don't have " << numLevel;
	cout << ((numLevel > 1) ? " improvements " : " improvement ");
	cout << "." << endl;
	return 0;
  }

  int refund = (numLevel * campus[target]->getImproveCost()) / 2;
  campus[target]->setLevel(currentLevel-numLevel);
  int balance = refund + players[currentPlayer]->getMoney();
  players[currentPlayer]->setMoney(balance);
  cout << "You have sold " << numLevel;
  cout << ((numLevel > 1) ? " improvements " : " improvement ");
  cout << "for $" << refund << ". " << endl;
  return refund;
}



void Board::wonBid(string winnerName, int finalPrice, string propertyName) {
  int target = findPlace(propertyName);
  int winnerIndex;
  for (int i=0; i<this->numPlayer; i++) {
	if (players[i]->getName() == winnerName) {
	  winnerIndex = i;
	}
  }

  int temp = this->currentPlayer;
  this->currentPlayer = winnerIndex;
  bool ok = collectMoney(finalPrice, "payment of the auction you won");
  if (ok) {											//paid the payment
	campus[target]->setOwner(players[winnerIndex]);
	cout << campus[target]->getName() << " is now under your name." << endl;
	string type = rezOrGym(propertyName);
	players[winnerIndex]->addProperty(campus[target], type);
  }
  this->currentPlayer = temp;
}



void Board::next() {
  this->currentPlayer = this->nextPlayer;
  if ((this->nextPlayer + 1) >= numPlayer) {
	this->nextPlayer = 0;
  }
  else {
  	this->nextPlayer = this->nextPlayer + 1;
  }
  cout << "It is " << players[currentPlayer]->getName() << "'s turn now." << endl;
}



bool Board::trade(string name, string give, string receive) {
  istringstream s1(give);;
  istringstream s2(receive);
  int giveTarget;
  int giveAmount;
  int receiveAmount;
  bool giveCheck = false;
  string giveType;

  if (name == players[currentPlayer]->getName()) {
	cout << "You can't trade with yourself." << endl;
	return false;
  }

  int receiver = -1;
  for (int i=0; i<this->numPlayer; i++) {							//find the player
	if (players[i]->getName() == name) {
	  receiver = i;
	}
  }
  if (receiver == -1) {
	cout << "There is no such player in this game!" << endl;
	return false;
  }


  if (give == "cup") {										//trade with cup
	if (players[currentPlayer]->getNumCups() == 0) {
	  cout << "You don't have any Roll Up the Rim Cup." << endl;
	  return false;
	}
	else {
	  giveCheck = true;
	  giveType = "cup";
	}
  }  else
  if (! (s1 >> giveAmount)) {									//trade with property
	giveTarget = findPlace(give);
	if (giveTarget == -1) {
	  cout << "No such place in this game" << endl;
	  return false;
	}
	if ((campus[giveTarget]->getOwner() == NULL && campus[giveTarget]->getPrevOwner() == NULL)
	   || (campus[giveTarget]->getPrevOwner() == NULL 
		&& campus[giveTarget]->getOwner()->getName() != players[currentPlayer]->getName())
	   || (campus[giveTarget]->getOwner() == NULL
		&& campus[giveTarget]->getPrevOwner()->getName() != players[currentPlayer]->getName())) {
	  cout << "You don't own " << campus[giveTarget]->getName() << "." << endl;
	  return false;
	}
	else {
	  giveCheck = true;
	  giveType = "property";
	}
  }
  else {											//trade with money
	if (giveAmount > players[currentPlayer]->getMoney()) {
	  cout << "You don't have enough money to trade." << endl;
	  return false;
	}
	else {
	  giveCheck = true;
	  giveType = "money";
	}
  }

  if (receive == "cup") {									//wants a cup
	if (players[receiver]->getNumCups() == 0) {
	  cout << players[receiver]->getName() << " doesn't have any Roll Up the Rim Cup." << endl;
	  return false;
	}
	else {
	  if (giveCheck) {
		if (giveType == "cup") {							//trade cup with cup
		  cout << "You received a Roll Up the Rim Cup from " << players[receiver]->getName();
		  cout << "." << endl;
		  cout << players[receiver]->getName()  << " received a Roll Up the Rim Cup from ";
		  cout << players[currentPlayer]->getName() << "." << endl;
		} else
		if (giveType == "property") {							//trade cup with property
		  if (campus[giveTarget]->getOwner() != NULL) {
			campus[giveTarget]->setOwner(players[receiver]);
			string type = rezOrGym(campus[giveTarget]->getName());
		  	players[currentPlayer]->removeProperty(campus[giveTarget], type);
		  	players[receiver]->addProperty(campus[giveTarget], type);
		  } else
		  if (campus[giveTarget]->getPrevOwner() != NULL) {
			campus[giveTarget]->setPrevOwner(players[receiver]);
		  }

		  RURCup *temp = players[receiver]->useCup();
		  delete temp;
		  players[currentPlayer]->gainCup();

		  cout << "You traded " << campus[giveTarget]->getName() << " with ";
		  cout << players[receiver]->getName() << ", and received a Roll Up the Rim Cup." << endl;
		}
		else {										//trade cup with money
		  int balance = players[currentPlayer]->getMoney() - giveAmount;
		  int income = players[receiver]->getMoney() + giveAmount;
		  players[currentPlayer]->setMoney(balance);
		  players[receiver]->setMoney(income);

		  RURCup *temp = players[receiver]->useCup();
		  delete temp;
		  players[currentPlayer]->gainCup();

		  cout << "You traded $" << giveAmount << " with ";
		  cout << players[receiver]->getName() << ", and received a Roll Up the Rim Cup." << endl;
		}
		return true;
	  }
	}
  }  else
  if (!(s2 >> receiveAmount)) {									//wants a property
	int receiveTarget = findPlace(receive);
	if (receiveTarget == -1) {
	  cout << "No such place in this game." << endl;
	  return false;
	}
	if (campus[receiveTarget]->getOwner()->getName() != players[receiver]->getName()) {
	  cout << players[receiver]->getName() << " doesn't own ";
	  cout << campus[receiveTarget]->getName() << "." << endl;
	  return false;
	}
	else {
	  if (giveCheck) {
		if (giveType == "cup") {							//trade property with cup
		  RURCup *temp = players[currentPlayer]->useCup();
		  delete temp;
		  players[receiver]->gainCup();

		  if (campus[receiveTarget]->getOwner() != NULL) {
		  	campus[receiveTarget]->setOwner(players[currentPlayer]);
			string type = rezOrGym(campus[receiveTarget]->getName());
		  	players[receiver]->removeProperty(campus[receiveTarget], type);
		  	players[currentPlayer]->addProperty(campus[receiveTarget], type);
		  } else
		  if (campus[receiveTarget]->getPrevOwner() != NULL) {
			campus[receiveTarget]->setPrevOwner(players[currentPlayer]);
		  }

		  cout << "You now own " << campus[receiveTarget]->getName();
		  cout << "." << endl;
		  cout << players[receiver]->getName()  << " received a Roll Up the Rim Cup from ";
		  cout << players[currentPlayer]->getName() << "." << endl;
		} else
		if (giveType == "property") {							//trade property with property
		  if (campus[giveTarget]->getOwner() != NULL) {
		  	campus[giveTarget]->setOwner(players[receiver]);
			string type = rezOrGym(campus[giveTarget]->getName());
		  	players[currentPlayer]->removeProperty(campus[giveTarget], type);
		  	players[receiver]->addProperty(campus[giveTarget], type);
		  } else
		  if (campus[giveTarget]->getPrevOwner() != NULL) {
			campus[giveTarget]->setPrevOwner(players[receiver]);
		  }

		  if (campus[receiveTarget]->getOwner() != NULL) {
		  	campus[receiveTarget]->setOwner(players[currentPlayer]);
			string type = rezOrGym(campus[receiveTarget]->getName());
		  	players[receiver]->removeProperty(campus[receiveTarget], type);
		  	players[currentPlayer]->addProperty(campus[receiveTarget], type);
		  } else
		  if (campus[receiveTarget]->getPrevOwner() != NULL) {
			campus[receiveTarget]->setPrevOwner(players[currentPlayer]);
		  }

		  cout << "You traded " << campus[giveTarget]->getName() << " with ";
		  cout << players[receiver]->getName() << ", and now you own " << campus[receiveTarget]->getName() << "." << endl;
		}
		else {										//trade property with money
		  int balance = players[currentPlayer]->getMoney() - giveAmount;
		  int income = players[receiver]->getMoney() + giveAmount;
		  players[currentPlayer]->setMoney(balance);
		  players[receiver]->setMoney(income);

		  if (campus[receiveTarget]->getOwner() != NULL) {
		  	campus[receiveTarget]->setOwner(players[currentPlayer]);
			string type = rezOrGym(campus[receiveTarget]->getName());
		  	players[receiver]->removeProperty(campus[receiveTarget], type);
		  	players[currentPlayer]->addProperty(campus[receiveTarget], type);
		  } else
		  if (campus[receiveTarget]->getPrevOwner() != NULL) {
			campus[receiveTarget]->setPrevOwner(players[currentPlayer]);
		  }

		  cout << "You traded $" << giveAmount << " with ";
		  cout << players[receiver]->getName() << ", and now you own " << campus[receiveTarget]->getName() << endl;
		}
		return true;
	  }
	}
  }
  else {											//wants some money
	if (receiveAmount > players[receiver]->getMoney()) {
	  cout  << players[receiver]->getName() << " doesn't have enough money to trade." << endl;
	  return false;
	}
	else {
	  if (giveCheck) {
		if (giveType == "cup") {							//trade money with cup
		  RURCup *temp = players[currentPlayer]->useCup();
		  delete temp;
		  players[receiver]->gainCup();

		  int balance = players[receiver]->getMoney() - receiveAmount;
		  int income = players[currentPlayer]->getMoney() + receiveAmount;
		  players[receiver]->setMoney(balance);
		  players[currentPlayer]->setMoney(income);

		  cout << "You received " << receiveAmount << " from " << players[receiver]->getName();
		  cout << "." << endl;
		  cout << players[receiver]->getName()  << " received a Roll Up the Rim Cup from ";
		  cout << players[currentPlayer]->getName() << "." << endl;
		} else
		if (giveType == "property") {							//trade money with property
		  if (campus[giveTarget]->getOwner() != NULL) {
			campus[giveTarget]->setOwner(players[receiver]);
			string type = rezOrGym(campus[giveTarget]->getName());
		  	players[currentPlayer]->removeProperty(campus[giveTarget], type);
		  	players[receiver]->addProperty(campus[giveTarget], type);
		  } else
		  if (campus[giveTarget]->getPrevOwner() != NULL) {
			campus[giveTarget]->setPrevOwner(players[receiver]);
		  }

		  int balance = players[receiver]->getMoney() - receiveAmount;
		  int income = players[currentPlayer]->getMoney() + receiveAmount;
		  players[receiver]->setMoney(balance);
		  players[currentPlayer]->setMoney(income);

		  cout << "You traded " << campus[giveTarget]->getName() << " with ";
		  cout << players[receiver]->getName() << ", and received $" << receiveAmount << "." << endl;
		}
		else {										//trade money with money
		  int balance1 = players[currentPlayer]->getMoney() - giveAmount + receiveAmount;
		  int balance2 = players[receiver]->getMoney() - receiveAmount + giveAmount;
		  players[currentPlayer]->setMoney(balance1);
		  players[receiver]->setMoney(balance2);

		  cout << "You traded $" << giveAmount << " with ";
		  cout << players[receiver]->getName() << ", and received $" << receiveAmount << "." << endl;
		}
		return true;
	  }
	}
  }
}



int Board::mortgage(string propertyName) {
  int target = findPlace(propertyName);
  if (target == -1) {
	cout << "There is no such place in this game." << endl;
	return 0;
  }

  int totalCost = campus[target]->getCost();
  int improvementCost = campus[target]->getImproveCost();
  Player* owner = campus[target]->getOwner();
  if (owner == NULL || owner->getName() != players[currentPlayer]->getName() || totalCost == 0) {
	cout << "You are not the owner of " << propertyName << "." << endl;
	return 0;
  }
  else {
	if (improvementCost != 0 && campus[target]->getLevel() != 0) {				//check if there is any improvement
	  cout << "You have to sell all the improvements before mortgage." << endl;
	  return 0;
	}

	int halfCost = totalCost / 2;								//process mortgage
	campus[target]->setPrevOwner(owner);
	campus[target]->setOwner(NULL);
	int income = players[currentPlayer]->getMoney() + halfCost;
	players[currentPlayer]->setMoney(income);
	string type = rezOrGym(campus[target]->getName());
	players[currentPlayer]->removeProperty(campus[target], type);
	return halfCost;
  }
}



bool Board::unmortgage(string propertyName) {
  int target = findPlace(propertyName);
  if (target == -1) {
	cout << "There is no such place in this game." << endl;
	return false;
  }

  int totalCost = campus[target]->getCost();
  int improvementCost = campus[target]->getImproveCost();
  Player* prev = campus[target]->getPrevOwner();
  if (prev == NULL || prev->getName() != players[currentPlayer]->getName() || totalCost == 0) {
	cout << "You never owned this property! You cannot ummortgage it." << endl;
	return false;
  }
  else {
	int halfCost = totalCost / 2;
	int tenPercent = totalCost * 0.1;
	int totalPayment = halfCost + tenPercent;
	if (totalPayment > players[currentPlayer]->getMoney()) {				//check if player has enough money
	  cout << "You do not have enough money to unmortgage this property." << endl;
	  return false;
	}

	int balance = players[currentPlayer]->getMoney() - totalPayment;			//process unmortgage
	players[currentPlayer]->setMoney(balance);
	campus[target]->setOwner(prev);
	campus[target]->setPrevOwner(NULL);
	string type = rezOrGym(campus[target]->getName());
	players[currentPlayer]->addProperty(campus[target], type);
	cl->pay(totalPayment, "unmortgage fees");
	return true;
  }
}



void Board::dropOut() {
  cout << players[currentPlayer]->getName() << " broke!" << endl;
  cout << players[currentPlayer]->getName() << " lose!" << endl;
  
  int newNumPlayer = this->numPlayer - 1;							//remove the player
  Player** newPlayers = new Player *[newNumPlayer];
  int k = 0;
  for (int j=0; j<this->numPlayer; j++) {
	if (j != currentPlayer) {
	  newPlayers[k] = this->players[j];
	  k++;
	}
  }

  int *newPlayerPlaces = new int [newNumPlayer];
  for (int k=0; k<currentPlayer; k++) {
	newPlayerPlaces[k] = playerPlaces[k];
  }
  for (int n=this->currentPlayer; n<newNumPlayer; n++) {
	newPlayerPlaces[n] = playerPlaces[n+1];
  }

  delete players[currentPlayer];
  delete[] players;
  this->players = newPlayers;
  this->numPlayer = newNumPlayer;
  delete[] playerPlaces;
  this->playerPlaces = newPlayerPlaces;

  if (currentPlayer >= numPlayer) {
	this->currentPlayer = 0;
  }

  if (this->currentPlayer + 1 >= numPlayer) {
	this->nextPlayer = 0;
  }
  else {
  	this->nextPlayer = this->currentPlayer + 1;
  }

  this->anyLoss = true;
}



void Board::bankrupt(string owed) {
  if (this->numPlayer == 2) {
	this->dropOut();
	return;
  }

  if (owed != "") {										//the player owed another player
	int owedIndex;
	for (int i=0; i<this->numPlayer; i++) {
	  if (players[i]->getName() == owed) owedIndex = i;
	}

	int income = players[owedIndex]->getMoney() + players[currentPlayer]->getMoney();	//the player who is owed gets his money
	players[owedIndex]->setMoney(income);


	int numProperty = players[currentPlayer]->getNumProperty();				//the player who is owed gets his properties
	for (int i=0; i<numProperty; i++) {
	  string type = rezOrGym(players[currentPlayer]->allProperty()[i]->getName());
	  players[currentPlayer]->allProperty()[i]->setOwner(players[owedIndex]);
	  players[owedIndex]->addProperty(players[currentPlayer]->allProperty()[i], type);
	}


	int totalTenPercentToBank = 0;								//the player who is owed receives his mortgaged properties
	for (int m=0; m<40; m++) {
	  if (campus[m]->getPrevOwner() != NULL && campus[m]->getPrevOwner()->getName() == players[currentPlayer]->getName()) {
		int cost = campus[m]->getCost();
		totalTenPercentToBank = totalTenPercentToBank + (cost * 0.1);
		campus[m]->setPrevOwner(players[owedIndex]);
	  }
	}


	int numCup = players[currentPlayer]->getNumCups();					//the player who is owed gets his Cups
	for (int k=0; k<numCup; k++) {
	  RURCup *temp = players[currentPlayer]->useCup();
	  delete temp;
	  players[owedIndex]->gainCup();
	}

	cout << players[owedIndex]->getName() << " had all assets from " << players[currentPlayer]->getName() << "." << endl;


	int temp = this->currentPlayer;								//process to collect the fees
	this->currentPlayer = owedIndex;
	bool paidToBank = collectMoney(totalTenPercentToBank, "fees of receiving mortgaged properties");
	this->currentPlayer = temp;
	if (paidToBank) {									//player who is owed paid the first 10%
	  for (int u=0; u<40; u++) {
	  	if (campus[u]->getPrevOwner() != NULL && campus[u]->getPrevOwner()->getName() == players[owedIndex]->getName()) {
		  string name = campus[u]->getName();
		  if (cl->unmort(name)) {								//player who is owed wants to unmortgage
			int tmp = this->currentPlayer;
		 	this->currentPlayer = owedIndex;
			bool ok = this->unmortgage(name);
			if (!ok) {								//he does not have enough money, then must pay second 10%
			  bool done = this->collectMoney((campus[u]->getCost() * 0.1), "fees of leaving mortgaged property as mortgaged");
			  this->currentPlayer = tmp;
			  if (!done) break;
			}
			this->currentPlayer = tmp;
		  }
		  else {									//he does not want to unmortgage, wants to pay second 10%
			int tmp = this->currentPlayer;
			this->currentPlayer = owedIndex;
			bool done = this->collectMoney((campus[u]->getCost() * 0.1), "fees of leaving mortgaged property as mortgaged");
			this->currentPlayer = tmp;
			if (!done) break;
		  }
		}
	  }
	}
  }
  else {											//the player didn't owe another player
	int numProperty = players[currentPlayer]->getNumProperty();
	for (int i=0; i<numProperty; i++) {							//auction all properties
	  cl->auction(players[currentPlayer]->allProperty()[i]->getName());
	}

	for (int m=0; m<40; m++) {
	  if (campus[m]->getPrevOwner() != NULL && campus[m]->getPrevOwner()->getName() == players[currentPlayer]->getName()) {
		campus[m]->setPrevOwner(NULL);
		campus[m]->setOwner(NULL);
		cl->auction(campus[m]->getName());
	  }
	}

	int numCup = players[currentPlayer]->getNumCups();					//destroy player's all Roll Up the Rim Cups
	for (int j=0; j<numCup; j++) {
	  RURCup *temp = players[currentPlayer]->useCup();
	  delete temp;
	}
  }

  this->dropOut();
  cout << "It is " << players[currentPlayer]->getName() << "'s turn." << endl;
}



void Board::goToTims() {
  playerPlaces[currentPlayer] = 10;
  players[currentPlayer]->goToTims();
}



bool Board::isInTims() {
  return players[currentPlayer]->isInTims();
}



string Board::win() {
  if (this->numPlayer == 1) {
	return players[currentPlayer]->getName();
  }
  else {
	return "";
  }
}



string Board::rezOrGym(string name) {
  if (name == "MKV" || name == "UWP" || name == "V1" || name == "REV") {
	return "residence";
  } else
  if (name == "PAC" || name == "CIF") {
	return "gym";
  }
  else {
	return "";
  }
}



static char f(string name) {
    if(name == "Goose") {
      return 'G';
    }else if(name == "GRT Bus") {
      return 'B';
    }else if(name == "Tim Hortons Doughnut") {
      return 'D';
    }else if(name == "Professor") {
      return 'P';
    }else if(name == "Student") {
      return 'S';
    }else if(name == "Money") {
      return '$';
    }else if(name == "Laptop") {
      return 'L';
    }else if(name == "Pink tie") {
      return 'T';
    }else {
      return 0;
  }
}



void Board::asset() {
  cout << "Money: " << players[currentPlayer]->getMoney() << endl;
  cout << "Properties owned(mortgaged not displayed):" << endl;
  cout << players[currentPlayer]->getProperty() << endl;
  cout << "Number of Roll Up the Rim Cups:" << players[currentPlayer]->getNumCups() << endl;
}



void Board::save(string fileName) {
  ofstream ofs;
  ofs.open(fileName.c_str());
  ofs << numPlayer << endl;
  for(int i = 0; i < numPlayer; i++) {
    char c = f(players[i]->getName());
    ofs << players[i]->getName() << " " << c << " " << players[i]->getNumCups() << " " << players[i]->getMoney() << " " << playerPlaces[i];
    if(playerPlaces[i] == 10) {
      if(players[i]->isInTims()) {
        ofs << " " << 1 << " " << players[i]->getTurns();
      }else {
        ofs << " " << 0;
      }
    }
    ofs << endl;
  }
  for(int i = 0; i < 40; i++) {
    if(campus[i]->getCost()) {
      ofs << campus[i]->getName() << " ";
      if(campus[i]->getPrevOwner()) {
        ofs << campus[i]->getPrevOwner()->getName() << " -1" << endl;
      }else if(campus[i]->getOwner()) {
        ofs << campus[i]->getOwner()->getName() << " " << campus[i]->getLevel() << endl;
      }else {
        ofs << "BANK 0" << endl;
      }
    }
  }
  ofs.close();
}



void Board::load(string file, Controller *cl) {
  currentPlayer = 0;
  nextPlayer = 1;
  this->cl = cl;
  ifstream ifs(file.c_str());
  if(ifs.is_open()) {
    ifs >> numPlayer;
    players = new Player*[numPlayer];
    playerPlaces = new int[numPlayer];
    for(int i = 0; i < numPlayer; i++) {
      players[i] = new Player();
      string name;
      int cup, money, posn;
      ifs >> name;
      if(name == "Tim") {
        string more;
        ifs >> more;
        name.append(" ");
        name.append(more);
        ifs >> more;
        name.append(" ");
        name.append(more);
      }else if(name == "GRT" || name == "Pink") {
        string more;
        ifs >> more;
        name.append(" ");
        name.append(more);
      }
      players[i]->setName(name);
      ifs >> name;
      ifs >> cup >> money >> posn;
      for(int j = 0; j < cup; j++) {
        players[i]->gainCup();
      }
      players[i]->setMoney(money);
      playerPlaces[i] = posn;
      if(posn == 10) {
        int eff;
        ifs >> eff;
        if(eff) {
          players[i]->goToTims();
          int turns;
          ifs >> turns;
          for(int j = 0; j < turns - 1; j++) {
            players[i]->stall();
          }
        }
      }
    }
    for(int i = 0; i < 40; i++) {
      if(campus[i]->getCost()) {
        string name, type;
        int lvl;
        ifs >> type;
        ifs >> name;
        if(name == "Tims") {
          string more;
          ifs >> more;
          name.append(" ");
          name.append(more);
          ifs >> more;
          name.append(" ");
          name.append(more);
        }else if(name == "GRT" || name == "Pink") {
          string more;
          ifs >> more;
          name.append(" ");
          name.append(more);
        }
        ifs >> lvl;
        for(int j = 0; j < numPlayer; j++) {
          if(players[j]->getName() == name && lvl != -1) {
            players[j]->addProperty(campus[i], rezOrGym(type));
            campus[i]->setOwner(players[j]);
            campus[i]->setLevel(lvl);
          }else if(players[j]->getName() == name && lvl == -1) {
            campus[i]->setPrevOwner(players[j]);
            campus[i]->setOwner(NULL);
          }else {
            continue;
          }
        }
      }
    }
    ifs.close();
  }else {
    cout << "Incorrect file name!" << endl;
  }
}



bool Board::anyoneLoss() {
  if (this->anyLoss) {
	this->anyLoss = false;
	return true;
  }
  else {
	return false;
  }
}
