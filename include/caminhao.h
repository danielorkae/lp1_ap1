#ifndef CAMINHAO_H
#define CAMINHAO_H

#include <iostream>
#include <string>

#include "veiculo.h"

using namespace std;

/**
 * Classe de Veículos do tipo Caminhao
 */

class Caminhao : public Veiculo
{
private:

  /**
   * Properties
   * Atributos especificos desta classe
   */

  string carga;

public:

  /**
   * Getters
   * Funções para acessar os valores dos atributos da classe
   */

  string getCarga();

  /**
   * Setters
   * Funções para determinar os valores dos atributos da classe
   */

  void setCarga(string _carga);

  /**
   * Constructors and Destructors
   * Contrutor padrão, por parâmetro e destrutor da classe
   */

  Caminhao();
  Caminhao(string marca, string chassi, float preco, int _dia, int _mes, int _ano, string carga);
  ~Caminhao();

};

#endif