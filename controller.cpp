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
    std::cout << "Use Direction Key to choose mode and tap enter to confirm:";

    setCursorLocation(13,13);
    setBackgroundColor();
    
	std::cout << "1.Easy Mode" ;
    setTextColor(3);
    setCursorLocation(13,14);
	std::cout << "2.Ordinary Mode" ;
    setCursorLocation(13,15);
	std::cout << "3.Hard Mode" ;
    setCursorLocation(13,16);
	std::cout << "4.Nightmare Mode" ;

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
                        std::cout << "1.Easy Mode" ;

                        setCursorLocation(13,14);
                        setTextColor(3);
                        std::cout<<"2.Ordinary Mode";
                        --mode;
                        break;
                    
                    case 3:
                        setCursorLocation(13,14);
                        setBackgroundColor();
                        std::cout<<"2.Ordinary Mode";

                        setCursorLocation(13,15);
                        setTextColor(3);
                        std::cout << "3.Hard Mode" ;
                        --mode;
                        break;
                    
                    case 4:
                        setCursorLocation(13,15);
                        setBackgroundColor();
                        std::cout<<"3.Hard Mode";

                        setCursorLocation(13,16);
                        setTextColor(3);
                        std::cout<<"4.Nightmare Mode";
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
                        std::cout << "2.Ordinary Mode" ;

                        setCursorLocation(13,13);//cancel background color
                        setTextColor(3);
                        std::cout<<"1.Easy Mode";
                        ++mode;
                        break;
                    
                    case 2:
                        setCursorLocation(13,15);
                        setBackgroundColor();
                        std::cout<<"3.Hard Mode";

                        setCursorLocation(13,14);
                        setTextColor(3);
                        std::cout<<"2.Ordinary Mode";
                        ++mode;
                        break;
                    
                    case 3:
                        setCursorLocation(13,16);
                        setBackgroundColor();
                        std::cout<<"4.Nightmare Mode";

                        setCursorLocation(13,15);
                        setTextColor(3);
                                 
                        std::cout<<"3.Hard Mode";
                        ++mode;
                        break;
                    }
                }
               break;
            case 13://Enter
                isenter = true;
                break;
            default://inavailable
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
    setCursorLocation(34,1);
    std::cout<<"Greedy Snake";
    setCursorLocation(34,3);
    std::cout<<"Difficulty:";
    setCursorLocation(34,5);
    switch(mode){
        case 1:
            std::cout<<"Easy Mode";
            break;
        case 2:
            std::cout<<"Ordinary Mode";
            break;
        case 3:
            std::cout<<"Hard Mode";
            break;
        case 4:
            std::cout<<"Nightmare Mode";
            break;
        default:
            break;
    }
    setCursorLocation(34, 7);
    std::cout << "Score:" ;
    setCursorLocation(34, 8);
    std::cout << "     0" ;
    setCursorLocation(34, 10);
    std::cout << " Move by Direction Key" ;
    setCursorLocation(33, 11);
    std::cout << " ESC to Pause" ;
}

int Controller::RunningGame(){
    
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(hOut,&CursorInfo);
    CursorInfo.bVisible = false;
 	SetConsoleCursorInfo(hOut,&CursorInfo);
 	
    Snake *newsnake=new Snake();
    Food  *newfood =new Food();
    setTextColor(6);
    newsnake->PrintSnake();
    newfood->GenerateFood(*newsnake);
    newfood->PrintFood();
    while(!newsnake->HitWall()&&!newsnake->BiteSelf()){
        if(!newsnake->ChangeDirection()){//Input ESC
            //Menu();
        }
        if(newsnake->GetFood(*newfood)){//Eat Food
            newsnake->AddLengthMove();
            score++;
            DrawScore();
            newfood->GenerateFood(*newsnake);
            newfood->PrintFood();
        }
        else    newsnake->Move();
        Sleep(speed);
    }
    delete newsnake;
    delete newfood;
    int k;
    setCursorLocation(13,13);
    setTextColor(3);
    std::cout<<"Game Over. 1: restart; 2:Leave.";
    std::cin>>k;
    return k;
}

//void Controller::Menu(){

//}

void Controller::DrawScore(){
    setCursorLocation(34,8);
    setTextColor(6);
    std::cout<<"     "<<score;
}

void Controller::SetSpeed(){
    switch (mode)
    {
    case 1:
        speed=220;
        break;
    case 2:
        speed=170;
        break;

    case 3:
        speed=135;
        break;
    case 4:
        speed=80;
        break;
    default:
        break;
    }
}

void Controller::Game(){
    Welcome();
    while(true){
        Select();
        SetSpeed();
        InitMap();
        SetSpeed();
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
