#pragma once
#include "Base.h"

class BasuraRoja :
    public Base
{
private:

public:
    BasuraRoja();
    ~BasuraRoja();
    BasuraRoja(int px, int py, int pw, int ph);;
    void Mover(Graphics^ g);

};

