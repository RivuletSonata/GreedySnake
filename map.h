#ifndef MAP_H
#define MAP_H

#include<vector>
#include "tool.h"
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>

class Map{
    public:
        Map();
        void Map_mode2();
        void Map_mode3();
        void Map_mode4();
        void DrawMap();
    private:
        std::vector<Point> initmap;//保存初始地图
                                                                                                                         
};


#endif