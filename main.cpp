#include <iostream>
#include "models/automovel.h"

using namespace std;

int main()
{
  Automovel *a = new Automovel("Onix");
  Automovel *b = new Automovel();

  b->setModelo("Prisma");

  cout << "Modelo do carro: " << a->getModelo() << endl;
  cout << "Modelo do carro: " << b->getModelo() << endl;
  
  return 0;
}