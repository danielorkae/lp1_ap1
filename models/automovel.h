#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include <iostream>
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
  int dia;
  int mes;
  int ano;
  float preco;

public:
  /**
   * Getters
   */
  string getModelo();
  string getMarca();
  string getChassi();
  int getDiaDataDeFabricacao();
  int getMesDataDeFabricacao();
  int getAnoDataDeFabricacao();
  float getPreco();

  /**
   * Setters
   */

  void setModelo(string modelo);
  void setMarca(string marca);
  void setChassi(string Chassi);
  void setDiaDataDeFabricacao(int dia);
  void setMesDataDeFabricacao(int mes);
  void setAnoDataDeFabricacao(int ano);
  void setPreco(float preco);
  void addPercentage(float valeu);

  /**
   * Constructors and Destructors
   */

  Automovel();
  Automovel(string marca, string modelo, string chassi, float preco, int _dia, int _mes, int _ano);
  ~Automovel();

  /**
   * Operators
   */

  friend ostream &operator<<(ostream &stream, const Automovel &automovel);
};

#endif