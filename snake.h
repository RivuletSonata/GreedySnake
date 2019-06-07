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
        enum Direction{UP ,DOWN, RIGHT, LEFT};//枚举方向
        void PrintSnake();//打印蛇
        void AddLengthMove();//加长身体的移动
        void Move();//普通移动
        bool BiteSelf();//判定是否咬到自己
        bool HitWall();//判定是否撞到墙
        bool GetFood(const Food& );//判定是否吃到食物
        bool ChangeDirection();//改变方向
    private:
        Direction direction;//方向变量
        std::deque<Point> snake;
};

#endif

