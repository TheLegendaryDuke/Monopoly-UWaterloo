#include "special.h"

void Special::setOwner(Player *o = NULL) {}
int Special::getCost() {return 0;}
Special::~Special() {}
Special::Special(std::string name): Place(name, -1, 0, 0) {}
