#ifndef FOOD_H
#define FOOD_H

class Food{
    public:
        Food();
        void PrintfFood();
        void GenerateFood(int x,int y);
        int GetX(){return this->lx;};
        int GetY(){return this->ly;};
    private:
        int lx;
        int ly;
};


#endif