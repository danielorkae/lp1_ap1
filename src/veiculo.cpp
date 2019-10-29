#include "../include/veiculo.h"

using namespace std;

/**
 * Constructors and Destructors Padrão
 */

Veiculo::Veiculo() {}

Veiculo::~Veiculo() {}

/**
 * Getters
 */

string Veiculo::getMarca()
{
  return this->marca;
}

string Veiculo::getChassi()
{
  return this->chassi;
}

int Veiculo::getDiaDataDeFabricacao()
{
  return this->dia;
}

int Veiculo::getMesDataDeFabricacao()
{
  return this->mes;
}

int Veiculo::getAnoDataDeFabricacao()
{
  return this->ano;
}

float Veiculo::getPreco()
{
  return this->preco;
}

/**
 * Setters
 */

void Veiculo::setMarca(string marca)
{
  this->marca = marca;
}

void Veiculo::setChassi(string chassi)
{
  this->chassi = chassi;
}

void Veiculo::setDiaDataDeFabricacao(int day)
{
  this->dia = day;
}

void Veiculo::setMesDataDeFabricacao(int month)
{
  this->mes = month;
}

void Veiculo::setAnoDataDeFabricacao(int year)
{
  this->ano = year;
}

void Veiculo::setPreco(float preco)
{
  this->preco = preco;
}


/*
 * Adicionar porcentagem ao preço do veiculo
 */

void Veiculo::addPercentage(float value)
{
  this->preco += (this->preco * value) / 100;
}

/**
 * Operators
 */

ostream &operator<<(ostream &stream, const Veiculo &veiculo)
{
  //Utilizando a stream para fazer a impressao dos atributos do veículo
  stream
      << "=== IMPRIMIR VEÍCULO ===" << endl
      << veiculo.marca << endl
      << "Preço: \t\tR$ " << veiculo.preco << endl
      << "Chassi: \t" << veiculo.chassi << endl
      << "Fabricação: \t" << veiculo.dia << "/" << veiculo.mes << "/" << veiculo.ano << endl
      << endl;

  return stream;
}
