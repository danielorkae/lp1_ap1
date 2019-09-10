#include <vector>
#include <string>
#include <vector>
#include "automovel.h"

using namespace std;

class Concessionaria
{
private:
  /**
   * Properties
   */
  string nome;
  string cnpj;
  vector<Automovel *> estoque;

  /**
   * Methods
   */

  Automovel *encontrarAutomovelNoEstoque(string chassi, bool imprimir);
  int calculaData(int day, int month, int year);

public:
  /**
   * Constructors and Destructors
   */

  Concessionaria();
  ~Concessionaria();
  Concessionaria(string nome, string cnpj);

  /**
   * Getters
   */

  string getNome();
  string getCnpj();
  int getQntEstoque();
  vector<Automovel *> getEstoque();

  /**
   * Setters
   */

  void setNome(string nome);
  void setCnpj(string cnpj);

  /**
   * Methods
   */

  void listarEstoque();
  void adicionarAutomovelAoEstoque();
  void aumentarValorDoEstoque();
  void listarCarros90();
};

//-----------------------------------------------------------------------------------------------

