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
  cout << "=== LISTAR ESTOQUE === " << endl
       << endl;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    cout << estoque[i];
  }
}

void Concessionaria::adicionarAutomovelAoEstoque()
{
  string modelo, marca, chassi, dataDeFabricacao;
  float preco;

  cout << "=== CADASTRO DE AUTOMÓVEL ===" << endl;

  cout << "Chassi: " << endl;
  cin >> chassi;

  if (encontrarAutomovelNoEstoque(chassi, false) != NULL)
  {
    cout << "Automóvel já cadastrado com esse número de chassi." << endl;
    return;
  }

  cout << "Marca:" << endl;
  cin >> marca;

  cout << "Modelo:" << endl;
  cin >> modelo;

  cout << "Preço:" << endl;
  cin >> preco;

  cout << "Data de fabricação (DD-MM-AAAA):" << endl;
  cin >> dataDeFabricacao;

  estoque.push_back(new Automovel(marca, modelo, chassi, preco, dataDeFabricacao));

  cout << "Automóvel cadastrado com sucesso!";
}

void Concessionaria::aumentarValorDoEstoque(int porcentagem)
{
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
    cout << "Nenhum automóvel encontrado." << endl;
  }

  return NULL;
}

/**
 * Overloads
 */

ostream &operator<<(ostream &stream, Concessionaria const concessionaria)
{
  stream
      << "=== IMPRIMIR CONCESSIONÁRIA ===" << endl
      << "Concessionária " << concessionaria.nome << endl
      << "CNPJ: \t" << concessionaria.cnpj << endl
      << "Estoque" << concessionaria.estoque.size() << " carros" << endl
      << endl;

  return stream;
}
