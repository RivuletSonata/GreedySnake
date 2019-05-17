#ifndef SNAKE_H
#define SNAKE_H

#include"tool.h"
#include"food.h"
#include<bits/stdc++.h>

class Food;
class Snake{
	friend class Food;
    public:
        Snake();
        enum Direction{UP ,DOWN, RIGHT, LEFT};
        void PrintSnake();
        void setSnakeSpeed(int mode);
        void AddLengthMove();
        void Move();
        bool BiteSelf();
        bool HitWall();
        bool GetFood(const Food& );
        bool ChangeDirection();
    private:
        int speed;
        Direction direction;
        std::deque<Point> snake;
};

#endif
