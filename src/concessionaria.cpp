#include "../include/concessionaria.h"

/**
 * Constructors and Destructors
 */

//Construtor Padrão
Concessionaria::Concessionaria() {}

//Destrutor Padrão
Concessionaria::~Concessionaria() {}

//Construtor com parâmetro, utilizando as propriedades da concessionaria
Concessionaria::Concessionaria(string nome, string cnpj, string tipo_propriedade, string nome_propriedade)
{
  setNome(nome);
  setCnpj(cnpj);
  setTipoPropriedade(tipo_propriedade);
  setNomePropriedade(nome_propriedade);
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

string Concessionaria::getTipo_propriedade()
{
  return tipo_propriedade;
}

string Concessionaria::getNome_propriedade()
{
  return nome_propriedade;
}

int Concessionaria::getEstoqueAutomovel()
{
  return estoque_automovel.size();
}

int Concessionaria::getEstoqueMoto()
{
  return estoque_moto.size();
}

int Concessionaria::getEstoqueCaminhao()
{
  return estoque_caminhao.size();
}

/**
 * Setters
 */

void Concessionaria::setNome(string _nome)
{
  this->nome = _nome;
}

void Concessionaria::setCnpj(string _cnpj)
{
  this->cnpj = _cnpj;
}

void Concessionaria::setTipoPropriedade(string _tipo_propriedade)
{
    this->tipo_propriedade = _tipo_propriedade;
}

void Concessionaria::setNomePropriedade(string _nome_propriedade)
{
  this->nome_propriedade = _nome_propriedade;
}

/**
 * Methods
 */

void Concessionaria::listarEstoque()
{
  cout << endl
       << "=== LISTAR VEÍCULOS NO ESTOQUE === " << endl
       << endl;

  /**
   * As impressões estão sendo feitas utilizando a sobrecarga do operador "<<", criado na classe Veículo
   */

  for (unsigned int i = 0; i < estoque_automovel.size(); i++)
  {
    cout << *estoque_automovel[i];
  }

  for (unsigned int i = 0; i < estoque_moto.size(); i++)
  {
    cout << *estoque_moto[i];
  }

  for (unsigned int i = 0; i < estoque_caminhao.size(); i++)
  {
    cout << *estoque_caminhao[i];
  }

  //Em caso de não haver nenhum veículo cadastrado ainda
  if (estoque_automovel.size() == 0 && estoque_caminhao.size() == 0 && estoque_moto.size() == 0)
  {
    cout << "Nenhum veículo em estoque." << endl;
  }
}

void Concessionaria::adicionarVeiculoAoEstoque()
{

  //variáveis auxiliares
  int entrada_tipo = 0, entrada = 0;

  //Propriedades do veículos
  string marca, chassi, motor, modelo, carga;
  float preco;
  int dia, mes, ano;

  cout << endl
       << "=== CADASTRO DE VEÍCULO ===" << endl;

  //Tipos de veículos disponíveis para cadastro
  cout << endl
       << "Selecione o tipo de veículo:"
       << endl 
       << "[1] Automovel"
       << endl
       << "[2] Moto"
       << endl
       << "[3] Caminhao"
       << endl
       << "Informe um numero: ";
  cin >> entrada_tipo;

  //Checkagem para conferir se o valor informado é valido
  if (entrada_tipo != 1 && entrada_tipo != 2 && entrada_tipo != 3)
  {
    cout << "Valor inserido invalido!!!";
    return;
  }

  cout << "Chassi (Apenas números): ";
  cin >> chassi;

  //Checando se o número do chassi cadastrado ja é existente
  if (encontrarVeiculoNoEstoque(chassi, false) != NULL)
  {
    cout << endl
         << "Veículo já cadastrado com esse número de chassi." << endl;
    return;
  }

  cout << "Marca: ";
  cin >> marca;

  cout << "Preço: ";
  cin >> preco;

  cout << "Data de fabricação (Informe um dado de cada vez, apenas numeros):" << endl;

  cout << "Dia: ";
  cin >> dia;

  cout << "Mes: ";
  cin >> mes;

  cout << "Ano: ";
  cin >> ano;

  if (entrada_tipo == 1) 
  {
    cout << "Tipo de motor: "
         << endl
         << "[1] Gasolina"
         << endl
         << "[2] Elétrico"
         << endl
         << "Informe um numero: ";
    cin >> entrada;

    if (entrada == 1)
    {
      motor = "Gasolina";
    }
    else if (entrada == 2)
    {
      motor = "Elétrico";
    }
    else
    {
      cout << "Valor inserido invalido!!!";
      return;
    }

    //adicionando o veículo cadastrado ao vetor do seu tipo específico
    estoque_automovel.push_back(new Automovel(marca, chassi, preco, dia, mes, ano, motor));
  }
  else if (entrada_tipo == 2)
  {
    cout << "Modelo: "
         << endl
         << "[1] Clássico"
         << endl
         << "[2] Esportivo"
         << endl
         << "Informe um numero: ";
    cin >> entrada;

    if (entrada == 1)
    {
      modelo = "Clássico";
    }
    else if (entrada == 2)
    {
      modelo = "Esportivo";
    }
    else
    {
      cout << "Valor inserido invalido!!!";
      return;
    }

    //adicionando o veículo cadastrado ao vetor do seu tipo específico
    estoque_moto.push_back(new Moto(marca, chassi, preco, dia, mes, ano, modelo));
  }
  else if (entrada_tipo == 3)
  {
    cout << "Tipo de carga: "
         << endl
         << "[1] Comum"
         << endl
         << "[2] Perigosa"
         << endl
         << "Informe um numero: ";
    cin >> entrada;

    if (entrada == 1)
    {
      carga = "Comum";
    }
    else if (entrada == 2)
    {
      carga = "Perigosa";
    }
    else
    {
      cout << "Valor inserido invalido!!!";
      return;
    }

    //adicionando o veículo cadastrado ao vetor do seu tipo específico
    estoque_caminhao.push_back(new Caminhao(marca, chassi, preco, dia, mes, ano, carga));
  }

  cout << endl
       << "Veículo cadastrado com sucesso!" << endl;
}

void Concessionaria::aumentarValorDoEstoque()
{
  float porcentagem;

  cout << endl
       << "=== AUMENTAR VALOR DO ESTOQUE ===" << endl;

  //Valor da porcentagem a ser aplicada em todos os Preços dos veículos
  cout << "Porcentagem de aumento (Apenas numeros entre 0 e 100): " << endl;
  cin >> porcentagem;

  for (unsigned int i = 0; i < estoque_automovel.size(); i++)
  {
    Automovel *automovel = estoque_automovel[i];

    automovel->addPercentage(porcentagem);
  }

  for (unsigned int i = 0; i < estoque_moto.size(); i++)
  {
    Moto *moto = estoque_moto[i];

    moto->addPercentage(porcentagem);
  }

  for (unsigned int i = 0; i < estoque_caminhao.size(); i++)
  {
    Caminhao *caminhao = estoque_caminhao[i];

    caminhao->addPercentage(porcentagem);
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

  for (unsigned int i = 0; i < estoque_automovel.size(); i++)
  {
    Automovel *automovel = estoque_automovel[i];

    int dia_fab = automovel->getDiaDataDeFabricacao();
    int mes_fab = automovel->getMesDataDeFabricacao();
    int ano_fab = automovel->getAnoDataDeFabricacao();

    //Utiliza a função calculaData para transformar o dia, mes e ano em um único valor inteiro, facilitando a subtração entre os valores
    int resultado = calculaData(dia_data_atual, mes_data_atual, ano_data_atual) - calculaData(dia_fab, mes_fab, ano_fab);

    //Impressão do veículo utilizando a sobrecarga de operador da class Veículo
    if (resultado <= 90)
    {
      cout << *estoque_automovel[i];
    }
  }

  for (unsigned int i = 0; i < estoque_moto.size(); i++)
  {
    Moto *moto = estoque_moto[i];

    int dia_fab = moto->getDiaDataDeFabricacao();
    int mes_fab = moto->getMesDataDeFabricacao();
    int ano_fab = moto->getAnoDataDeFabricacao();

    int resultado = calculaData(dia_data_atual, mes_data_atual, ano_data_atual) - calculaData(dia_fab, mes_fab, ano_fab);

    if (resultado <= 90)
    {
      cout << *estoque_moto[i];
    }
  }

  for (unsigned int i = 0; i < estoque_caminhao.size(); i++)
  {
    Caminhao *caminhao = estoque_caminhao[i];

    int dia_fab = caminhao->getDiaDataDeFabricacao();
    int mes_fab = caminhao->getMesDataDeFabricacao();
    int ano_fab = caminhao->getAnoDataDeFabricacao();

    int resultado = calculaData(dia_data_atual, mes_data_atual, ano_data_atual) - calculaData(dia_fab, mes_fab, ano_fab);

    if (resultado <= 90)
    {
      cout << *estoque_caminhao[i];
    }
  }
}

Veiculo *Concessionaria::encontrarVeiculoNoEstoque(string chassi, bool imprimir)
{
  for (unsigned int i = 0; i < estoque_automovel.size(); i++)
  {
    Automovel *automovel = estoque_automovel[i];

    if (automovel->getChassi() == chassi)
    {
      if (imprimir)
      {
        cout << "=== IMPRIMIR VEÍCULO ===" << endl
        << "Automovel" << endl
        << "Marca: \t" << automovel->getMarca() << endl
        << "Preço: \t\tR$ " << automovel->getPreco() << endl
        << "Chassi: \t" << automovel->getChassi() << endl
        << "Fabricação: \t" << automovel->getDiaDataDeFabricacao() << "/" << automovel->getMesDataDeFabricacao() << "/" << automovel->getAnoDataDeFabricacao() << endl
        << "Tipo de motor: \t" << automovel->getMotor() << endl
        << endl;
      }

      return automovel;
    }
  }

  for (unsigned int i = 0; i < estoque_moto.size(); i++)
  {
    Moto *moto = estoque_moto[i];

    if (moto->getChassi() == chassi)
    {
      if (imprimir)
      {
        cout << "=== IMPRIMIR VEÍCULO ===" << endl
        << "Moto" << endl
        << "Marca: \t" << moto->getMarca() << endl
        << "Preço: \t\tR$ " << moto->getPreco() << endl
        << "Chassi: \t" << moto->getChassi() << endl
        << "Fabricação: \t" << moto->getDiaDataDeFabricacao() << "/" << moto->getMesDataDeFabricacao() << "/" << moto->getAnoDataDeFabricacao() << endl
        << "Tipo de modelo: \t" << moto->getModelo() << endl
        << endl;
      }

      return moto;
    }
  }

  for (unsigned int i = 0; i < estoque_caminhao.size(); i++)
  {
    Caminhao *caminhao = estoque_caminhao[i];

    if (caminhao->getChassi() == chassi)
    {
      if (imprimir)
      {
        cout << "=== IMPRIMIR VEÍCULO ===" << endl
        << "Caminhão" << endl
        << "Marca: \t" << caminhao->getMarca() << endl
        << "Preço: \t\tR$ " << caminhao->getPreco() << endl
        << "Chassi: \t" << caminhao->getChassi() << endl
        << "Fabricação: \t" << caminhao->getDiaDataDeFabricacao() << "/" << caminhao->getMesDataDeFabricacao() << "/" << caminhao->getAnoDataDeFabricacao() << endl
        << "Tipo de carga: \t" << caminhao->getCarga() << endl
        << endl;
      }

      return caminhao;
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

void Concessionaria::pesquisaChassi()
{
  string _chassi;

  cout << endl
       << "=== PESQUISAR VEÍCULOS POR CHASSI ===" << endl;

  cout << "Informe o número de chassi a ser pesquisado (Apenas números): ";
  cin >> _chassi;

  encontrarVeiculoNoEstoque(_chassi, true);
}

int Concessionaria::valorTotal()
{
  int total = 0;
  
  for (unsigned int i = 0; i < estoque_automovel.size(); i++)
  {
    total += estoque_automovel[i]->getPreco();
  }

  for (unsigned int i = 0; i < estoque_moto.size(); i++)
  {
    total += estoque_moto[i]->getPreco();
  }

  for (unsigned int i = 0; i < estoque_caminhao.size(); i++)
  {
    total += estoque_caminhao[i]->getPreco();
  }

  return total;
}
