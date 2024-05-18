#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estrutura para representar um participante
struct Participante {
    int id;
    string nome;
    string semestre;
    int ano;
    string curso;
};

// Classe para gerenciar a Turma do Café
class TurmaDoCafe {
private:
    vector<Participante> participantes;

public:
    // Método para adicionar novo participante
    void adicionar_participante(int id, string nome, string semestre, int ano, string curso) {
        Participante novo_participante = {id, nome, semestre, ano, curso};
        participantes.push_back(novo_participante);
    }

    // Método para mostrar todos os participantes
    void mostrar_participantes() {
        cout << "Participantes da Turma do Café:" << endl;
        for (const auto& participante : participantes) {
            cout << "ID: " << participante.id << endl << "Nome: " << participante.nome << endl << "Semestre: " << participante.semestre << endl << "Ano ingressante: " << participante.ano << endl << "Curso: " << endl;
        }
    }

    // Método para buscar participante pelo ID
    Participante* buscar_participante_por_id(int id) {
        for (auto& participante : participantes) {
            if (participante.id == id) {
                return &participante;
            }
        }
        return nullptr;
    }

    // Método para editar dados do participante (exceto o ID)
    void editar_dados_participante(int id) {
        Participante* participante = buscar_participante_por_id(id);
        if (participante) {
            cout << "Editar dados do participante com ID " << id << endl;
            cout << "Nome: ";
            getline(cin, participante->nome);
            cout << "Semestre: ";
            getline(cin, participante->semestre);
            cout << "Ano: ";
            cin >> participante->ano;
            cout << "Curso (DSM/SI/GE): ";
            cin >> participante->curso;
            cout << "Dados do participante atualizados com sucesso!" << endl;
        } else {
            cout << "Participante com ID " << id << " não encontrado." << endl;
        }
    }
};

int main() {
    TurmaDoCafe turma_cafe;

    // Função para inserir novos participantes
    auto inserir_participantes = [&turma_cafe]() {
        cout << "Inserir novo participante da Turma do Café" << endl;
        int id;
        string nome, semestre, curso;
        int ano;
        cout << "ID: ";
        cin >> id;
        cin.ignore(); // Limpar o buffer do teclado
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Semestre: ";
        getline(cin, semestre);
        cout << "Ano: ";
        cin >> ano;
        cout << "Curso (DSM/SI/GE): ";
        cin >> curso;
        turma_cafe.adicionar_participante(id, nome, semestre, ano, curso);
        cout << "Participante adicionado com sucesso!" << endl;
    };

    // Função para editar dados dos participantes
    auto editar_dados_participante = [&turma_cafe]() {
        cout << "Editar dados do participante" << endl;
        int id;
        cout << "ID do participante a ser editado: ";
        cin >> id;
        cin.ignore(); // Limpar o buffer do teclado
        turma_cafe.editar_dados_participante(id);
    };

    // Menu principal
    int opcao;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Inserir novo participante" << endl;
        cout << "2. Editar dados do participante" << endl;
        cout << "3. Mostrar participantes" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                system("cls");
                inserir_participantes();
                break;
            case 2:
            system("cls");
                editar_dados_participante();
                break;
            case 3:
            system("cls");
                turma_cafe.mostrar_participantes();
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
