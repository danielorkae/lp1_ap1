#include <iostream>
#include <string>
#include <vector>
#include "models/concessionaria.h"

using namespace std;

vector<Concessionaria *> concessionarias;

void criarConcessionaria();
Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir);

int main()
{

  return 0;
}

void criarConcessionaria()
{
  string nome, cnpj;
  int qntdEstoque;

  cout << "=== CADASTRO DE CONCESSIONáRIA ===" << endl;

  cout << "CNPJ: " << endl;
  cin >> cnpj;

  if (encontrarConcessionaria(cnpj, false) != NULL)
  {
    cout << "Esta concessionária já está cadastrada." << endl;
    return;
  }

  cout << "Nome: " << endl;
  cin >> nome;

  cout << "Qntd de estoque: " << endl;
  cin >> qntdEstoque;

  concessionarias.push_back(new Concessionaria(nome, cnpj, qntdEstoque));
}

Concessionaria *encontrarConcessionaria(string cnpj, bool imprimir)
{
  for (unsigned int i = 0; i < concessionarias.size(); i++)
  {
    auto concessionaria = concessionarias[i];

    if (concessionaria->getCnpj() == cnpj)
    {
      if (imprimir)
      {
        cout
            << "Concessionária " << concessionaria->getNome() << endl
            << "CNPJ: \t" << concessionaria->getCnpj() << endl
            << "Estoque: " << concessionaria->getQntEstoque() << endl;
      }

      return concessionaria;
    }
  }

  if (imprimir)
  {
    cout << "Nenhuma concessionária encontrada." << endl;
  }

  return NULL;
}
