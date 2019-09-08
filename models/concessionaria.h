#include <string>

using namespace std;

class Concessionaria
{
private:
  string nome;
  string cnpj;
  int qntEstoque;

public:
  string getNome();
  string getCnpj();
  int getQntEstoque();

  void setNome(string nome);
  void setCnpj(string cnpj);
  void setQntEstoque(int qntEstoque);

  Concessionaria();
  Concessionaria(string nome, string cnpj);
  Concessionaria(string nome, string cnpj, int qntEstoque);
};
