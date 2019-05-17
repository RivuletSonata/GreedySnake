#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include "tool.h"

class Snake;
class Food{
	friend class Snake;
    public:
        Food():lx(0),ly(0){};
        void PrintFood();
        void GenerateFood(Snake& newsnake);
        int GetX(){return this->lx;};
        int GetY(){return this->ly;};
    private:
        int lx;
        int ly;
};


#endif
