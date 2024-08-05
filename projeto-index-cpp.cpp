#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

#define T 10

struct cliente{
	int codigo;
	string nome;
	string endereco;
};

struct index{
	int codigo;
	int endereco;
};

void inclusaoClientes(cliente arq[], index idx[], int &qtdRegistros){
	int codigo, i;
	string nome, endereco;
	cout << "Digite o codigo do registro: ";
	cin >> codigo;
	cout << "\nDigite o nome do cliente: ";
	cin >> nome;
	cout << "\nDigite o endereco do cliente: ";
	cin >> endereco;
	
	arq[qtdRegistros].codigo = codigo;
	arq[qtdRegistros].nome = nome;
	arq[qtdRegistros].endereco = endereco;

	
	for(i = qtdRegistros-1; idx[i].codigo > codigo; i--){
		idx[i+1].codigo = idx[i].codigo;
		idx[i+1].endereco = idx[i].endereco;
	}
	
	idx[i+1].codigo = codigo;
	idx[i+1].endereco = qtdRegistros;
	qtdRegistros++;
	
}

void mostrarClientes(cliente vetorClientes[], int qtdRegistros) {
    cout << "=== CLIENTES ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorClientes[i].codigo << endl;
        cout << "Nome: " << vetorClientes[i].nome << endl;
        cout << "Endereco: " << vetorClientes[i].endereco << endl;
        cout << endl;
    }
}

void mostrarIndex(index vetIndex[], int qtdRegistros) {
    cout << "=== IDX COD CLIENTES ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "Codigo: " << vetIndex[i].codigo << endl;
        cout << "Endereco: " << vetIndex[i].endereco << endl;
        cout << endl;
    }
}


int main(){
	int qtdRegistros = 5;
	
	cliente clientes[T] = {
	{1, "Joao", "J"},
	{2, "Maria", "M"},
	{7, "Jose", "J"},
	{3, "Pedro", "p"},
	{5, "Fernanda", "F"},
	};
	 
	index indexCodClientes[T] = {
	{1,0},
	{2,1},
	{3,3},
	{5,4},
	{7,2},
	};
	
	mostrarIndex(indexCodClientes, qtdRegistros);
	
	inclusaoClientes(clientes, indexCodClientes, qtdRegistros);
	system("cls");
	
	mostrarClientes(clientes, qtdRegistros);
	mostrarIndex(indexCodClientes, qtdRegistros);
	
	
}

