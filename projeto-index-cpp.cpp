#include <iostream>
#include <string>
#include <conio.h> 
using namespace std;

#define T 10

// Definicao das structs
struct Cidade {
    int codigo_cidade;
    string nome;
    string UF;
};

struct EspecialidadeMedica {
    int codigo_especialidade;
    string descricao;
};

struct Medico {
    int codigo_medico;
    string nome;
    int codigo_especialidade;
    string endereco;
    string telefone;
    int codigo_cidade;
    int status;
};

struct Paciente {
    int codigo_paciente;
    string nome;
    string endereco;
    int codigo_cidade;
    int status;
};

struct CID {
    int codigo_CID;
    string descricao;
};

struct Medicamento {
    int codigo_medicamento;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct Consulta {
    int codigo_consulta;
    int codigo_paciente;
    int codigo_medico;
    string data;
    string horario;
    int cod_CID;
    int cod_medicamento;
    int qtde_medicamento;
};

struct Index {
    int codigo;
    int endereco;
};

// Funcoes
// Cidades
void inclusaoCidade(Cidade arq[], Index idx[], int &qtdRegistros);
void mostrarCidade(Cidade vetorCidades[], int qtdRegistros);

// Especialidade Medica
void inclusaoEspecialidadeMedica(EspecialidadeMedica arq[], Index idx[], int &qtdRegistros);
void mostrarEspecialidadeMedica(EspecialidadeMedica vetorEspecialidades[], int qtdRegistros);

// Inclusao Medico
void inclusaoMedico(struct Medico medicos[],struct EspecialidadeMedica esp[],struct Cidade cidades[],struct Index ind[],struct Index ind_esp[],struct Index ind_cidade[],int &cont,int cont_esp,int cont_cidade);
void mostrarMedico(struct Medico medico[],struct Index ind[],int cont);
void exclusaoMedico(struct Medico medicos[],struct Index ind[],int cont,struct Index ind_consulta[],int cont_consulta);

// Paciente
void inclusaoPaciente(struct Paciente pacientes[],struct Index ind[],struct Cidade cidade[],struct Index ind_cidade[],int &cont,int cont_cidade);
void mostrarPaciente(struct Paciente paciente[],struct Index ind[],int cont);
void exclusaoPaciente(struct Paciente pacientes[],struct Index ind[],int cont,struct Index ind_consulta[],int cont_consulta);

// CID
void inclusaoCID(CID arq[], Index idx[], int &qtdRegistros);
void mostrarCID(CID vetorCIDs[], int qtdRegistros);

// Medicamento
void inclusaoMedicamento(Medicamento arq[], Index idx[], int &qtdRegistros);
void mostrarMedicamento(Medicamento vetorMedicamentos[], int qtdRegistros);

// Consulta
void inclusaoConsulta(Consulta arq[], Index idx[], int &qtdRegistros);
void mostrarConsulta(Consulta vetorConsultas[], int qtdRegistros);

int busca (struct Index idx[], int cont, int cod);

int main() {
	
int qtdRegistrosCidade = 5;
Cidade cidades[T] = {
    {1, "Sao Paulo", "SP"},
    {2, "Rio de Janeiro", "RJ"},
    {3, "Belo Horizonte", "MG"},
    {4, "Salvador", "BA"},
    {5, "Fortaleza", "CE"}
};

Index indexCidades[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosEspecialidade = 5;
EspecialidadeMedica especialidades[T] = {
    {1, "Cardiologia"},
    {2, "Neurologia"},
    {3, "Pediatria"},
    {4, "Ortopedia"},
    {5, "Dermatologia"}
};

Index indexEspecialidades[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosMedico = 5;
Medico medicos[T] = {
    {1, "Dr. Joao Silva", 1, "Av. Paulista, 1000", "(11) 1234-5678", 1},
    {2, "Dra. Maria Oliveira", 2, "Rua da Assembleia, 500", "(21) 2345-6789", 2},
    {3, "Dr. Pedro Santos", 3, "Praca da Liberdade, 300", "(31) 3456-7890", 3},
    {4, "Dra. Ana Costa", 4, "Av. Sete de Setembro, 400", "(71) 4567-8901", 4},
    {5, "Dr. Carlos Almeida", 5, "Rua de Caxias, 700", "(85) 5678-9012", 5}
};

Index indexMedicos[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosPaciente = 5;
Paciente pacientes[T] = {
    {1, "Jose da Silva", "Rua do Comercio, 10", 1, 0},
    {2, "Ana Maria", "Rua das Flores, 20", 2, 0},
    {3, "Carlos Eduardo", "Av. Brasil, 30", 3, 0},
    {4, "Patricia Souza", "Rua da Paz, 40", 4, 0},
    {5, "Marcelo Ferreira", "Rua das Acacias, 50", 5, 0}
};

Index indexPacientes[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosCID = 5;
CID cids[T] = {
    {1, "A00 - Colera"},
    {2, "B01 - Tuberculose"},
    {3, "C34 - Neoplasia Maligna do Pulmao"},
    {4, "D50 - Anemia Ferropriva"},
    {5, "E11 - Diabetes Tipo 2"}
};

Index indexCIDs[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosMedicamento = 5;
Medicamento medicamentos[T] = {
    {1, "Paracetamol", 100, 10, 200, 4.99},
    {2, "Amoxicilina", 150, 20, 300, 8.50},
    {3, "Ibuprofeno", 200, 30, 250, 6.75},
    {4, "Omeprazol", 250, 40, 300, 9.10},
    {5, "Dipirona", 300, 50, 350, 5.25}
};

Index indexMedicamentos[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosConsulta = 5;
Consulta consultas[T] = {
    {1, 1, 1, "2024-01-10", "08:30", 1, 1, 1},
    {2, 2, 2, "2024-01-15", "09:00", 2, 2, 1},
    {3, 3, 3, "2024-01-20", "10:00", 3, 3, 2},
    {4, 4, 4, "2024-01-25", "11:00", 4, 4, 2},
    {5, 5, 5, "2024-01-30", "14:00", 5, 5, 3}
};

Index indexConsultas[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

    int escolhaTabela, escolhaOperacao;

    do {
        system("cls");
        cout << "=== MENU PRINCIPAL ===" << endl;
        cout << "1. Cidades" << endl;
        cout << "2. Especialidades Medicas" << endl;
        cout << "3. Medicos" << endl;
        cout << "4. Pacientes" << endl;
        cout << "5. CID" << endl;
        cout << "6. Medicamentos" << endl;
        cout << "7. Consultas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolhaTabela;
        
        switch (escolhaTabela) {
            case 1: // Cidades
                do {
                    system("cls");
                    cout << "=== CIDADES ===" << endl;
                    cout << "1. Incluir Cidade" << endl;
                    cout << "2. Mostrar Cidades" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoCidade(cidades, indexCidades, qtdRegistrosCidade);
                            getch();
                            break;
                        case 2:
                            mostrarCidade(cidades, qtdRegistrosCidade);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 2: // Especialidades Medicas
                do {
                    system("cls");
                    cout << "=== ESPECIALIDADES MEDICAS ===" << endl;
                    cout << "1. Incluir Especialidade Medica" << endl;
                    cout << "2. Mostrar Especialidades Medicas" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoEspecialidadeMedica(especialidades, indexEspecialidades, qtdRegistrosEspecialidade);
                            getch();
                            break;
                        case 2:
                            mostrarEspecialidadeMedica(especialidades, qtdRegistrosEspecialidade);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 3: // Medicos
                do {
                    system("cls");
                    cout << "=== MEDICOS ===" << endl;
                    cout << "1. Incluir Medico" << endl;
                    cout << "2. Excluir Medico" << endl;
                    cout << "3. Mostrar Medicos" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoMedico(medicos, especialidades, cidades, indexMedicos, indexEspecialidades, indexCidades, qtdRegistrosMedico, qtdRegistrosEspecialidade, qtdRegistrosCidade);
                            getch();
                            break;
                        case 2:
                            exclusaoMedico(medicos, indexMedicos, qtdRegistrosMedico, indexConsultas, qtdRegistrosConsulta);
                            getch();
                            break;
                        case 3:
                            mostrarMedico(medicos, indexMedicos, qtdRegistrosMedico);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 4: // Pacientes
                do {
                    system("cls");
                    cout << "=== PACIENTES ===" << endl;
                    cout << "1. Incluir Paciente" << endl;
                    cout << "2. Excluir Paciente" << endl;
                    cout << "3. Mostrar Pacientes" << endl;        
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoPaciente(pacientes, indexPacientes, cidades, indexCidades, qtdRegistrosPaciente, qtdRegistrosCidade);
                            getch();
                            break;
                        case 2:
                            exclusaoPaciente(pacientes, indexPacientes, qtdRegistrosPaciente, indexConsultas, qtdRegistrosConsulta);
                            getch();
                            break;
                        case 3:
                            mostrarPaciente(pacientes, indexPacientes, qtdRegistrosPaciente);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 5: // CID
                do {
                    system("cls");
                    cout << "=== CID ===" << endl;
                    cout << "1. Incluir CID" << endl;
                    cout << "2. Mostrar CID" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoCID(cids, indexCIDs, qtdRegistrosCID);
                            getch();
                            break;
                        case 2:
                            mostrarCID(cids, qtdRegistrosCID);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 6: // Medicamentos
                do {
                    system("cls");
                    cout << "=== MEDICAMENTOS ===" << endl;
                    cout << "1. Incluir Medicamento" << endl;
                    cout << "2. Mostrar Medicamentos" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoMedicamento(medicamentos, indexMedicamentos, qtdRegistrosMedicamento);
                            getch();
                            break;
                        case 2:
                            mostrarMedicamento(medicamentos, qtdRegistrosMedicamento);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 7: // Consultas
                do {
                    system("cls");
                    cout << "=== CONSULTAS ===" << endl;
                    cout << "1. Incluir Consulta" << endl;
                    cout << "2. Mostrar Consultas" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoConsulta(consultas, indexConsultas, qtdRegistrosConsulta);
                            getch();
                            break;
                        case 2:
                            mostrarConsulta(consultas, qtdRegistrosConsulta);
                            getch();
                            break;
                        case 0:
                            system("cls");
                            break;
                        default:
                            cout << "Opcao invalida, tente novamente." << endl;
                            getch();
                            break;
                    }
                } while (escolhaOperacao != 0);
                break;
            
            case 0: // Sair
                cout << "Saindo do programa." << endl;
                break;
            
            default:
                cout << "Opcao invalida, tente novamente." << endl;
                getch();
        }
    } while (escolhaTabela != 0);

    return 0;
}

void mostrarCidade(Cidade vetorCidades[], int qtdRegistros) {
    cout << "=== CIDADES ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo da Cidade: " << vetorCidades[i].codigo_cidade << endl;
        cout << "Nome: " << vetorCidades[i].nome << endl;
        cout << "UF: " << vetorCidades[i].UF << endl;
        cout << endl;
    }
}

void inclusaoEspecialidadeMedica(EspecialidadeMedica arq[], Index idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para Especialidade Medica
}

void mostrarEspecialidadeMedica(EspecialidadeMedica vetorEspecialidades[], int qtdRegistros) {
    cout << "=== ESPECIALIDADES MEDICAS ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo da Especialidade: " << vetorEspecialidades[i].codigo_especialidade << endl;
        cout << "Descricao: " << vetorEspecialidades[i].descricao << endl;
        cout << endl;
    }
}

void inclusaoMedico(struct Medico medicos[],struct EspecialidadeMedica esp[],struct Cidade cidades[],struct Index ind[],struct Index ind_esp[],struct Index ind_cidade[],int &cont,int cont_esp,int cont_cidade){
	int cod=0;
		
	for(int x=1;x != -1;){
		cout<<" Incluir um novo Medico "<< endl;
		cout<<" Cod: ";
		cin>>medicos[cont].codigo_medico;
		cin.ignore();
		if(busca(ind,cont,medicos[cont].codigo_medico) == -1){
			cod=medicos[cont].codigo_medico;
			cout<<" Nome: ";
			getline(cin,medicos[cont].nome);
			cout<<" Codigo da Especialidade: ";
			cin>> medicos[cont].codigo_especialidade;
			cin.ignore();
			int result = busca(ind_esp,cont_esp,medicos[cont].codigo_especialidade);
			cout<<" Descricao: "<< esp[result].descricao <<endl;
			cout <<" Endereco : ";
			getline(cin,medicos[cont].endereco);
			cout<<" Codigo da Cidade: ";
			cin>>medicos[cont].codigo_cidade;
			cin.ignore();
			result = busca(ind_cidade,cont_cidade,medicos[cont].codigo_cidade);
			cout<<" Cidade: " << cidades[result].nome << " | " << cidades[result].UF <<endl;
			cout<<" Telefone: ";
			getline(cin,medicos[cont].telefone);
			cout<<"\n### Medico Cadastrado com sucesso### "<<endl;
			medicos[cont].status = 0;
			x= -1;  	
		}
		else{
			cout<<"\n ### Codigo ja existente ### \n" <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].codigo > cod ;i--){
		ind[i+1].codigo = ind[i].codigo;
		ind[i+1].endereco = ind[i].endereco;
		
	}
	
	ind[i+1].codigo = cod;
	ind[i+1].endereco = cont;
	cont++;
}

void exclusaoMedico(struct Medico medicos[],struct Index ind[],int cont,struct Index ind_consulta[],int cont_consulta){
	int ex;
	for(int x=1;x != -1;){
		cout<<" Digite o codigo da exclusao do Medico: ";
		cin>>ex;
		if(ex == 0){
			x=-1;
		}
		else{
			int result = busca(ind,cont,ex);
			if(result != -1){
				if(busca(ind_consulta,cont_consulta,medicos[result].codigo_medico) == -1){
					if(medicos[result].status != 1){
						cout << "\n Codigo do Medico: " << medicos[result].codigo_medico; 
					    cout << "\n Nome: " << medicos[result].nome;
					    medicos[result].status = 1;
					    cout<<"\n\n ### Medico Excluido com Sucesso ### \n" <<endl;
					    x=-1;
					}
					else{
						cout<<"\n ### Medico ja Excluido ### \n" <<endl;
					}
				}	
				else{
					cout<<"\n ### Nao foi possivel concluir a operacao ### " <<endl;
					cout<<"\n Medico esta cadastrado em uma consulta \n" <<endl;
				}
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}	
	}	
}

void mostrarMedico(struct Medico medico[],struct Index ind[],int cont){
	cout << "=== MEDICOS ===" << endl;
	for(int i=0;i<cont;i++){
		int k= ind[i].endereco;
		if(medico[k].status ==0 ){
            cout << "\n\n\n**Registro " << k + 1 << "**";
			cout << "\nCodigo do Medico: " << medico[k].codigo_medico;
	        cout << "\nNome: " << medico[k].nome;
	        cout << "\nEspecialidade: " << medico[k].codigo_especialidade;
			cout << "\nEndereco: " << medico[k].endereco;
			cout << "\nTelefone: " << medico[k].telefone;
	        cout << "\nCidade: " << medico[k].codigo_cidade << endl;
        }
	}
}

void inclusaoPaciente(struct Paciente pacientes[],struct Index ind[],struct Cidade cidade[],struct Index ind_cidade[],int &cont,int cont_cidade){
	int cod=0;	
	for(int x=1;x != -1;){
		cout<<" Incluir um novo Paciente "<< endl;
		cout<<" Cod: ";
		cin>>pacientes[cont].codigo_paciente;
		cin.ignore();
		if(busca(ind,cont,pacientes[cont].codigo_paciente) == -1){
			cod=pacientes[cont].codigo_paciente;
			cout<<" Nome: ";
			getline(cin,pacientes[cont].nome);
			cout <<" Endereco : ";
			getline(cin,pacientes[cont].endereco);
			cout<<" Codigo da Cidade: ";
			cin>>pacientes[cont].codigo_cidade;
			cin.ignore();
			int result = busca(ind_cidade,cont_cidade,pacientes[cont].codigo_cidade);
			cout<<" Cidade: " << cidade[result].nome<< " | " << cidade[result].UF <<endl;
			pacientes[cont].status =0;
			cout<<"\n### Paciente Cadastrado com sucesso ###"<<endl;
			x= -1;  	
		}
		else{
			cout<<"\n ### Codigo ja existente ### \n" <<endl;
		}
	}
	
	int i=0;
	for(i=cont-1; i>= 0 && ind[i].codigo > cod ;i--){
		ind[i+1].codigo = ind[i].codigo;
		ind[i+1].endereco = ind[i].endereco;
	}
	
	ind[i+1].codigo = cod;
	ind[i+1].endereco = cont;
	cont++;
}

void mostrarPaciente(struct Paciente paciente[],struct Index ind[],int cont){
	cout << "=== PACIENTES ===" << endl;
	for(int i=0;i<cont;i++){
		int k= ind[i].endereco;
		if(paciente[k].status ==0 ){
            cout << "\n\n\n**Registro " << k + 1 << "**";
			cout << "\nCodigo do Paciente: " << paciente[k].codigo_paciente;
	        cout << "\nNome: " << paciente[k].nome;
			cout << "\nEndereco: " << paciente[k].endereco;
	        cout << "\nCidade: " << paciente[k].codigo_cidade << endl;
        }
	}
}

void exclusaoPaciente(struct Paciente pacientes[],struct Index ind[],int cont,struct Index ind_consulta[],int cont_consulta){
	int ex;
	for(int x=1;x != -1;){
		cout<<" Digite o codigo da exclusao do Paciente: ";
		cin>>ex;
		if(ex ==0 ){
			x=-1;
		}
		else{
			int result = busca(ind,cont,ex);
			if(result != -1){
				if(busca(ind_consulta,cont_consulta,pacientes[result].codigo_paciente) == -1){
					if(pacientes[result].status != 1){
						cout << "\n Paciente: " << pacientes[result].codigo_paciente << " -- " << pacientes[result].nome<<endl;
					    pacientes[result].status = 1;
					    cout<<"\n\n ### Paciente Ecluido com Sucesso ### \n" <<endl;
					    x=-1;
					}
					else{
						cout<<"\n ### Paciente ja Excluido ### \n" <<endl;
					}
				}	
				else{
					cout<<"\n ### Nao foi possivel concluir a operacao ### " <<endl;
					cout<<"\n Paciente esta cadastrado em uma consulta \n" <<endl;
				}
			}
			else{
				cout<<"\n ### Codigo nao existente ### \n" <<endl;
			}
		}

	}	
}

void inclusaoCID(CID arq[], Index idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para CID
}

void mostrarCID(CID vetorCIDs[], int qtdRegistros) {
    cout << "=== CID ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo CID: " << vetorCIDs[i].codigo_CID << endl;
        cout << "Descricao: " << vetorCIDs[i].descricao << endl;
        cout << endl;
    }
}

void leituraMedicamento(struct Medicamento medicamento[],int &cont){

	int i = 0;    
	for (int saida = 1; i < T && saida != 0; i++){
		cout<<"\n**Registro [ "<<i + 1<<" ]**"<<endl;
		cout << " Codigo do Medicamento: ";
        cin >> medicamento[i].codigo_medicamento;
        cin.ignore();
		if (medicamento[i].codigo_medicamento > 0){
			cout << " Descricao do Medicamento: ";
            getline(cin,medicamento[i].descricao);
            cout << " Quantidade em Estoque: ";
            cin >> medicamento[i].quant_estoque;
            cin.ignore();
            cout << " Quantidade Minima de Estoque: ";
            cin >> medicamento[i].estoque_minimo;
            cin.ignore();
            cout << " Quantidade Maxima de Estoque: ";
            cin >> medicamento[i].estoque_maximo;
            cout << " Preco Unitario do Medicamento: ";
            cin >> medicamento[i].preco_unitario;
            cin.ignore();
        }
        else saida = 0;
    }
    cont = i-1;
}

void mostrarMedicamento(Medicamento vetorMedicamentos[], int qtdRegistros) {
    cout << "=== MEDICAMENTOS ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo do Medicamento: " << vetorMedicamentos[i].codigo_medicamento << endl;
        cout << "Descricao: " << vetorMedicamentos[i].descricao << endl;
        cout << "Quantidade em Estoque: " << vetorMedicamentos[i].quant_estoque << endl;
        cout << "Estoque Minimo: " << vetorMedicamentos[i].estoque_minimo << endl;
        cout << "Estoque Maximo: " << vetorMedicamentos[i].estoque_maximo << endl;
        cout << "Preco Unitario: R$ " << vetorMedicamentos[i].preco_unitario << endl;
        cout << endl;
    }
}

void inclusaoConsulta(Consulta arq[], Index idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para Consulta
}

void mostrarConsulta(Consulta vetorConsultas[], int qtdRegistros) {
    cout << "=== CONSULTAS ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo da Consulta: " << vetorConsultas[i].codigo_consulta << endl;
        cout << "Codigo do Paciente: " << vetorConsultas[i].codigo_paciente << endl;
        cout << "Codigo do Medico: " << vetorConsultas[i].codigo_medico << endl;
        cout << "Data: " << vetorConsultas[i].data << endl;
        cout << "Horario: " << vetorConsultas[i].horario << endl;
        cout << "Codigo CID: " << vetorConsultas[i].cod_CID << endl;
        cout << "Codigo do Medicamento: " << vetorConsultas[i].cod_medicamento << endl;
        cout << "Quantidade de Medicamento: " << vetorConsultas[i].qtde_medicamento << endl;
        cout << endl;
    }
}

int busca (struct Index idx[], int cont, int cod){
    int i = 0, f = cont-1;
    int m = (i + f) / 2;
    if(f == -1){
    	return -1;
	}
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2){
        if (cod > idx[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigo){
    	return idx[m].endereco;
    }
    else return -1;
}
