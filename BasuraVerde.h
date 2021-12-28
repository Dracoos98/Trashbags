#pragma once
#include "Base.h"

class BasuraVerde :
    public Base
{
private:
    
public:
    BasuraVerde();
    ~BasuraVerde();
    BasuraVerde(int px, int py, int pw, int ph);;
    void Mover(Graphics^ g);
   
};

