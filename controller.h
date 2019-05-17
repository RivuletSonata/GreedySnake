#ifndef CONTROLLER_H
#define	CONTROLLER_H



class Controller{
	public:
        Controller():speed(140),mode(1),score(0){};
        void Welcome();
        void Select ();
        void InitMap();
        int RunningGame();
        void SetSpeed();
        void Game();
        int Menu();
        void GameOver();
        void DrawScore();
    private:
        int score;
        int speed;
        int mode;
};
#endif
