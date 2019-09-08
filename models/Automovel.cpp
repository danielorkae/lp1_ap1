#include "automovel.h"

using namespace std;

/**
 * Getters
 */

string Automovel::getModelo()
{
  return this->modelo;
}

string Automovel::getMarca()
{
  return this->marca;
}

string Automovel::getNumeroDoChassi()
{
  return this->numeroDoChassi;
}

string Automovel::getDataDeFrabricacao()
{
  return this->dataDeFrabricacao;
}

float Automovel::getPreco()
{
  return this->preco;
}

/**
 * Setters
 */

void Automovel::setModelo(string modelo)
{
  this->modelo = modelo;
}

void Automovel::setMarca(string marca)
{
  this->marca = marca;
}

void Automovel::setNumeroDoChassi(string numeroDoChassi)
{
  this->numeroDoChassi = numeroDoChassi;
}

void Automovel::setDataDeFrabricacao(string dataDeFabricacao)
{
  this->dataDeFrabricacao;
}

void Automovel::setPreco(float preco)
{
  this->preco = preco;
}

/**
 * Constructors
 */

Automovel::Automovel()
{
}

Automovel::Automovel(string modelo)
{
  setModelo(modelo);
}
