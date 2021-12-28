#pragma once
#include "Base.h"
class BasuraAzul :
    public Base
{
private:

public:
    BasuraAzul();
    ~BasuraAzul();
    BasuraAzul(int px, int py, int pw, int ph);;
    void Mover(Graphics^ g);
};

