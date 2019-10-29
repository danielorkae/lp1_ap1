#include <iostream>
#include <string>
#include "../include/menu.h"

using namespace std;

int menuPrincipal()
{
  int selecao;

  //Opções do menu principal, com as opções para manipular as concesisonarias
  cout
      << endl
      << "=== MENU PRINCIPAL ===" << endl
      << "1 - Escolher concessionária" << endl
      << "2 - Cadastrar concessionária" << endl
      << "3 - Listar concessionárias" << endl
      << "0 - Sair" << endl;

  cout << "#: ";
  cin >> selecao;

  //Condicional para checkar se o valor informado não está fora das opções
  if (selecao < 0 || selecao > 3)
  {
    return menuPrincipal();
  }

  //Retorno do menu selecionado
  return selecao;
}

int menuDaConcessionaria()
{
  int selecao;

  //Opções do menu interno das concessionarias, com as opções para manipular os atributos da concessionaria em si
  cout
      << endl
      << "=== MENU DA CONCESSIONÁRIA ===" << endl
      << "1 - Listar veículos" << endl
      << "2 - Cadastrar veículo" << endl
      << "3 - Aumentar preço de todos veículos" << endl
      << "4 - Listar veículos com menos de 90 dias de uso" << endl
      << "5 - Pesquisar veículo por chassi" << endl
      << "0 - Voltar ao menu principal" << endl;

  cout << "#: ";
  cin >> selecao;

  //Condicional para checkar se o valor informado não está fora das opções
  if (selecao < 0 || selecao > 5)
  {
    return menuDaConcessionaria();
  }

  //Retorno do menu selecionado
  return selecao;
}