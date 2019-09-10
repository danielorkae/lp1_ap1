#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "models/menu.h"
#include "models/concessionaria.h"

using namespace std;

void criarConcessionaria();
Concessionaria *escolherConcessionaria();
Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir);

vector<Concessionaria *> concessionarias;
Concessionaria *concessionariaSelecionada = NULL;

int main()
{
  bool sair = false;
  int selecaoMenuPrincipal, selecaoMenuConcessionaria;

  system("clear");

  while (!sair)
  {
    if (concessionariaSelecionada == NULL)
    {
      selecaoMenuPrincipal = menuPrincipal();

      switch (selecaoMenuPrincipal)
      {
      case 1:
        concessionariaSelecionada = escolherConcessionaria();
        break;
      case 2:
        criarConcessionaria();
        break;
      default:
        return 0;
      }
    }
    else
    {
      selecaoMenuConcessionaria = menuDaConcessionaria();

      switch (selecaoMenuConcessionaria)
      {
      case 1:
        concessionariaSelecionada->listarEstoque();
        break;
      case 2:
        concessionariaSelecionada->adicionarAutomovelAoEstoque();
        break;
      case 3:
        concessionariaSelecionada->aumentarValorDoEstoque();
        break;
      case 4:
        concessionariaSelecionada->listarCarros90();
        break;
      default:
        concessionariaSelecionada = NULL;
        break;
      }
    }
  }

  return 1;
}


//-------------------------------------------------------------------------------------------------

Concessionaria *escolherConcessionaria()
{
  unsigned int selecao;

  cout << endl
       << "=== ESCOLHER CONCESSIONÁRIA ===" << endl;

  for (unsigned int i = 0; i < concessionarias.size(); i++)
  {
    cout << i + 1 << " - " << concessionarias[i]->getNome() << endl;
  }

  if (concessionarias.size() == 0)
  {
    cout << "Nenhuma concessionária cadastrada." << endl
         << endl;

    return NULL;
  }

  cout << "0 - Voltar" << endl;

  cin >> selecao;

  if (selecao == 0)
  {
    return NULL;
  }

  if (selecao < 0 || selecao > concessionarias.size())
  {
    return escolherConcessionaria();
  }

  return concessionarias[selecao - 1];
}

void criarConcessionaria()
{
  string nome, cnpj;

  cout << endl
       << "=== CADASTRO DE CONCESSIONÁRIA ===" << endl;

  cout << "CNPJ: ";
  cin >> cnpj;

  if (encontrarConcessionaria(cnpj, false) != NULL)
  {
    cout << "Esta concessionária já está cadastrada." << endl;
  }
  else
  {
    cout << "Nome: ";
    cin >> nome;

    concessionarias.push_back(new Concessionaria(nome, cnpj));

    cout << endl
         << "Concessionária cadastrada com sucesso!" << endl;
  }
}

Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir)
{
  for (unsigned int i = 0; i < concessionarias.size(); i++)
  {
    auto concessionaria = concessionarias[i];

    if (concessionaria->getCnpj() == cnpj)
    {
      if (imprimir)
      {
        cout << concessionaria;
      }

      return concessionaria;
    }
  }

  if (imprimir)
  {
    cout << "Nenhuma concessionária encontrada." << endl;
  }

  return NULL;
}
