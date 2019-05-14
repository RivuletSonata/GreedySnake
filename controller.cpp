#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "map.h"
#include "food.h"
#include "snake.h"

void Controller::Welcome(){
    setwindowsize(40,32);
    setTextColor(2);
//May Insert action 
    setCursorLocation(13,10);
    std::cout<<"Welcome to Greedy Snake!";
    setCursorLocation(13,20);
    std::cout << "Press any key to start... " ;
    setCursorLocation(13,21);
    system("pause");
}

void Controller::Select(){
    setTextColor(3);
    setCursorLocation(13,10);
    std::cout << "请使用上下按键选择模式，并用回车确认:";

    setCursorLocation(13,13);
    setBackgroundColor();
    
	std::cout << "1.简单模式" ;
    //setTextColor(3);
    setCursorLocation(13,14);
	std::cout << "2.正常模式" ;
    setCursorLocation(13,15);
	std::cout << "3.困难模式" ;
    setCursorLocation(13,16);
	std::cout << "4.噩梦模式" ;

    bool isenter=false;
    mode=1;
    int ch=1;
    while(ch=getch()){
        switch (ch){
            case 72://upmode
                if(mode>1){
                    switch (mode)
                    {
                    case 2:
                        setCursorLocation(13,13);
                        setBackgroundColor();
                        std::cout << "1.简单模式" ;

                        setCursorLocation(13,14);
                        setTextColor(3);
                        std::cout<<"2.正常模式";
                        --mode;
                        break;
                    
                    case 3:
                        setCursorLocation(13,14);
                        setBackgroundColor();
                        std::cout<<"2.正常模式";

                        setCursorLocation(13,15);
                        setTextColor(3);
                        std::cout << "3.困难模式" ;
                        --mode;
                        break;
                    
                    case 4:
                        setCursorLocation(13,15);
                        setBackgroundColor();
                        std::cout<<"3.困难模式";

                        setCursorLocation(13,16);
                        setBackgroundColor();
                        std::cout<<"4.噩梦模式";
                        --mode;
                        break;
                    }
                }
                break;
        
            case 80://down mode
                if(mode<4){
                    switch (mode)
                    {
                    case 1:
                        setCursorLocation(13,14);//uplight
                        setBackgroundColor();
                        std::cout << "2.正常模式" ;

                        setCursorLocation(13,13);//cancel background color
                        setTextColor(3);
                        std::cout<<"1.简单模式";
                        ++mode;
                        break;
                    
                    case 2:
                        setCursorLocation(13,15);
                        setBackgroundColor();
                        std::cout<<"3.困难模式";

                        setCursorLocation(13,14);
                        setTextColor(3);
                        std::cout<<"2.正常模式";
                        ++mode;
                        break;
                    
                    case 3:
                        setCursorLocation(13,16);
                        setBackgroundColor();
                        std::cout<<"4.噩梦模式";

                        setCursorLocation(13,15);
                        setBackgroundColor();
                        std::cout<<"3.困难模式";
                        ++mode;
                        break;
                    }
                }
               break;
            case 13://Enter回车键
                isenter = true;
                break;
            default://无效按键
                break;  
        }
        if (isenter) break;
    }
    setCursorLocation(31,31);
    
}

void Controller::InitMap(){
    system("cls");
    
    Map *newmap= new Map();
    newmap->DrawMap();
    delete newmap;

    setTextColor(3);
    setCursorLocation(33,1);
    std::cout<<"Greedy Snake";
    setCursorLocation(32,3);
    std::cout<<"Difficulty:";
    setCursorLocation(33,5);
    switch(mode){
        case 1:
            std::cout<<"简单模式";
            break;
        case 2:
            std::cout<<"普通模式";
            break;
        case 3:
            std::cout<<"困难模式";
            break;
        case 4:
            std::cout<<"噩梦模式";
            break;
        default:
            break;
    }
    setCursorLocation(31, 7);
    std::cout << "得分：" ;
    setCursorLocation(37, 8);
    std::cout << "     0" ;
    setCursorLocation(33, 13);
    std::cout << " 方向键移动" ;
    setCursorLocation(33, 15);
    std::cout << " ESC键暂停" ;
}

int Controller::RunningGame(){
    Snake *newsnake=new Snake();
    //Food *;
    setTextColor(6);
    newsnake->PrintSnake();

    //newfood->PrintFood();
    while(!newsnake->HitWall()&&!newsnake->BiteSelf()){
        if(!newsnake->ChangeDirection()){

        }
        if(false){

        }
        else    newsnake->Move();


        Sleep(speed);
    }
    delete newsnake;
    int k;
    std::cout<<"Game Over. 1: restart; 2:Leave.";
    std::cin>>k;
    return k;
}

void Controller::Menu(){

}

void Controller::SetSpeed(){
    switch (mode)
    {
    case 1:
        speed=130;
        break;
    case 2:
        speed=95;
        break;

    case 3:
        speed=60;
        break;
    case 4:
        speed=35;
        break;
    default:
        break;
    }
}

void Controller::Game(){
    Welcome();
    while(true){
        Select();
        InitMap();

        int temp=RunningGame();
        if(temp==1){
            system("cls");
            continue;
        }
        if(temp==2){
            break;
        }
        else break;
    }

}