#ifndef TOOL_H
#define TOOL_H

void setBackgroundColor();//设置文字高亮
void setTextColor(int colorid);//设置文字颜色
void setwindowsize(int cols,int lines);//设置窗口大小
void setCursorLocation(int x,int y);//设置光标位置
class Point{
    public:
        Point();//默认构造函数
        Point(const int a,const int b): x(a),y(b){};//带坐标的构造函数
        void Print();//边界点的打印
        void PrintDot();//内部点的打印
        void ChangePoint(const int x,const int y);//将点坐标更改为(x,y)
        void ClearPoint();//清除点
        int getx(){return this->x ;}//返回x坐标
        int gety(){return this->y ;}//返回y坐标
    private:
        int x;
        int y;
};

#endif
