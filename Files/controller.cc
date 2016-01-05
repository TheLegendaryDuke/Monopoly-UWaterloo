#include "controller.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Controller::setRolled(bool r) {
  rolled = r;
}

bool Controller::unmort(string place) {
  cout << "Do you want to unmortgage " << place << "?(y/n)" << endl;
  string ans;
  cin >> ans;
  if(ans == "y") {
    return true;
  }else if(ans == "n") {
    return false;
  }else {
    cout << "Invalid answer." << endl;
    return unmort(place);
  }
}

int Controller::getNumPlayers() {
  return board->getNumPlayers();
}
string Controller::getPlaceName(int n) {
  return board->getPlaceName(n);
}
string Controller::getPlayerName(int n) {
  return board->getPlayerName(n);
}
int Controller::getPlayerMoney(int n) {
  return board->getPlayerMoney(n);
}
int Controller::getPlayerCups(int n) {
  return board->getPlayerCups(n);
}
int Controller::getPosn(int n) {
  return board->getPosn(n);
}
string Controller::getPlaceOwner(int n) {
  return board->getPlaceOwner(n);
}
int Controller::getPlaceLevel(int n) {
  return board->getPlaceLevel(n);
}

void Controller::pay(int cost, string type) {
  cout << "You paid $" << cost << " as " << type << endl;
}
void Controller::init() {
  cout << "Enter the number of players to start a new game." << endl;
  int n;
  cin >> n;
  while(n > 8 || n < 2) {
    cout << "Incorrect number of players." << endl << "Please enter a number between 2 and 8." << endl;
    if(cin.fail()) {
      cin.clear();
      cin.ignore();
    }
    cin >> n;
  }
  board->init(n, this);
}
bool Controller::tuitionOrWorth() {
  cout << "Do you want to pay $300 or 10" << "%" << " of your total worth?($/%)" << endl;
  char ans;
  cin >> ans;
  if(ans == '%') {
    return true;
  }else if(ans == '$') {
    return false;
  }else {
    cout << "Invalid input." << endl;
    return tuitionOrWorth();
  }
}
int Controller::rollPayCup(bool roll) {
  if(!roll) {
    cout << "Do you want to pay money or use a cup to get out of Tims Line?(cup/$)"<< endl;
    string ans;
    cin >> ans;
    if(ans == "$") {
      return 2;
    }else if(ans == "cup") {
      return 3;
    }else {
      cout << "Invalid answer." << endl;
      return rollPayCup(roll);
    }
  }else {
    cout << "Do you want to roll the dices(roll), pay $50($), or use a cup(cup) to get out of the Tims Line?" << endl;
    string ans;
    cin >> ans;
    if(ans == "roll") {
      return 1;
    }else if(ans == "$") {
      return 2;
    }else if(ans == "cup") {
      return 3;
    }else {
      cout << "Invalid input." << endl;
      return rollPayCup(roll);
    }
  }
}
int Controller::requestPlayerName(int n) {
  cout << "Please choose the piece for player no." << n + 1 << endl;
  char p;
  cin >> p;
  switch (p) {
    case 'G':
      return 1;
    case 'B':
      return 2;
    case 'D':
      return 3;
    case 'P':
      return 4;
    case 'S':
      return 5;
    case '$':
      return 6;
    case 'L':
      return 7;
    case 'T':
      return 8;
    default:
      cout << "Invalid input." << endl;
      return requestPlayerName(n);
  }
}
int Controller::roll() {
  srand(time(NULL));
  cout << "Rolling dice..." << endl;
  int a = rand() % 6 + 1;
  int b = rand() % 6 + 1;
  cout << "You rolled a " << a << " and a " << b << endl;
  return a * 10 + b;
}
void Controller::move() {
  string winner = board->win();
  if(winner != "") {
    return;
  }
  if(board->isInTims()) {
    board->move(0, 0);
    return;
  }
  int dice = roll();
  board->move(dice / 10, dice % 10);
  winner = board->win();
  if(board->anyoneLoss()) {
    rolled = false;
    return;
  }
  for(int i = 0; i < 3; i++) {
    if(dice / 10 == dice % 10) {
      if(board->isInTims()) return;
      cout << "You have rolled a double!!!" << endl;
      if(i == 2) {
        cout << "You are too lucky for a mortal. You have been punished by the gods to go to DC Tims Line!!!" << endl;
        board->goToTims();
        rolled = true;
        return;
      }
      cout << "Do you want to continue to roll?(y/n)" << endl;
      string ans;
      cin >> ans;
      if(ans == "n") {
        cout << "Do you want to upgrade this property?(y/n)" << endl;
        cin >> ans;
        if(ans == "y") {
          cout << "How many levels do you want to buy?" << endl;
          int x;
          cin >> x;
          while(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input." << endl;
            cin >> x;
          }
          board->upgrade(x);
        }else {
          cout << "Automatically rolling." << endl;
        }
      }
      dice = roll();
      board->move(dice / 10, dice % 10);
    }
  }
  rolled = true;
}
bool Controller::buy() {
  cout << "Do you want to buy this property?(y/n)" << endl;
  string a;
  cin >> a;
  if(a == "y") {
    return true;
  }else if(a == "n") {
    return false;
  }else {
    cout << "Invalid answer." << endl;
    return buy();
  }
}
static bool g(string name) {
  if(name == "G" || name == "B" || name == "D" || name == "P" || name == "S" || name == "$" || name == "L" || name == "T") {
    return true;
  }else {
    return false;
  }
}
void Controller::auction(string place) {
  cout << "Auction starts!" << endl;
  cout << "Property on sale: " << place << endl;
  int turn = 0;
  int price = 0;

  int bidders[board->getNumPlayers()];
  for(int i = 0; i < board->getNumPlayers(); i++) {
    bidders[i] = 1;
  }
  while(true) {
    if(turn == board->getNumPlayers()) {
      turn = 0;
    }
    if(!bidders[turn]) {
      turn++;
      continue;
    }
    int valid = 0;
    for(int i = 0; i < board->getNumPlayers(); i++) {
      if(bidders[i]) valid++;
    }
    if(valid == 1) {
      cout << "Auction finished." << endl;
      cout << board->getPlayerName(turn) << " won." << endl;
      board->wonBid(board->getPlayerName(turn), price, place);
      return;
    }
    cout << "Highest bid: " << price << endl;
    cout << "It's now " << board->getPlayerName(turn) << "'s turn to bid." << endl;
    cout << "How much are you willing to bid? (enter -1 to withdraw from the auction)" << endl;
    int offer;
    cin >> offer;
    while(cin.fail()) {
      cout << "Invalid input." << endl;
      cin.clear();
      cin.ignore();
      cin >> offer;
    }
    while(offer != -1 && (offer <= price || offer > board->getPlayerMoney(turn))) {
      if(offer <= price) {
        cout << "You must make a bid higher than the highest bid." << endl;
        cin >> offer;
      }else {
        cout << "You are bidding more than you own!" << endl;
        cout << "Please reenter your bid." << endl;
        cin >> offer;
      }
      while(cin.fail()) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore();
        cin >> offer;
      }
    }
    if(offer == -1) {
      bidders[turn] = 0;
      turn++;
      continue;
    }
    price = offer;
    turn++;
  }
}
int Controller::mortgage() {
  cout << "Enter the property you want to mortgage:" << endl;
  string property;
  cin >> property;
  int result = board->mortgage(property);
  while(true) {
    if(result == 0) {
      cout << "Enter the property you want to mortgage or " << "\"cancel\"" << "to cancel." << endl;
      cin >> property;
      if(property == "cancel") {
        return 0;
      }
      result = board->mortgage(property);
    }else {
      cout << "You have successfully mortgaged " << property << " for $" << result << endl;
      return result;
    }
  }
}
int Controller::noMoney(int money) {
  cout << "You do not have enough money. (need $" << money << " more) What would you like to do? (mortgage?trade?bankrupt?sell(improvement)?)" << endl;
  string decision;
  cin >> decision;
  if(decision == "bankrupt") {
    return 0;
  }else if(decision == "sell") {
    cout << "Enter the name of the property the improvement belongs to." << endl;
    string name;
    cin >> name;
    cout << "Now enter the number of levels you want to sell." << endl;
    int level;
    cin >> level;
    int ans;
    ans = board->sell(name, level);
    if(ans) {
      cout << "Sale successful." << endl;
      return ans;
    }else {
      cout << "Sale failed." << endl;
      return noMoney(money);
    }
  }else if(decision == "trade") {
    string name;
    do {
      cout << "Enter the player you want to trade with:" << endl;
      cin >> name;
      if(name == "Tim") {
        string more;
        cin >> more;
        name.append(" ");
        name.append(more);
        cin >> more;
        name.append(" ");
        name.append(more);
      }else if(name == "GRT" || name == "Pink") {
        string more;
        cin >> more;
        name.append(" ");
        name.append(more);
      }
    }while(!(g(name))); 
    string property;
    cout << "Enter the property you want to trade:" << endl;
    cin >> property;
    cout << "Enter how much you want to trade it for:" << endl;
    string inmoney;
    cin >> inmoney;
    cout << name << ", do you agree to trade?(y/n)" << endl;
    char dec;
    cin >> dec;
    if(dec == 'y') {
      board->trade(name, property, inmoney);
    }else {
      cout << "Motion denied." << endl;
      return noMoney(money);
    }
  }else if(decision == "mortgage") {
    cout << "Please enter the property you want to mortgage." << endl;
    string in;
    cin >> in;
    int res;
    res = board->mortgage(in);
    while(!res) {
      cout << "mortgage failed, enter a new property or \"cancel\" to cancel." << endl;
      cin >> in;
      if(in == "cancel") {
        return noMoney(money);
      }else {
        res = board->mortgage(in);
      }
    }
  }else {
    cout << "Invalid command." << endl;
    return  noMoney(money);
  }
}
Controller::~Controller() {
  delete board;
  delete td;
}
void Controller::play(string cmd, string fileName = "") {
  board = new Board;
  td = new TextDisplay(this);
  if(cmd == "-load") {
    board->load(fileName, this);
    cout << "Loading completed." << endl;
    cout << "There are currently " << board->getNumPlayers() << " players in the game." << endl;
  }else {
    init();
  } 
  rolled = false;
  string command;
  while(true) {
    string winner = board->win();
    if(winner != "") {
      cout << winner << " won!!!" << endl;
      break;
    }else {
      cout << "Please enter a command." << endl;
    }
    cin >> command;
    if(command == "roll") {
      if(rolled) {
        cout << "You cannot roll anymore." << endl;
      }else {
        move();
      }
    }else if(command == "quit") {
      break;
    }else if(command == "next") {
      board->next();
      rolled = false;
    }else if(command == "trade") {
      string name;
      string give;
      string receive;
      cout << "Enter the player you want to trade with." << endl;
      cin >> name;
      if(name == "Tim") {
        string more;
        cin >> more;
        name.append(" ");
        name.append(more);
        cin >> more;
        name.append(" ");
        name.append(more);
      }else if(name == "GRT" || name == "Pink") {
        string more;
        cin >> more;
        name.append(" ");
        name.append(more);
      }
      cout << "Enter the property or amount of money you want to give." << endl;
      cin >> give;
      cout << "Enter the property or amount of money you'd like to receive for it." << endl;
      cin  >> receive;
      cout << name << ", do you agree to trade?(y/n)" << endl;
      char ans;
      cin >> ans;
      if(ans == 'y') {
        if(board->trade(name, give, receive)) {
          cout << "Trade successful." << endl;
        }else {
          cout << "Trade failed." << endl;
        }
      }else {
        cout << "Motion Denied." << endl;
      }
    }else if(command == "improve") {
      string option;
      cin >> option;
      if(option == "buy") {
        cout << "How many levels would you like to upgrade the property by?" << endl;
        int x;
        cin >> x;
        board->upgrade(x);
      }else if(option == "sell") {
        cout << "Enter the name of the property the improvement belongs to." << endl;
        string name;
        cin >> name;
        cout << "Now enter the number of levels you want to sell." << endl;
        int level;
        cin >> level;
        while(cin.fail()) {
          cin.clear();
          cin.ignore();
          cout << "Please enter a number." << endl;
          cin >> level;
        }
        int ans;
        ans = board->sell(name, level);
        if(ans) {
          cout << "Sale successful." << endl;
        }else {
          cout << "Sale failed." << endl;
        }
      }
    }else if(command == "mortgage") {
      mortgage();
    }else if(command == "unmortgage") {
      string name;
      cout << "Enter the property you want to unmortgage." << endl;
      cin >> name;
      if(board->unmortgage(name)) {
        cout << "Property unmortgaged." << endl;
      }else {
        cout << "Motion denied." << endl;
      }
    }else if(command == "asset") {
      board->asset();
    }else if(command == "save") {
      string fname;
      cin >> fname;
      board->save(fname);
    }else if(command == "print") {
      td->print();
    }else{
      cout << "Invalid command" << endl;
    }//if
  }// while


}
