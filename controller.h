#ifndef CONTROLLER_H
#define	CONTROLLER_H
class Controller{
	public:
        Controller():speed(140),mode(1),score(0){};
        /*结构函数*/
        void Game();//一级游戏控制函数
        void Welcome();//欢迎界面
        void Select ();//选择模式界面
        void InitMap();//生成地图界面
        int RunningGame();//二级游戏控制界面
        int GameoverSelect();//游戏结束选择界面
        void GameOver();//游戏结束界面
        /*行为函数*/
        void SetSpeed();//设置贪吃蛇速度
        void DrawScore();//展示分数
    private:
        int score;
        int speed;
        int mode;
};
#endif

