#ifndef __RURCUP_H__
#define __RURCUP_H__
class RURCup {
  static int numCup; //number of cups present
  RURCup();
public:
  static RURCup* getCup(); // get a new cup, returns 0 if cup number is 4
  ~RURCup();// dtor
};
#endif
