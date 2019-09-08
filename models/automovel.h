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
  string chassi;
  string dataDeFrabricacao;
  float preco;

public:
  /**
   * Getters
   */
  string getModelo();
  string getMarca();
  string getChassi();
  string getDataDeFrabricacao();
  float getPreco();

  /**
   * Setters
   */

  void setModelo(string modelo);
  void setMarca(string marca);
  void setChassi(string Chassi);
  void setDataDeFrabricacao(string dataDeFabricacao);
  void setPreco(float preco);

  /**
   * Constructors
   */

  Automovel();
  Automovel(string marca, string modelo, string chassi, float preco, string dataDeFrabricacao);
};

#endif