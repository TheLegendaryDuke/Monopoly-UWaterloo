#include "controller.h"

using std::string;

int main(int ARGV, char* ARGC[]) {
  if(ARGV == 3) {
    string cmd = ARGC[1];
    string file = ARGC[2];
    Controller c;
    c.play(cmd, file);
  }else {
    Controller c;
    string a = "new";
    c.play(a,a);
  }
}
