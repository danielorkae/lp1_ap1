#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include <string>

using namespace std;

class Automovel
{
private:
  /**
   * Properties
   */

  string modelo;
  string marca;
  string numeroDoChassi;
  string dataDeFrabricacao;
  float preco;

public:
  /**
   * Getters
   */
  string getModelo();
  string getMarca();
  string getNumeroDoChassi();
  string getDataDeFrabricacao();
  float getPreco();

  /**
   * Setters
   */

  void setModelo(string modelo);
  void setMarca(string marca);
  void setNumeroDoChassi(string numeroDoChassi);
  void setDataDeFrabricacao(string dataDeFabricacao);
  void setPreco(float preco);

  /**
   * Constructors
   */

  Automovel();
  Automovel(string modelo);
};

#endif