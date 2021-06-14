#include "animation.hpp"

void print_border(coords size){
  for (int i = 0; i < size.x + 2; i++){
    if (i == 0 || i == size.x + 1){
      printw("+");
      continue;
    }
    printw("-");
  }

  printw("\n");

  for (int i = 1; i <= size.y; i++){
    mvaddch(i, 0, '|');
    mvaddch(i, size.x + 1, '|');
  }

  printw("\n");

  for (int i = 0; i < size.x + 2; i++){
    if (i == 0 || i == size.x + 1){
      printw("+");
      continue;
    }
    printw("-");
  }
  refresh();
}

void animation(const coords size){
  noecho();
  coords dot(1, 1, 1, 1);
  mvaddch(dot.y, dot.x, 'o');
  refresh();
  
  while (true){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    mvaddch(dot.y, dot.x, ' ');

    detect_border(size, dot);
    
    dot.x += dot.vx;
    dot.y += dot.vy;
    
    mvaddch(dot.y, dot.x, 'o');
    move(size.y + 1, size.x + 1);
    refresh();
  }
}

void detect_border(const coords size, coords &dot){
  if (size.x == 1) dot.vx = 0;
  else if (dot.x == 1) dot.vx = 1;
  else if (dot.x == size.x) dot.vx = -1;

  if (size.y == 1) dot.vy = 0;
  else if (dot.y == 1) dot.vy = 1;
  else if (dot.y == size.y) dot.vy = -1;
}