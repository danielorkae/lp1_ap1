#include "../include/automovel.h"

using namespace std;

/**
 * Constructors and Destructors
 */

Automovel::Automovel() {}

Automovel::~Automovel() {}

Automovel::Automovel(string marca, string modelo, string chassi, float preco, int _dia, int _mes, int _ano)
{
  setMarca(marca);
  setModelo(modelo);
  setChassi(chassi);
  setPreco(preco);
  setDiaDataDeFabricacao(_dia);
  setMesDataDeFabricacao(_mes);
  setAnoDataDeFabricacao(_ano);
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

int Automovel::getDiaDataDeFabricacao()
{
  return this->dia;
}

int Automovel::getMesDataDeFabricacao()
{
  return this->mes;
}

int Automovel::getAnoDataDeFabricacao()
{
  return this->ano;
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

void Automovel::setDiaDataDeFabricacao(int day)
{
  this->dia = day;
}

void Automovel::setMesDataDeFabricacao(int month)
{
  this->mes = month;
}

void Automovel::setAnoDataDeFabricacao(int year)
{
  this->ano = year;
}

void Automovel::setPreco(float preco)
{
  this->preco = preco;
}

void Automovel::addPercentage(float value)
{
  this->preco += (this->preco * value) / 100;
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
      << "Fabricação: \t" << automovel.dia << "/" << automovel.mes << "/" << automovel.ano << endl
      << endl;

  return stream;
}
