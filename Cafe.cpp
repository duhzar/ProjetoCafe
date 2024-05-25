#include <iostream>
#include <fstream>
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
    Aluno* next;
};

// Ponteiro para o primeiro elemento da lista
Aluno* turmaDoCafe = nullptr;

// Função para novos participantes
void novoAluno(int id, string nome, int semestre, int anoIngresso, string curso) {
    Aluno* novoAluno = new Aluno {id, nome, semestre, anoIngresso, curso,nullptr};
  if(turmaDoCafe == nullptr){
    turmaDoCafe = novoAluno;
  }else{
      Aluno* temp = turmaDoCafe;
      while (temp->next !=nullptr){
        temp = temp-> next;
      }
      temp -> next = novoAluno;
  }
}

// Função para achar Participantes
Aluno* encontrarAluno(int id){
    Aluno* temp = turmaDoCafe;
    while (temp != nullptr){
        if(temp->id == id){
            return temp;
        }
        temp =temp->next;
    }
    return nullptr;
}

// Função para salvar os dados dos participantes em um arquivo
void salvarAluno() {
    ofstream arquivo("Lista.txt");
    if (arquivo.is_open()) {
       Aluno* temp = turmaDoCafe;
       while (temp != nullptr){
        arquivo <<temp->id<<" "
                <<temp->nome<<" "
                <<temp->semestre<<" "
                <<temp->anoIngresso<<" "
                <<temp->curso<<"\n";
        temp = temp->next;
       }
        arquivo.close();
        cout << "Dados salvos com sucesso.\n";
    } else {
        cout << "Nao foi possovel abrir o arquivo Lista.txt\n";
    }
}

// Fun��o para ler arquivo .txt
void lerArquivo() {
    ifstream arquivo;
    arquivo.open("Lista.txt", ios::in); // abre o arquivo para leitura
     if (! arquivo){ cout << "Arquivo Lista.txt nao pode ser aberto" << endl;
}else {
    int id, semestre, anoIngresso;
    string nome, curso;
        while (arquivo >> id >> nome >> semestre >> anoIngresso >> curso) {
            novoAluno(id, nome, semestre, anoIngresso, curso);
        }
}
}

// Fun��o para editar um participante
void editarParticipante(int id) {
    Aluno* aluno = encontrarAluno(id);
    if(aluno != nullptr) {
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
        aluno->nome = nome;
        aluno->semestre = semestre;
        aluno->anoIngresso = anoIngresso;
        aluno->curso = curso;
    } else {
        cout << "Participante nao encontrado.\n";
    }
}
//Função para listar participantes
void listarParticipantes(){
    Aluno* temp = turmaDoCafe;
    while (temp != nullptr){
        cout << "ID: "<< temp->id << ",Nome: "<< temp->nome
             << ", Semestre: "<< temp->semestre
             << ", Ano de Ingresso: "<< temp->anoIngresso
             << ", Curso: "<<temp->curso <<"\n"<< endl;
        temp = temp->next;
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
           listarParticipantes();
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
            system("cls");
            salvarAluno();
        }
    }

    return 0;
}
