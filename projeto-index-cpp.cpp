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

struct IndexCidade {
    int codigo_cidade;
    int endereco;
};

struct EspecialidadeMedica {
    int codigo_especialidade;
    string descricao;
};

struct IndexEspecialidadeMedica {
    int codigo_especialidade;
    int endereco;
};

struct Medico {
    int codigo_medico;
    string nome;
    int codigo_especialidade;
    string endereco;
    string telefone;
    int codigo_cidade;
};

struct IndexMedico {
    int codigo_medico;
    int endereco;
};

struct Paciente {
    int codigo_paciente;
    string nome;
    string endereco;
    int codigo_cidade;
};

struct IndexPaciente {
    int codigo_paciente;
    int endereco;
};

struct CID {
    int codigo_CID;
    string descricao;
};

struct IndexCID {
    int codigo_CID;
    int endereco;
};

struct Medicamento {
    int codigo_medicamento;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct IndexMedicamento {
    int codigo_medicamento;
    int endereco;
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

struct IndexConsulta {
    int codigo_consulta;
    int endereco;
};

// Funcoes
// Cidades
void inclusaoCidade(Cidade arq[], IndexCidade idx[], int &qtdRegistros);
void mostrarCidade(Cidade vetorCidades[], int qtdRegistros);

// Especialidade Medica
void inclusaoEspecialidadeMedica(EspecialidadeMedica arq[], IndexEspecialidadeMedica idx[], int &qtdRegistros);
void mostrarEspecialidadeMedica(EspecialidadeMedica vetorEspecialidades[], int qtdRegistros);

// Inclusao Medico
void inclusaoMedico(Medico arq[], IndexMedico idx[], int &qtdRegistros);
void mostrarMedico(Medico vetorMedicos[], int qtdRegistros);

// Paciente
void inclusaoPaciente(Paciente arq[], IndexPaciente idx[], int &qtdRegistros);
void mostrarPaciente(Paciente vetorPacientes[], int qtdRegistros);

// CID
void inclusaoCID(CID arq[], IndexCID idx[], int &qtdRegistros);
void mostrarCID(CID vetorCIDs[], int qtdRegistros);

// Medicamento
void inclusaoMedicamento(Medicamento arq[], IndexMedicamento idx[], int &qtdRegistros);
void mostrarMedicamento(Medicamento vetorMedicamentos[], int qtdRegistros);

// Consulta
void inclusaoConsulta(Consulta arq[], IndexConsulta idx[], int &qtdRegistros);
void mostrarConsulta(Consulta vetorConsultas[], int qtdRegistros);

int main() {
	
int qtdRegistrosCidade = 5;
Cidade cidades[T] = {
    {1, "Sao Paulo", "SP"},
    {2, "Rio de Janeiro", "RJ"},
    {3, "Belo Horizonte", "MG"},
    {4, "Salvador", "BA"},
    {5, "Fortaleza", "CE"}
};

IndexCidade indexCidades[T] = {
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

IndexEspecialidadeMedica indexEspecialidades[T] = {
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

IndexMedico indexMedicos[T] = {
    {1, 0},
    {2, 1},
    {3, 2},
    {4, 3},
    {5, 4}
};

int qtdRegistrosPaciente = 5;
Paciente pacientes[T] = {
    {1, "Jose da Silva", "Rua do Comercio, 10", 1},
    {2, "Ana Maria", "Rua das Flores, 20", 2},
    {3, "Carlos Eduardo", "Av. Brasil, 30", 3},
    {4, "Patricia Souza", "Rua da Paz, 40", 4},
    {5, "Marcelo Ferreira", "Rua das Acacias, 50", 5}
};

IndexPaciente indexPacientes[T] = {
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

IndexCID indexCIDs[T] = {
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

IndexMedicamento indexMedicamentos[T] = {
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

IndexConsulta indexConsultas[T] = {
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
                    cout << "2. Mostrar Medicos" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoMedico(medicos, indexMedicos, qtdRegistrosMedico);
                            getch();
                            break;
                        case 2:
                            mostrarMedico(medicos, qtdRegistrosMedico);
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
                    cout << "2. Mostrar Pacientes" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> escolhaOperacao;
                    
                    switch (escolhaOperacao) {
                        case 1:
                            inclusaoPaciente(pacientes, indexPacientes, qtdRegistrosPaciente);
                            getch();
                            break;
                        case 2:
                            mostrarPaciente(pacientes, qtdRegistrosPaciente);
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

// Implementar funções de inclusão
void inclusaoCidade(Cidade arq[], IndexCidade idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para Cidade
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

void inclusaoEspecialidadeMedica(EspecialidadeMedica arq[], IndexEspecialidadeMedica idx[], int &qtdRegistros) {
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

void inclusaoMedico(Medico arq[], IndexMedico idx[], int &qtdRegistros) {
//    for(int i = 0; i<T; i++ )
//	int codigo, i;
//	string nome, endereco;
//	cout << "Digite o codigo do registro: ";
//	cin >> codigo;
//	cout << "\nDigite o nome do cliente: ";
//	cin >> nome;
//	cout << "\nDigite o endereco do cliente: ";
//	cin >> endereco;
//	
//	arq[qtdRegistros].codigo = codigo;
//	arq[qtdRegistros].nome = nome;
//	arq[qtdRegistros].endereco = endereco;
//	arq[qtdRegistros].status = 0;
//
//	
//	for(i = qtdRegistros-1; i <= 0 && idx[i].codigo > codigo; i--){
//		idx[i+1].codigo = idx[i].codigo;
//		idx[i+1].endereco = idx[i].endereco;
//	}
//	
//	idx[i+1].codigo = codigo;
//	idx[i+1].endereco = qtdRegistros;
//	qtdRegistros++;
}

void mostrarMedico(Medico vetorMedicos[], int qtdRegistros) {
    cout << "=== MEDICOS ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo do Medico: " << vetorMedicos[i].codigo_medico << endl;
        cout << "Nome: " << vetorMedicos[i].nome << endl;
        cout << "Codigo da Especialidade: " << vetorMedicos[i].codigo_especialidade << endl;
        cout << "Endereco: " << vetorMedicos[i].endereco << endl;
        cout << "Telefone: " << vetorMedicos[i].telefone << endl;
        cout << "Codigo da Cidade: " << vetorMedicos[i].codigo_cidade << endl;
        cout << endl;
    }
}

void inclusaoPaciente(Paciente arq[], IndexPaciente idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para Paciente
}

void mostrarPaciente(Paciente vetorPacientes[], int qtdRegistros) {
    cout << "=== PACIENTES ===" << endl;
    for (int i = 0; i < qtdRegistros; i++) {
        cout << "**Registro " << i + 1 << "**" << endl;
        cout << "Codigo do Paciente: " << vetorPacientes[i].codigo_paciente << endl;
        cout << "Nome: " << vetorPacientes[i].nome << endl;
        cout << "Endereco: " << vetorPacientes[i].endereco << endl;
        cout << "Codigo da Cidade: " << vetorPacientes[i].codigo_cidade << endl;
        cout << endl;
    }
}

void inclusaoCID(CID arq[], IndexCID idx[], int &qtdRegistros) {
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

void inclusaoMedicamento(Medicamento arq[], IndexMedicamento idx[], int &qtdRegistros) {
    // Implementar funcao de inclusao para Medicamento
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

void inclusaoConsulta(Consulta arq[], IndexConsulta idx[], int &qtdRegistros) {
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



