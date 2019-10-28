#include "../include/caminhao.h"

using namespace std;

/**
 * Constructors and Destructors
 */

Caminhao::Caminhao() {}

Caminhao::~Caminhao() {}

Caminhao::Caminhao(string marca, string chassi, float preco, int _dia, int _mes, int _ano, string carga)
{
  setMarca(marca);
  setChassi(chassi);
  setPreco(preco);
  setDiaDataDeFabricacao(_dia);
  setMesDataDeFabricacao(_mes);
  setAnoDataDeFabricacao(_ano);
  setCarga(carga);
}

/**
 * Getters
 */

string Caminhao::getCarga()
{
  return this->carga;
}

/**
 * Setters
 */

void Caminhao::setCarga(string _carga)
{
  this->carga = _carga;
}