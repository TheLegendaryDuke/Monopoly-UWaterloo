#include "rurcup.h"

using namespace std;

int RURCup::numCup = 0;

RURCup::RURCup() {}
RURCup::~RURCup() {
  numCup--;
}
RURCup* RURCup::getCup() {
  if(numCup < 4) {
    numCup++;
    return new RURCup;
  }else {
    return 0;
  }
}
