#include <iostream>
#include <vector>
#include "concessionaria.h"
#include "automovel.h"

/**
 * Constructors
 */

Concessionaria::Concessionaria() {}

Concessionaria::Concessionaria(string nome, string cnpj)
{
  setNome(nome);
  setCnpj(cnpj);
}

/**
 * Getters
 */

string Concessionaria::getNome()
{
  return nome;
}

string Concessionaria::getCnpj()
{
  return cnpj;
}

int Concessionaria::getQntEstoque()
{
  return estoque.size();
}

/**
 * Setters
 */

void Concessionaria::setNome(string nome)
{
  this->nome = nome;
}

void Concessionaria::setCnpj(string cnpj)
{
  this->cnpj = cnpj;
}

/**
 * Methods
 */

void Concessionaria::listarEstoque()
{
  cout << endl
       << "=== LISTAR AUTOMÓVEIS NO ESTOQUE === " << endl
       << endl;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    cout << *estoque[i];
  }

  if (estoque.size() == 0)
  {
    cout << "Nenhum automóvel em estoque." << endl;
  }
}

void Concessionaria::adicionarAutomovelAoEstoque()
{
  string modelo, marca, chassi, dataDeFabricacao;
  float preco;

  cout << endl
       << "=== CADASTRO DE AUTOMÓVEL ===" << endl;

  cout << "Chassi: ";
  cin >> chassi;

  if (encontrarAutomovelNoEstoque(chassi, false) != NULL)
  {
    cout << endl
         << "Automóvel já cadastrado com esse número de chassi." << endl;
    return;
  }

  cout << "Marca: ";
  cin >> marca;

  cout << "Modelo: ";
  cin >> modelo;

  cout << "Preço: ";
  cin >> preco;

  cout << "Data de fabricação (DD-MM-AAAA):";
  cin >> dataDeFabricacao;

  estoque.push_back(new Automovel(marca, modelo, chassi, preco, dataDeFabricacao));

  cout << endl
       << "Automóvel cadastrado com sucesso!" << endl;
}

void Concessionaria::aumentarValorDoEstoque()
{
  int porcentagem;

  cout << endl
       << "=== AUMENTAR VALOR DO ESTOQUE ===" << endl;

  cout << "Porcentagem de aumento: " << endl;
  cin >> porcentagem;

  float aumento = 1 + porcentagem / 100;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    auto automovel = estoque[i];

    automovel->setPreco(automovel->getPreco() * aumento);
  }
}

Automovel *Concessionaria::encontrarAutomovelNoEstoque(string chassi, bool imprimir)
{
  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    auto automovel = estoque[i];

    if (automovel->getChassi() == chassi)
    {
      if (imprimir)
      {
        cout << automovel;
      }

      return automovel;
    }
  }

  if (imprimir)
  {
    cout << endl
         << "Nenhum automóvel encontrado." << endl;
  }

  return NULL;
}
