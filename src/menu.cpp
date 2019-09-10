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
      << "1 - Listar automóveis" << endl
      << "2 - Cadastrar automóvel" << endl
      << "3 - Aumentar preço de todos automóveis" << endl
      << "4 - Listar carros com menos de 90 dias de uso" << endl
      << "0 - Voltar ao menu principal" << endl;

  cout << "#: ";
  cin >> selecao;

  if (selecao < 0 || selecao > 4)
  {
    return menuDaConcessionaria();
  }

  return selecao;
}