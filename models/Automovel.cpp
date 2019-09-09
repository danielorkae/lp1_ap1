#include "automovel.h"

using namespace std;

/**
 * Constructors
 */

Automovel::Automovel() {}

Automovel::Automovel(string marca, string modelo, string chassi, float preco, string dataDeFabricacao)
{
  setMarca(marca);
  setModelo(modelo);
  setChassi(chassi);
  setPreco(preco);
  setDataDeFrabricacao(dataDeFabricacao);
}

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

string Automovel::getChassi()
{
  return this->chassi;
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

void Automovel::setChassi(string chassi)
{
  this->chassi = chassi;
}

void Automovel::setDataDeFrabricacao(string dataDeFabricacao)
{
  this->dataDeFrabricacao = dataDeFrabricacao;
}

void Automovel::setPreco(float preco)
{
  this->preco = preco;
}

/**
 * Operators
 */

ostream &operator<<(ostream &stream, const Automovel &automovel)
{
  stream
      << "=== IMPRIMIR AUTOMÓVEL ===" << endl
      << automovel.marca << " " << automovel.modelo << endl
      << "Preço: \t\tR$ " << automovel.preco << endl
      << "Chassi: \t" << automovel.chassi << endl
      << "Fabricação: \t" << automovel.dataDeFrabricacao << endl
      << endl;

  return stream;
}
