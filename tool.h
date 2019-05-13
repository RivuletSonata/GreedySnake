#ifndef TOOL_H
#define TOOL_H

void setBackgroundColor();
void setTextColor(int colorid);
void setwindowsize(int cols,int lines);
void setCursorLocation(int x,int y);//
class Point{
    public:
        Point();
        Point(const int a,const int b): x(a),y(b){};
        void Print();
        void PrintDot();
        void ChangePoint(const int x,const int y);
        void ClearPoint();
    private:
        int x;
        int y;
};

#endif
