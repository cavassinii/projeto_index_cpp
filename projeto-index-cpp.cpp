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
	int status;
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
	arq[qtdRegistros].status = 0;

	
	for(i = qtdRegistros-1; i <= 0 && idx[i].codigo > codigo; i--){
		idx[i+1].codigo = idx[i].codigo;
		idx[i+1].endereco = idx[i].endereco;
	}
	
	idx[i+1].codigo = codigo;
	idx[i+1].endereco = qtdRegistros;
	qtdRegistros++;
	
}

int exclusaoClientes(index vetIndex[], cliente vetClientes[], int qtdRegistros) {
	int cod;
	
	cout << "\nDigite o codigo do cadastro a ser excluido: ";
	cin >> cod;
	
    int i = 0, f = qtdRegistros - 1;
    int m = (i + f) / 2;
    for (; f >= i && cod != vetIndex[m].codigo; m = (i + f) / 2){
        if (cod > vetIndex[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == vetIndex[m].codigo){
     	vetClientes[vetIndex[m].endereco].status = 1;
     	cout << "\nRegistro excluido com sucesso" << endl;
      
    }
    else
       cout << "\nCliente nao encontrado " << endl;
    

}

void mostrarClientes(cliente vetorClientes[], int qtdRegistros) {
    cout << "=== CLIENTES ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo: " << vetorClientes[i].codigo << endl;
        cout << "Nome: " << vetorClientes[i].nome << endl;
        cout << "Endereco: " << vetorClientes[i].endereco << endl;
        cout << "Status: " << vetorClientes[i].status << endl;
        cout << endl;
    }
}

void mostrarClientesAtivos(index indexClientes[], cliente vetorClientes[], int qtdRegistros) {
	int i = 0;
    cout << "=== CLIENTES ===" << endl;
    while(i < qtdRegistros){
    	if(vetorClientes[indexClientes[i].endereco].status == 0){	
        	cout << "**Registro " << i + 1 << "**" << endl;
        	cout << "Codigo: " << vetorClientes[indexClientes[i].endereco].codigo << endl;
        	cout << "Nome: " << vetorClientes[indexClientes[i].endereco].nome << endl;
        	cout << "Endereco: " << vetorClientes[indexClientes[i].endereco].endereco << endl;
        	cout << endl;
        	
        	i++;
    	}else i++;
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
	{1, "Joao", "J", 0},
	{2, "Maria", "M", 0},
	{7, "Jose", "J", 0},
	{3, "Pedro", "p", 0},
	{5, "Fernanda", "F", 0},
	};
	 
	index indexCodClientes[T] = {
	{1,0},
	{2,1},
	{3,3},
	{5,4},
	{7,2},
	};
	
	/*mostrarIndex(indexCodClientes, qtdRegistros);
	
	inclusaoClientes(clientes, indexCodClientes, qtdRegistros);
	system("cls");
	
	mostrarClientes(clientes, qtdRegistros);
	mostrarIndex(indexCodClientes, qtdRegistros);*/
	
	exclusaoClientes(indexCodClientes, clientes, qtdRegistros);
	mostrarClientes(clientes, qtdRegistros);
	mostrarClientesAtivos(indexCodClientes, clientes, qtdRegistros);
	
	
}

