#ifndef SQUARE
#define SQUARE

class Square{
  private:
    char symbol = 'N'; //default symbol
    int effect = 0; //It does not add or substract positions
  
  public:
    virtual char getSymbol();
    virtual int getEffect();
     
};

#endif // !SQUARE
