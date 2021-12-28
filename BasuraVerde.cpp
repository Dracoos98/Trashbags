#include "BasuraVerde.h"

BasuraVerde::BasuraVerde()
{
}

BasuraVerde::~BasuraVerde()
{
}

BasuraVerde::BasuraVerde(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 1, 1, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	dy = (r->Next(10, 16));
	delete r;
}

void BasuraVerde::Mover(Graphics^ g)
{
	if (dy+h+y>g->VisibleClipBounds.Height)
	{
		dy = 0;
		eliminar = true;
	}
	y += dy;
}





