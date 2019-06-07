#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include "map.h"

Map::Map(){
    for(int i=1;i<=30;++i)  initmap.emplace_back(Point(i,1));
    for(int i=2;i<=30;++i){
        initmap.emplace_back(Point(1,i));
        initmap.emplace_back(Point(30,i));
    } 
    for(int i=2;i<=29;++i)  initmap.emplace_back(Point(i,30));
}
void Map::DrawMap(){
    for (auto& Point : initmap){
        Point.Print();
        Sleep(10);//调用Sleep函数可营造动画效果
    }
}

