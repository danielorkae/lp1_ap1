#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Veiculo
{
private:

  /**
   * Properties
   * Atributos de um Veículo, que neste caso são comuns a todo veículo independente do seu tipo (automovel, moto ou caminhao)
   * O nível de visibilidade é private, mesmo que esta classe seja utilizada como base para outras, uma vez que é possível acessar os dados privados através de funções
   */

  string marca;
  string chassi;
  int dia;
  int mes;
  int ano;
  float preco;

public:

  /**
   * Getters
   * Funções para acessar os valores dos atributos da classe
   */

  string getMarca();
  string getChassi();
  int getDiaDataDeFabricacao();
  int getMesDataDeFabricacao();
  int getAnoDataDeFabricacao();
  float getPreco();

  /**
   * Setters
   * Funções para determinar os valores dos atributos da classe
   */

  void setMarca(string marca);
  void setChassi(string Chassi);
  void setDiaDataDeFabricacao(int dia);
  void setMesDataDeFabricacao(int mes);
  void setAnoDataDeFabricacao(int ano);
  void setPreco(float preco);

  /**
  * Função para adicionar um valor equivalente a uma porcentagem ao valor de todos os veiculos de uma concessionaria
  */

  void addPercentage(float valeu);

  /**
   * Constructors and Destructors
   * Contrutor e destrutor da classe
   */

  Veiculo();
  ~Veiculo();

  /**
   * Operators
   * Utilizado para imprimir os valores do automovel como um todo
   */

  friend ostream &operator<<(ostream &stream, const Veiculo &veiculo);
};

#endif