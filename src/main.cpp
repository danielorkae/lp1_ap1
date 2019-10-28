//Bibliotecas padrão

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

//Arquivos modularizados

#include "../include/concessionaria.h"
#include "../include/veiculo.h"
#include "../include/automovel.h"
#include "../include/moto.h"
#include "../include/caminhao.h"
#include "../include/menu.h"

using namespace std;

//

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
        concessionariaSelecionada->adicionarVeiculoAoEstoque();
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

void criarConcessionaria()
{
  string nome, cnpj, tipo_propriedade, nome_propriedade;
  int escolha;

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

    cout << "Tipo de propriedade: "
         << endl
         << "[1] Pessoa Física"
         << endl
         << "[2] Pessoa Jurídica"
         << endl
         << "Escolha uma entrada: ";
    cin >> escolha;

    if (escolha == 1) 
    {
      tipo_propriedade = "Pessoa Física";

      cout << "Informe o nome da Pessoa Física: ";
      cin >> nome_propriedade;
    }
    else if (escolha == 2) 
    {
      tipo_propriedade = "Pessoa Jurídica: ";

      cout << "Informe o número da Pessoa Jurídica";
      cin >> nome_propriedade;
    }
    else 
    {
      cout << "Valor informado inválido!";
    }


    concessionarias.push_back(new Concessionaria(nome, cnpj, tipo_propriedade, nome_propriedade));

    cout << endl
         << "Concessionária cadastrada com sucesso!" << endl;
  }
}

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

Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir)
{
  for (unsigned int i = 0; i < concessionarias.size(); i++)
  {
    Concessionaria *concessionaria = concessionarias[i];

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
