#include "init.hpp"

coords init(){
  coords size;
  char *x, *y;
  printw("x dimension : ");
  refresh();
  getstr(x);
  printw("y dimension : ");
  refresh();
  getstr(y);
  clear();

  try {
    std::string x_str = x;
    size.x = std::stoi(x_str);
    
    std::string y_str = y;
    size.y = std::stoi(y_str);
  }
  catch (std::invalid_argument& e) {
    printw(e.what());
    getch();
    endwin();
  }
  return size;
}