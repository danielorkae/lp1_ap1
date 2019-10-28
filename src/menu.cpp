#include <iostream>
#include <string>
#include "../include/menu.h"

using namespace std;

int menuPrincipal()
{
  int selecao;

  cout
      << endl
      << "=== MENU PRINCIPAL ===" << endl
      << "1 - Escolher concessionária" << endl
      << "2 - Cadastrar concessionária" << endl
      << "0 - Sair" << endl;

  cout << "#: ";
  cin >> selecao;

  if (selecao < 0 || selecao > 3)
  {
    return menuPrincipal();
  }

  return selecao;
}

int menuDaConcessionaria()
{
  int selecao;

  cout
      << endl
      << "=== MENU DA CONCESSIONÁRIA ===" << endl
      << "1 - Listar veículos" << endl
      << "2 - Cadastrar veículo" << endl
      << "3 - Aumentar preço de todos veículos" << endl
      << "4 - Listar veículos com menos de 90 dias de uso" << endl
      << "0 - Voltar ao menu principal" << endl;

  cout << "#: ";
  cin >> selecao;

  if (selecao < 0 || selecao > 4)
  {
    return menuDaConcessionaria();
  }

  return selecao;
}