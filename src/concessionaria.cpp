#include <iostream>
#include <vector>
#include "../include/concessionaria.h"
#include "../include/automovel.h"

/**
 * Constructors and Destructors
 */

Concessionaria::Concessionaria() {}

Concessionaria::~Concessionaria() {}

Concessionaria::Concessionaria(string nome, string cnpj)
{
  setNome(nome);
  setCnpj(cnpj);
}

/**
 * Getters
 */

string Concessionaria::getNome()
{
  return nome;
}

string Concessionaria::getCnpj()
{
  return cnpj;
}

int Concessionaria::getQntEstoque()
{
  return estoque.size();
}

/**
 * Setters
 */

void Concessionaria::setNome(string nome)
{
  this->nome = nome;
}

void Concessionaria::setCnpj(string cnpj)
{
  this->cnpj = cnpj;
}

/**
 * Methods
 */

void Concessionaria::listarEstoque()
{
  cout << endl
       << "=== LISTAR AUTOMÓVEIS NO ESTOQUE === " << endl
       << endl;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    cout << *estoque[i];
  }

  if (estoque.size() == 0)
  {
    cout << "Nenhum automóvel em estoque." << endl;
  }
}

void Concessionaria::adicionarAutomovelAoEstoque()
{
  string modelo, marca, chassi;
  float preco;
  int dia, mes, ano;

  cout << endl
       << "=== CADASTRO DE AUTOMÓVEL ===" << endl;

  cout << "Chassi: ";
  cin >> chassi;

  if (encontrarAutomovelNoEstoque(chassi, false) != NULL)
  {
    cout << endl
         << "Automóvel já cadastrado com esse número de chassi." << endl;
    return;
  }

  cout << "Marca: ";
  cin >> marca;

  cout << "Modelo: ";
  cin >> modelo;

  cout << "Preço: ";
  cin >> preco;

  cout << "Data de fabricação (Informe um dado de cada vez, apenas numeros):" << endl;

  cout << "Dia: ";
  cin >> dia;

  cout << "Mes: ";
  cin >> mes;

  cout << "Ano: ";
  cin >> ano;

  estoque.push_back(new Automovel(marca, modelo, chassi, preco, dia, mes, ano));

  cout << endl
       << "Automóvel cadastrado com sucesso!" << endl;
}

void Concessionaria::aumentarValorDoEstoque()
{
  float porcentagem;

  cout << endl
       << "=== AUMENTAR VALOR DO ESTOQUE ===" << endl;

  cout << "Porcentagem de aumento (Apenas numeros entre 0 e 100): " << endl;
  cin >> porcentagem;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    Automovel *automovel = estoque[i];

    automovel->addPercentage(porcentagem);
  }
}

void Concessionaria::listarCarros90()
{

  int dia_data_atual;
  int mes_data_atual;
  int ano_data_atual;

  cout << endl
       << "=== INFORMAR CARROS COM 90 DIAS DE USO ===" << endl;

  cout << "Data atual (Informe um dado de cada vez, apenas numeros):" << endl;

  cout << "Dia: ";
  cin >> dia_data_atual;

  cout << "Mes: ";
  cin >> mes_data_atual;

  cout << "Ano: ";
  cin >> ano_data_atual;

  cout << endl
       << "CARROS COM MENOS DE 90 DIAS DE USO:" << endl
       << endl;

  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    Automovel *automovel = estoque[i];

    int dia_fab = automovel->getDiaDataDeFabricacao();
    int mes_fab = automovel->getMesDataDeFabricacao();
    int ano_fab = automovel->getAnoDataDeFabricacao();

    int resultado = calculaData(dia_data_atual, mes_data_atual, ano_data_atual) - calculaData(dia_fab, mes_fab, ano_fab);

    if (resultado <= 90)
    {
      cout << *estoque[i];
    }
  }
}

Automovel *Concessionaria::encontrarAutomovelNoEstoque(string chassi, bool imprimir)
{
  for (unsigned int i = 0; i < estoque.size(); i++)
  {
    Automovel *automovel = estoque[i];

    if (automovel->getChassi() == chassi)
    {
      if (imprimir)
      {
        cout << automovel;
      }

      return automovel;
    }
  }

  if (imprimir)
  {
    cout << endl
         << "Nenhum automóvel encontrado." << endl;
  }

  return NULL;
}

int Concessionaria::calculaData(int day, int month, int year)
{

  if (month < 3)
    year--, month += 12;

  return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}