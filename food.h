#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include "tool.h"

class Snake;
class Food{
	friend class Snake;
    public:
        Food():lx(0),ly(0){};
        void PrintFood();//打印食物
        void GenerateFood(Snake& newsnake);//生成食物
        int GetX(){return this->lx;};//返回坐标
        int GetY(){return this->ly;};
    private:
        int lx;
        int ly;
};

#endif
