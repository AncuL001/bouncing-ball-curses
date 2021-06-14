#pragma once

#include "coords.hpp"
#include <curses.h>
#include <chrono>
#include <thread>

void print_border(const coords size);
void animation(const coords size);
void detect_border(const coords size, coords &dot);