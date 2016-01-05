#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include "view.h"
#include "controller.h"


class TextDisplay:public View {
  Controller *c;//access to the controller
public:
  TextDisplay(Controller* c);
  void print(); // print the board
  void anyone(int); // a helper for print
  void buildingL(int, int, char); // a helper for print
  void owner(int); // a helper for print
};

#endif
