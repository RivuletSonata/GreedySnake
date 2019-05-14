#ifndef CONTROLLER_H
#define	CONTROLLER_H



class Controller{
	public:
        Controller();
        void Welcome();
        void Select ();
        void InitMap();
        int RunningGame();
        void SetSpeed();
        void Game();
        void Menu();
        void GameOver();
        void DrawScore();
    private:
        int score;
        int speed;
        int mode;
};
#endif