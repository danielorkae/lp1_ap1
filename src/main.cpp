//Bibliotecas padrão

#include <iostream>
#include <istream>
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

//Funções para manipular os objetos Concessionaria

void criarConcessionaria(); //Cria uma concessionaria com todos os seus atributos
void listarConcessionarias(); //Lista todas as concessionarias existentes, e caso nao haja nenhuma, ele irá informar
Concessionaria *escolherConcessionaria(); //Função para escolher uma concessionaria e fazer alterações em seus atributos, como os veículos
Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir); //Função para encontrar uma concessionaria ja existente

vector<Concessionaria *> concessionarias; //Vetor de concessionarias
Concessionaria *concessionariaSelecionada = NULL; //Objeto concessionaria utilizado no menu de interação com usuário

//-------------------------------------------------------------------------------------------------

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
      case 3:
        listarConcessionarias();
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
      case 5:
        concessionariaSelecionada->pesquisaChassi();
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
  string nome, cnpj, tipo_propriedade, nome_propriedade, entrada;
  int escolha = 0;

  cout << endl
       << "=== CADASTRO DE CONCESSIONÁRIA ===" << endl;

  cout << "Nome: ";
  cin >> nome;

  cout << "CNPJ: ";
  cin >> cnpj;

  if (encontrarConcessionaria(cnpj, false) != NULL)
  {
    cout << "Esta concessionária já está cadastrada." << endl;
  }
  else
  {
    cin.clear();

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

      cout << "Informe o número da Pessoa Jurídica: ";
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

//-------------------------------------------------------------------------------------------------

void listarConcessionarias()
{
  cout << endl
        << "=== LISTAR CONCESSIONÁRIAS ===" << endl;

  if (concessionarias.size() == 0)
  {
    cout << endl << "Nenhuma concessionária cadastrada."
         << endl;
    return;
  }

  for (unsigned int i = 0; i < concessionarias.size(); i++)
  {

    cout << endl << "######################################################" << endl << endl;

    Concessionaria *concessionaria = concessionarias[i];

    cout << "Nome: " << concessionaria->getNome() << endl
          << "Proprietário do tipo " << concessionaria->getTipo_propriedade()
          << concessionaria->getNome_propriedade() << endl;

    concessionaria->listarEstoque();

    cout << endl << "Valor total dos veículos: R$" << concessionaria->valorTotal() << endl;
  } 

  cout << endl << "######################################################" << endl << endl;
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

//-------------------------------------------------------------------------------------------------

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
