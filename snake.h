#ifndef SNAKE_H
#define SNAKE_H

#include"tool.h"
#include<bits/stdc++.h>
class Snake{
    public:
        Snake();
        enum Direction{UP ,DOWN, RIGHT, LEFT};
        void PrintSnake();
        void setSnakeSpeed(int mode);
        void AddLengthMove();
        void Move();
        bool BiteSelf();
        bool HitWall();
        bool GetFood();
        bool ChangeDirection();
    private:
        int speed;
        Direction direction;
        std::deque<Point> snake;
};

#endif