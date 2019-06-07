#include "snake.h"
#include "food.h" 
#include "tool.h"
#include "controller.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <conio.h>

Snake::Snake(){
    snake.emplace_back(14,8);
    snake.emplace_back(15,8);
    snake.emplace_back(16,8);
    direction = Direction::UP;
}

void Snake::PrintSnake(){
    for(auto &point: snake){
        point.PrintDot();
    }
}

bool Snake::ChangeDirection(){
    char ch;
    if(kbhit()){
        ch=getch();
        switch(ch){

            case -32:
                ch=getch();
                switch(ch){
                    case 72://up
                        if(direction!=DOWN)
                            direction=UP;
                        break;
                    case 80://down
                        if(direction!=UP)
                            direction=DOWN;
                        break;
                    case 75://left
                        if(direction!=RIGHT)
                            direction=LEFT;
                        break;
                    case 77://right
                        if(direction!=LEFT)
                            direction=RIGHT;
                        break;
                        
                    default:
                        break;
                }
                return true;
            case 27:
                return false;
            default:
                return true;
        }
    }
    return true;
}

void Snake::AddLengthMove(){
    switch(direction){
        case Direction::UP:
            snake.emplace_front(Point(snake.front().getx(),snake.front().gety()-1));
            break;
        case Direction::DOWN:
            snake.emplace_front(Point(snake.front().getx(),snake.front().gety()+1));
            break;
        case Direction::LEFT:
            snake.emplace_front(Point(snake.front().getx()-1,snake.front().gety()));
            break;
        case Direction::RIGHT:
            snake.emplace_front(Point(snake.front().getx()+1,snake.front().gety()));
            break;
        default:
            break;
    }
    setTextColor(14);
    snake.front().PrintDot();

}

void Snake::Move(){
    AddLengthMove();
    snake.back().ClearPoint();
    snake.pop_back();
}

bool Snake::BiteSelf(){
    int cnt=0;
    for(auto& point :snake){
        if(point.getx()==snake.front().getx()&&point.gety()==snake.front().gety()){
            ++cnt;
        }
    }
    if(cnt>=2)  return true; //ture ->has bit self
    else return false; 
}

bool Snake::GetFood(const Food& newfood){
    return snake.front().getx()==newfood.lx && snake.front().gety()==newfood.ly;
}

bool Snake::HitWall(){
    return snake.front().getx()>=30||
            snake.front().getx()<=1||
            snake.front().gety()>=30||
            snake.front().gety()<=1;//true->has hit wall
}
