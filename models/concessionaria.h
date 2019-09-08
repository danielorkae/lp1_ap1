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

public:
  /**
   * Constructors
   */

  Concessionaria();
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
  void aumentarValorDoEstoque(int porcentagem);
  Automovel *encontrarAutomovelNoEstoque(string chassi, bool imprimir);

  /**
   * Overload
   */

  friend ostream &operator<<(ostream &stream, Concessionaria const concessionaria);
};
