#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <locale.h>
#include <stdlib.h>

using namespace std;

// Definindo a estrutura
struct Aluno {
    int id;
    string nome;
    int semestre;
    int anoIngresso;
    string curso;
};

// Lista para armazenar os participantes
list<Aluno> turmaDoCafe;

// Fun��o para novos participantes
void novoAluno(int id, string nome, int semestre, int anoIngresso, string curso) {
    Aluno novoAluno = {id, nome, semestre, anoIngresso, curso};
    turmaDoCafe.push_back(novoAluno);
}

// Fun��o para achar Participantes
list<Aluno>::iterator encontrarAluno(int id) {
    for (auto it = turmaDoCafe.begin(); it != turmaDoCafe.end(); ++it) {
        if (it->id == id) {
            return it;
        }
    }
    return turmaDoCafe.end();
}

// Fun��o para salvar os dados dos participantes em um arquivo
void salvarAluno() {
    ofstream arquivo("Lista.txt");
    if (arquivo.is_open()) {
        for (auto& participante : turmaDoCafe) {
            arquivo << participante.id << " "
                    << participante.nome << " "
                    << participante.semestre << " "
                    << participante.anoIngresso << " "
                    << participante.curso << "\n";
        }
        arquivo.close();
        cout << "Dados salvos com sucesso.\n";
    } else {
        cout << "N�o foi poss�vel abrir o arquivo Lista.txt\n";
    }
}

// Fun��o para ler arquivo .txt
void lerArquivo() {
    ifstream arquivo("Lista.txt");
    if (arquivo.is_open()) {
        int id, semestre, anoIngresso;
        string nome, curso;
        while (arquivo >> id >> nome >> semestre >> anoIngresso >> curso) {
            novoAluno(id, nome, semestre, anoIngresso, curso);
        }
        arquivo.close();
        cout << "Dados carregados com sucesso.\n";
    } else {
        cout << "N�o foi poss�vel abrir o arquivo Lista.txt\n";
    }
}

// Fun��o para editar um participante
void editarParticipante(int id) {
    auto it = encontrarAluno(id);
    if (it != turmaDoCafe.end()) {
        string nome, curso;
        int semestre, anoIngresso;
        cout << "Digite o novo nome: ";
        cin >> nome;
        cout << "Digite o novo semestre: ";
        cin >> semestre;
        cout << "Digite o novo ano de ingresso: ";
        cin >> anoIngresso;
        cout << "Digite o novo curso (DSM, SI, GE): ";
        cin >> curso;
        it->nome = nome;
        it->semestre = semestre;
        it->anoIngresso = anoIngresso;
        it->curso = curso;
    } else {
        cout << "Participante n�o encontrado.\n";
    }
}

int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");
    // Menu principal
    int opcao = 0;
    while(opcao != 6) {
        cout << "1. Inserir novo participante\n";
        cout << "2. Listar participantes\n";
        cout << "3. Editar participante\n";
        cout << "4. Ler participantes de arquivo\n";
        cout << "5. Salvar todos os participantes\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            system("cls");
            int id, semestre, anoIngresso;
            string nome, curso;
            cout << "Digite o ID: ";
            cin >> id;
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite o semestre: ";
            cin >> semestre;
            cout << "Digite o ano de ingresso: ";
            cin >> anoIngresso;
            cout << "Digite o curso (DSM, SI, GE): ";
            cin >> curso;
            novoAluno(id, nome, semestre, anoIngresso, curso);
        } else if(opcao == 2) {
            system("cls");
            for(auto& participante : turmaDoCafe) {
                cout << "ID: " << participante.id << ", Nome: " << participante.nome << ", Semestre: " << participante.semestre << ", Ano de Ingresso: " << participante.anoIngresso << ", Curso: " << participante.curso << "\n"<< endl;
            }
        } else if(opcao == 3){
            system("cls");
            int id;
            cout << "Insira o ID do participante para editar:";
            cin >>id;
            editarParticipante(id);
        } else if (opcao == 4){
            system("cls");
            lerArquivo();
        } else if (opcao == 5){
            salvarAluno();
        }
    }

    return 0;
}
