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
   * Foram criados 3 vetores de veículos ao invés de um para tornar mais fácil a manipulação do vector
   */

  //Informações
  string nome;
  string cnpj;
  string tipo_propriedade;
  string nome_propriedade;

  //Vetores de veículos separados por tipos
  vector<Automovel *> estoque_automovel;
  vector<Moto *> estoque_moto;
  vector<Caminhao *> estoque_caminhao;

public:

  /**
   * Constructors and Destructors
   * Contrutor padrão, por parâmetro e destrutor da classe
   */

  Concessionaria();
  ~Concessionaria();
  Concessionaria(string nome, string cnpj, string tipo_propriedade, string nome_propriedade);

  /**
   * Getters
   * Funções para acessar os valores dos atributos da classe
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
   * Funções para determinar os valores dos atributos da classe
   */

  void setNome(string _nome);
  void setCnpj(string _cnpj);
  void setTipoPropriedade(string _tipo_propriedade);
  void setNomePropriedade(string _nome_propriedade);
  
  /**
   * Methods
   */

  void listarEstoque(); //Lista todos os veículos contidos no estoque da concessionaria
  void adicionarVeiculoAoEstoque(); //Adiciona um veículo específico ao estoque, diferenciado pelo tipo
  void aumentarValorDoEstoque(); //Realiza um aumento no valor de todos os veículos contidos no estoque da concessionaria selecionada
  void listarCarros90(); //Lista todos os carros que tem menos que 90 dias de uso
  Veiculo *encontrarVeiculoNoEstoque(string chassi, bool imprimir); //Verifica se um determinado veículo existe no estoque, fazendo as comparações pelo número de chassi
  int calculaData(int day, int month, int year); //Função para transformar o dia, mes e ano em um único número inteiro, facilitando o calculo de dias de vida do veículo

  void pesquisaChassi(); //Pesquisa no estoque da concessionaria de existe algum veículo com o número de chassi informado
  int valorTotal(); //Realiza o cálculo do valor total do estoque da concessionaria

};

//-----------------------------------------------------------------------------------------------

#endif