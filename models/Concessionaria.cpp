#include <iostream>
#include <vector>
#include "concessionaria.h"

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
