#include "Controladora.h"

Controladora::Controladora()
{
	Inicio = time(0);
}

Controladora::~Controladora()
{
}

void Controladora::Insertar_Basura()
{
	System::Random^ r = gcnew System::Random();
	int a,e,f,g;
	float b,c,d;
	a = 1 + rand() % (4 + 1 - 1);
	b= 1/100 + rand() % (1/10 + 1 - 1/100);
	c = 1 / 100 + rand() % (1 / 10 + 1 - 1 / 100);
	d = 1 / 100 + rand() % (1 / 10 + 1 - 1 / 100);
	e = 50 + rand() % (600 + 1 - 50);
	f = 50 + rand() % (600 + 1 - 50);
	g = 50 + rand() % (600 + 1 - 50);
	int tipo=a;
	if (tipo == 1)
	{
		if (difftime(time(0), Inicio) > b)
		{
			basuras.push_back(new BasuraVerde(e, 0, 1, 1));
			Inicio = time(0);
		}
	}
	if (tipo == 2)
	{
		if (difftime(time(0), Inicio) > c)
		{
			basuras2.push_back(new BasuraRoja(f, 0, 1, 1));
			Inicio = time(0);
		}
	}
	if (tipo == 3)
	{
		if (difftime(time(0), Inicio) > d)
		{
			basuras3.push_back(new BasuraAzul(g, 0, 1, 1));
			Inicio = time(0);
		}
	}
}

void Controladora::Dibujar_Basura1(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < basuras.size(); i++)
	{
		basuras.at(i)->Dibujar_desImagen(g, bmp);
		basuras.at(i)->Mover(g);
	}
	for (int i = 0; i < basuras.size(); i++)
	{
		if (basuras.at(i)->retornar_eliminar() == true)
			basuras.erase(basuras.begin() + i);
	}
	
}

void Controladora::Dibujar_Basura2(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < basuras2.size(); i++)
	{
		basuras2.at(i)->Dibujar_desImagen(g, bmp);
		basuras2.at(i)->Mover(g);
	}
	for (int i = 0; i < basuras2.size(); i++)
	{
		if (basuras2.at(i)->retornar_eliminar() == true)
			basuras2.erase(basuras2.begin() + i);
	}
}
void Controladora::Dibujar_Basura3(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < basuras3.size(); i++)
	{
		basuras3.at(i)->Dibujar_desImagen(g, bmp);
		basuras3.at(i)->Mover(g);
	}
	for (int i = 0; i < basuras3.size(); i++)
	{
		if (basuras3.at(i)->retornar_eliminar() == true)
			basuras3.erase(basuras3.begin() + i);
	}
}
