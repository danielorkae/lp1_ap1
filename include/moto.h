#ifndef MOTO_H
#define MOTO_H

#include <iostream>
#include <string>

#include "veiculo.h"

using namespace std;

/**
 * Classe de Veículos do tipo Moto
 */

class Moto : public Veiculo
{
private:

  /**
   * Properties
   * Atributos especificos desta classe
   */

  string modelo;

public:

  /**
   * Getters
   * Funções para acessar os valores dos atributos da classe
   */

  string getModelo();

  /**
   * Setters
   * Funções para determinar os valores dos atributos da classe
   */

  void setModelo(string _modelo);

  /**
   * Constructors and Destructors
   * Contrutor padrão, por parâmetro e destrutor da classe
   */

  Moto();
  Moto(string marca, string chassi, float preco, int _dia, int _mes, int _ano, string modelo);
  ~Moto();

};

#endif