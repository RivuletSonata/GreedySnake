#include <bits/stdc++.h>
#include <windows.h>
#include "food.h"
#include "tool.h"
#include "snake.h"
#include "controller.h"


void Food::PrintFood(){
    setCursorLocation(lx,ly);
    setTextColor(6);
    std::cout<<"x";
}

void Food::GenerateFood(Snake &newsnake){
    bool isoverlap=false;//
    int temp_x;
    int temp_y;
    while(true){
    	temp_x=rand()%28+2;
    	temp_y=rand()%28+2;
        for(auto& point: newsnake.snake){
            if(temp_x==point.getx() && temp_y==point.gety() ){
                isoverlap=true;
                break;
            }
        } 
        if(isoverlap)   continue;
        else break;
    }
    lx=temp_x;
    ly=temp_y;
}
