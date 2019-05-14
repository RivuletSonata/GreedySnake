#include "snake.h"
#include "tool.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <conio.h>
using namespace std;

Snake::Snake(){
    snake.emplace_back(14,8);
    snake.emplace_back(15,8);
    snake.emplace_back(16,8);
    direction = Direction::DOWN;
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

}

void Snake::Move(){

}
