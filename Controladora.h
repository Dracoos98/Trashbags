#pragma once
#include "BasuraVerde.h"
#include "BasuraRoja.h"
#include "BasuraAzul.h"
#include <vector>
#include <time.h>
using namespace std;
class Controladora
{
private:
	time_t Inicio;
	vector<Base*> basuras;
	vector<Base*> basuras2;
	vector<Base*> basuras3;

public:
	Controladora();
	~Controladora();
	void Insertar_Basura();
	void Dibujar_Basura1(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Basura2(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Basura3(Graphics^ g, Bitmap^ bmp);
};

