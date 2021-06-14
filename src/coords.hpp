#pragma once

struct coords{
    int x, y, vx, vy;
    coords(){};
    coords(int x, int y, int vx = 0, int vy = 0){
        this->x = x;
        this->y = y;
        this->vx = vx;
        this->vy = vy;
    }
};