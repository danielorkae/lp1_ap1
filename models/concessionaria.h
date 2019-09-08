#include <vector>
#include <string>
#include <vector>
#include "automovel.h"

using namespace std;

class Concessionaria
{
private:
  string nome;
  string cnpj;
  int qntEstoque;
  vector<Automovel *> estoque;

public:
  Concessionaria();
  Concessionaria(string nome, string cnpj);

  string getNome();
  string getCnpj();
  int getQntEstoque();
  vector<Automovel *> getEstoque();

  void setNome(string nome);
  void setCnpj(string cnpj);

  void adicionarAutomovelAoEstoque();
  Automovel *encontrarAutomovelNoEstoque(string chassi, bool imprimir);
};
