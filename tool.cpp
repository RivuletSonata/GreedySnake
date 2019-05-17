#include "tool.h"
#include <windows.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void setBackgroundColor(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}

void setTextColor(int colorid){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
                            colorid);
}

void setwindowsize(int cols,int lines){
    system("title GreedySnake");
    char cmd[30];
    sprintf(cmd,"mode con cols=%d lines=%d", cols * 2, lines);
    system(cmd);
}

void setCursorLocation(int x,int y){
    COORD loc;
	loc.X = x; loc.Y = y;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, loc);
}

void Point::Print(){
    setCursorLocation(x,y);
    cout<<"#";
}

void Point::PrintDot(){
    setCursorLocation(x,y);
    cout<<"o";
}
void Point::ChangePoint(const int x,const int y){
    this->x=x;
    this->y=y;
}
void Point::ClearPoint(){
    setCursorLocation(x,y);
    cout<<" ";   
}