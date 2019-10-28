#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include <iostream>
#include <vector>
#include <string>

#include "veiculo.h"
#include "automovel.h" 
#include "moto.h" 
#include "caminhao.h" 

using namespace std;

class Concessionaria
{
private:

  /**
   * Properties
   * Atributos especificos das concessionarias, tanto de informações básicas como de sua lista de estoque. 
   * Um vetor de chassis também esta sendo utilizado como auxiliar para facilitar na localização dos veiculos.
   */

  string nome;
  string cnpj;
  string tipo_propriedade;
  string nome_propriedade;

  vector<Automovel *> estoque_automovel;
  vector<Moto *> estoque_moto;
  vector<Caminhao *> estoque_caminhao;

  vector<string *> chassis; 

public:

  /**
   * Constructors and Destructors
   */

  Concessionaria();
  ~Concessionaria();
  Concessionaria(string nome, string cnpj, string tipo_propriedade, string nome_propriedade);

  /**
   * Getters
   */

  string getNome();
  string getCnpj();
  string getTipo_propriedade();
  string getNome_propriedade();
  int getEstoqueAutomovel();
  int getEstoqueMoto();
  int getEstoqueCaminhao();


  /**
   * Setters
   */

  void setNome(string _nome);
  void setCnpj(string _cnpj);
  void setTipoPropriedade(string _tipo_propriedade);
  void setNomePropriedade(string _nome_propriedade);
  
  /**
   * Methods
   */

  void listarEstoque();
  void adicionarVeiculoAoEstoque();
  void aumentarValorDoEstoque();
  void listarCarros90();
  Veiculo *encontrarVeiculoNoEstoque(string chassi, bool imprimir);
  int calculaData(int day, int month, int year);

};

//-----------------------------------------------------------------------------------------------

#endif