#ifndef MYGAME
#define MYGAME

class MyGame{
  private:
    int turn = 0;
    char option;

  public:
    void start();
    int mainloop();
    void handlopt();

};
#endif // !MYGAME
