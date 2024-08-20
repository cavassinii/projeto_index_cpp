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

void reorganizacaoCliente(index vetIndex[], cliente vetClientes[], int &qtdRegistros, cliente cliAtualizado[], index indexAtualizado[]){
	int cont = 0;
	
	for(int i = 0; i < qtdRegistros; i++){
		if(vetClientes[vetIndex[i].endereco].status == 0){
			
			cliAtualizado[cont].codigo = vetClientes[vetIndex[i].endereco].codigo;
			cliAtualizado[cont].nome = vetClientes[vetIndex[i].endereco].nome;
			cliAtualizado[cont].endereco = vetClientes[vetIndex[i].endereco].endereco;
			cliAtualizado[cont].status = vetClientes[vetIndex[i].endereco].status;	
			
			indexAtualizado[cont].codigo = vetIndex[cont].codigo;
			indexAtualizado[cont].endereco = cont;	
			
			cont++;
		}
	}
	vetClientes = cliAtualizado;
	vetIndex = indexAtualizado;
	qtdRegistros = cont;
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
	
	cliente cliAtualizado[T];
	index indexAtualizado[T];
	/*mostrarIndex(indexCodClientes, qtdRegistros);
	
	inclusaoClientes(clientes, indexCodClientes, qtdRegistros);
	system("cls");
	
	mostrarClientes(clientes, qtdRegistros);
	mostrarIndex(indexCodClientes, qtdRegistros);*/
	
	exclusaoClientes(indexCodClientes, clientes, qtdRegistros);
	
	cout << "\n---------------CLIENTES ATIVOS-----------------" << endl;
	mostrarClientesAtivos(indexCodClientes, clientes, qtdRegistros);
	reorganizacaoCliente(indexCodClientes, clientes, qtdRegistros, cliAtualizado, indexAtualizado);

	cout << "\n---------------VETOR CLIENTES APOS REORGANIZACAO-----------------" << endl;
	mostrarClientes(cliAtualizado, qtdRegistros);
	cout << "\n---------------VETOR DE INDECE APOS REORGANIZACAO-----------------" << endl;
	mostrarIndex(indexCodClientes, qtdRegistros);
	
	system("cls");
	
	exclusaoClientes(indexCodClientes, clientes, qtdRegistros);
	
	cout << "\n---------------CLIENTES ATIVOS-----------------" << endl;
	mostrarClientesAtivos(indexCodClientes, clientes, qtdRegistros);
	reorganizacaoCliente(indexCodClientes, clientes, qtdRegistros, cliAtualizado, indexAtualizado);

	cout << "\n---------------VETOR CLIENTES APOS REORGANIZACAO-----------------" << endl;
	mostrarClientes(cliAtualizado, qtdRegistros);
	cout << "\n---------------VETOR DE INDECE APOS REORGANIZACAO-----------------" << endl;
	mostrarIndex(indexAtualizado, qtdRegistros);
	

	
	
	
}

