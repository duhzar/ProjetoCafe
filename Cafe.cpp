#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<locale.h>
#include<stdlib.h>

using namespace std;

// Definindo a estrutura
struct Participante {
    int id;
    string nome;
    int semestre;
    int anoIngresso;
    string curso;
};

// Vetor para armazenar os participantes
vector<Participante> turmaDoCafe;

// Função para novos participantes
void novoParticipante(int id, string nome, int semestre, int anoIngresso, string curso) {
    Participante novoParticipante = {id, nome, semestre, anoIngresso, curso};
    turmaDoCafe.push_back(novoParticipante);
}
//Função para achar Participantes
int encontrarParticipante(int id) {
    for (int i = 0; i < turmaDoCafe.size(); i++) {
        if (turmaDoCafe[i].id == id) {
            return i;
        }
    }
    return -1;
}
// Função para salvar os dados dos participantes em um arquivo
void salvarParticipantes() {
    ofstream arquivo("participantes.txt");
    if (arquivo.is_open()) {
        for (auto& participante : turmaDoCafe) {
            arquivo << participante.id << " "
                    << participante.nome << " "
                    << participante.semestre << " "
                    << participante.anoIngresso << " "
                    << participante.curso << "\n";
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo participantes.txt\n";
    }
}
//Função para ler arquivo .txt
void lerArquivo() {
    ifstream arquivo("participantes.txt");
    if (arquivo.is_open()) {
        int id, semestre, anoIngresso;
        string nome, curso;
        while (arquivo >> id >> nome >> semestre >> anoIngresso >> curso) {
            novoParticipante(id, nome, semestre, anoIngresso, curso);
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo participantes.txt\n";
    }
}
// Função para editar um participante
void editarParticipante(int id) {
    int index = encontrarParticipante(id);
    if (index != -1) {
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
        turmaDoCafe[index].nome = nome;
        turmaDoCafe[index].semestre = semestre;
        turmaDoCafe[index].anoIngresso = anoIngresso;
        turmaDoCafe[index].curso = curso;
    } else {
        cout << "Participante não encontrado.\n";
    }
}

int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");
    // Menu principal
    int opcao = 0;
    while(opcao != 5) {
        cout << "1. Inserir novo participante\n";
        cout << "2. Listar participantes\n";
        cout << "3. Editar participante\n";
        cout << "4. Ler participantes de arquivo\n";
        cout << "5. Sair\n";
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
            novoParticipante(id, nome, semestre, anoIngresso, curso);
            salvarParticipantes();
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
            lerArquivo();
        }
    }

    return 0;
}
