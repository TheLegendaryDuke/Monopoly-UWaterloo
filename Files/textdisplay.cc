#include "textdisplay.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

TextDisplay::TextDisplay(Controller *c): c(c) {}

void space() {
  cout <<"|";
  for(int i = 0; i < 8; i++) {
    cout << " ";
  }
}
void mid() {
  cout <<"|";
  for(int i = 0; i < 8; i++) {
    cout << "-";
  }
}
void btm() {
  cout << "|";
  for(int i = 0; i < 8; i++) {
    cout << "_";
  }
}
void empty() {
  for(int i = 0; i < 72; i++) {
    cout << " ";
  }
}
void end() {
  cout << "|" << endl;
}
void emptyL() {
  space();
  space();
  empty();
  space();
  end();
}
void btmL() {
  btm();
  space();
  empty();
  btm();
  end();
}
void midL() {
  mid();
  space();
  empty();
  mid();
  end();
}
void stfL(string l, string r) {
  cout << "|";
  cout << setfill(' ') << setw(8) << left << l;
  space();
  empty();
  cout << "|";
  cout << setfill(' ') << setw(8) << left << r;
  end();
}
void lvl(int x) {
  if(x == 5) {
    cout << "|   V    ";
    return;
  }
  string l = "|";
  for(int i = 0; i < x; i++) {
    l.append("I");
  }
  cout << setw(9) << setfill(' ') << left << l;
}
static string convert(string name) {
    if(name == "Goose") {
      return "G";
    }else if(name == "GRT Bus") {
      return "B";
    }else if(name == "Tim Hortons Doughnut") {
      return "D";
    }else if(name == "Professor") {
      return "P";
    }else if(name == "Student") {
      return "S";
    }else if(name == "Money") {
      return "$";
    }else if(name == "Laptop") {
      return "L";
    }else if(name == "Pink tie") {
      return "T";
    }else {
      return "";
  }
}
void TextDisplay::anyone(int place) {
  string ppl = "|";
  for(int i = 0; i < c->getNumPlayers(); i++) {
    if(c->getPosn(i) == place) {
      ppl.append(convert(c->getPlayerName(i)));
    }
  }
  cout << setw(9) << setfill(' ') << left << ppl;
}
void TextDisplay::buildingL(int l, int r, char ch = ' ') {
  lvl(c->getPlaceLevel(l));
  space();
  empty();
  lvl(c->getPlaceLevel(r));
  end();
  midL();
  string a = "|";
  a.append(c->getPlaceName(l));
  a.append("(");
  a.append(convert(c->getPlaceOwner(l)));
  a.append(")");
  cout << setw(9) << setfill(' ') << left << a;
  space();
  empty();
  a = "|";
  a.append(c->getPlaceName(r));
  a.append("(");
  a.append(convert(c->getPlaceOwner(r)));
  a.append(")");
  cout << setw(9) << setfill(' ') << left << a;
  end();
  anyone(l);
  space();
  empty();
  anyone(r);
  end();
  btm();
  cout << "|";
  for(int i = 0; i < 80; i++) cout << ch;
  btm();
  end();
}
void TextDisplay::owner(int n) {
  string x = "|";
  x.append(c->getPlaceName(n));
  x.append("(");
  x.append(convert(c->getPlaceOwner(n)));
  x.append(")");
  cout << setw(9) << setfill(' ') << left << x;
}
void TextDisplay::print() {
  for(int i = 0; i < 100; i++) {
    cout << "_";
  }
  cout << endl;
  cout << "|Goose   ";
  lvl(c->getPlaceLevel(21));
  cout << "|NEEDLES ";
  lvl(c->getPlaceLevel(23));
  lvl(c->getPlaceLevel(24));
  owner(25);
  lvl(c->getPlaceLevel(26));
  lvl(c->getPlaceLevel(27));
  owner(28);
  lvl(c->getPlaceLevel(29));
  cout << "|GO TO   ";
  end();
  cout << "|Nesting ";
  mid();
  cout << "|HALL    ";
  mid();
  mid();
  space();
  mid();
  mid();
  space();
  mid();
  cout << "|TIMS    ";
  end();
  space();
  owner(21);
  space();
  owner(23);
  owner(24);
  space();
  owner(26);
  owner(27);
  space();
  owner(29);
  space();
  end();
  for(int i = 20; i < 31; i++) {
    anyone(i);
  }
  end();
  for(int i = 20; i < 31; i++) {
    btm();
  }
  end();
  buildingL(19, 31);
  buildingL(18, 32);
  stfL("SLC", "SLC");
  anyone(17);
  space();
  empty();
  anyone(33);
  end();
  emptyL();
  emptyL();
  btmL();
  buildingL(16, 34);
  owner(15);
  cout << "|";
  for(int i = 0; i < 19; i++) {
    cout << " ";
  }
  for(int i = 0; i < 41; i++) {
    cout << "_";
  } 
  for(int i = 0; i < 20; i++) {
    cout << " ";
  }
  owner(35);
  end();
  anyone(15);
  cout << "|";
  for(int i = 0; i < 19; i++) {
    cout << " ";
  }
  cout << "|";
  for(int i = 0; i < 39; i++) {
    cout << " ";
  }
  cout << "|";
  for(int i = 0; i < 20; i++) {
    cout << " ";
  }
  anyone(35);
  end();
  space();
  cout << "|";
  for(int i = 0; i < 19; i++) {
    cout << " ";
  }
  cout << "|  ###   ###   #####  ###   ###   ###   |";
  for(int i = 0; i < 20; i++) {
    cout << " ";
  }
  space();
  end();
  space();
  cout << "|";
  for(int i = 0; i < 19; i++) {
    cout << " ";
  }
  cout << "|  #  #  #  #     #  #   # #   # #   #  |";
  for(int i = 0; i < 20; i++) {
    cout << " ";
  }
  space();
  end();
  btm();
  cout << "|";
  for(int i = 0; i < 19; i++) {
    cout << " ";
  }
  cout << "|  ####  ####    #   #   # #   # #   #  |";
  for(int i = 0; i < 20; i++) {
    cout << " ";
  }
  btm();
  end();
  lvl(c->getPlaceLevel(14));
  cout << "|";
  for(int i = 0; i < 19; i++) cout << " ";
  cout << "|  #   # #   #  #    #   # #   # #   #  |";
  for(int i = 0; i < 20; i++) cout << " ";
  cout << "|NEEDLES ";
  end();
  mid();
  cout << "|";
  for(int i = 0; i < 19; i++) cout << " ";
  cout << "|  ####  ####  #      ###   ###   ###   |";
  for(int i = 0; i < 20; i++) cout << " ";
  cout << "|HALL    ";
  end();
  owner(14);
  cout << "|";
  for(int i = 0; i < 19; i++) cout << " ";
  cout << "|";
  for(int i = 0; i < 39; i++) cout << "_";
  cout << "|";
  for(int i = 0; i < 20; i++) cout << " ";
  anyone(36);
  end();
  anyone(14);
  space();
  empty();
  space();
  end();
  btmL();
  buildingL(13, 37);
  owner(12);
  space();
  empty();
  cout << "|COOP    ";
  end();
  anyone(12);
  space();
  empty();
  cout << "|FEE     ";
  end();
  space();
  space();
  empty();
  anyone(38);
  end();
  emptyL();
  btmL();
  buildingL(11, 39, '_');
  cout << "|DC Tims ";
  lvl(c->getPlaceLevel(9));
  lvl(c->getPlaceLevel(8));
  cout << "|NEEDLES ";
  lvl(c->getPlaceLevel(6));
  owner(5);
  cout << "|TUITION ";
  lvl(c->getPlaceLevel(3));
  cout << "|SLC     ";
  lvl(c->getPlaceLevel(1));
  cout << "|COLLECT ";
  end();
  cout << "|Line    ";
  mid();
  mid();
  cout << "|HALL    ";
  mid();
  space();
  space();
  mid();
  space();
  mid();
  cout << "|OSAP    ";
  end();
  space();
  owner(9);
  owner(8);
  space();
  owner(6);
  space();
  space();
  owner(3);
  space();
  owner(1);
  space();
  end();
  for(int i = 10; i > -1; i--) anyone(i);
  end();
  for(int i = 0; i < 11; i++) btm();
  end();
  cout << endl << endl;
  for(int i = 0; i < c->getNumPlayers(); i++) {
    cout << "Player " << i + 1 << ":    ";
  }
  cout << endl;
  for(int i = 0; i < c->getNumPlayers(); i++) {
    cout << "Piece: " << convert(c->getPlayerName(i)) << "     ";
  }
  cout << endl;
  for(int i = 0; i < c->getNumPlayers(); i++) {
    cout << "Money: ";
    cout << setw(6) << setfill(' ') << c->getPlayerMoney(i);
  }
  cout << endl;
  for(int i = 0; i < c->getNumPlayers(); i++) {
    cout << "RURCups: ";
    cout << setw(4) << setfill(' ') << c->getPlayerCups(i);
  }
  cout << endl << endl;
  cout << "Legend:" << endl;
  cout << "G:       Goose" << endl;
  cout << "B:       GRT Bus" << endl;
  cout << "D:       Tims Hortons Doughnut" << endl;
  cout << "P:       Professor" << endl;
  cout << "S:       Student" << endl;
  cout << "$:       Money" << endl;
  cout << "L:       Laptop" << endl;
  cout << "T:       Pink tie" << endl;
  cout << "RURCups: Roll Up the Rim Cup" << endl << endl << endl;
}
