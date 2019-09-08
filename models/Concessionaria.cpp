#include <iostream>
#include "concessionaria.h"

/**
 * Constructors
 */

Concessionaria::Concessionaria() {}

Concessionaria::Concessionaria(string nome, string cnpj)
{
  Concessionaria(nome, cnpj, 0);
}

Concessionaria::Concessionaria(string nome, string cnpj, int qntEstoque)
{
  setNome(nome);
  setCnpj(cnpj);
  setQntEstoque(qntEstoque);
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
  return qntEstoque;
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

void Concessionaria::setQntEstoque(int qntEstoque)
{
  this->qntEstoque = qntEstoque;
}
