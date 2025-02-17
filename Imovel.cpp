#include <string>
#include "Imovel.h"
#include "Financiamento.h"
using namespace std;

//construtor
Imovel::Imovel(string _endereco, int _areaConstruida, int _qntQuartos, int _qntBanheiros, int _qntVagas) {
    this->areaConstruida = _areaConstruida;
    this->qntQuartos = _qntQuartos;
    this->qntBanheiros = _qntBanheiros;
    this->qntVagas = _qntVagas;
    this->endereco = _endereco;
}

void Imovel::setEndereco(string _endereco) {
    this->endereco = _endereco;
}

string Imovel::getEndereco() {
    return this->endereco;
}

void Imovel::valorImovel(double valorDoImovel) {
    this->precoImovel = valorDoImovel;
}

double Imovel::getValorImovel() {
    return this->precoImovel;
}

//criando financiamento a partir de imovel
Financiamento Imovel::criaObjetoFinanciamento(Imovel imovel) {
    string banco;
    double valorEntrada;
    int meses;
    cout << "O valor total do im�vel � R$" << imovel.getValorImovel() << ". Efetue o pagamento.\n" << endl;
    cout << "\n-----Digite as seguintes informa��es de pagamento para dar continuidade-----" << endl;
    cout << "Banco: ";
    cin.ignore();
    getline(cin, banco);
    cout << "Valor da Entrada: ";
    cin >> valorEntrada;
    cout << "Meses de parcela: ";
    cin >> meses;
    Financiamento financiamento(banco, valorEntrada, meses);
    financiamento.calculoFinanciamento(imovel.getValorImovel());
    cout << "-----As informa��es foram processadas-----" << endl;
    return financiamento;
}
