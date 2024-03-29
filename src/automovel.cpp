#include "../include/automovel.h"

using namespace std;

/**
 * Constructors and Destructors
 */

//Construtor Padrão
Automovel::Automovel() {}

//Destrutor Padrão
Automovel::~Automovel() {}

//Construtor com parâmetro, utilizando as propriedades do veículo
Automovel::Automovel(string marca, string chassi, float preco, int _dia, int _mes, int _ano, string motor)
{
  setMarca(marca);
  setChassi(chassi);
  setPreco(preco);
  setDiaDataDeFabricacao(_dia);
  setMesDataDeFabricacao(_mes);
  setAnoDataDeFabricacao(_ano);
  setMotor(motor);
}

/**
 * Getters
 */

string Automovel::getMotor()
{
  return this->motor;
}

/**
 * Setters
 */

void Automovel::setMotor(string _motor)
{
    this->motor = _motor;
}