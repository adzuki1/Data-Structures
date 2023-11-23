#include <iostream>
using namespace std;

// Definição da estrutura do nó da lista
struct Node {
    int data;
    Node* next;
};

// Classe que representa a lista encadeada
class LinkedList {
private:
    Node* head; // Ponteiro para o primeiro nó da lista

public:
    LinkedList() {
        head = nullptr; // Inicializa a lista como vazia
    }

    // Função para inserir um elemento no início da lista (como pilha)
    void push(int value) {
        Node* newNode = new Node; // Cria um novo nó
        newNode->data = value; // Define o valor do novo nó
        newNode->next = head; // O próximo do novo nó aponta para o antigo primeiro nó
        head = newNode; // Atualiza o ponteiro de início para o novo nó
    }

    // Função para remover o elemento do início da lista (como pilha)
    void pop() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head; // Armazena o ponteiro do primeiro nó temporariamente
        head = head->next; // Atualiza o ponteiro de início para o próximo nó
        delete temp; // Libera a memória do nó removido
    }

    // Função para inserir um elemento no final da lista (como fila)
    void enqueue(int value) {
        Node* newNode = new Node(); // Cria um novo nó
        newNode->data = value; // Define o valor do novo nó
        newNode->next = nullptr; // O próximo do novo nó é nulo, pois será o último nó

        if (head == nullptr) {
            head = newNode; // Se a lista estiver vazia, o novo nó se torna o primeiro nó
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Encontra o último nó da lista
        }
        current->next = newNode; // Atualiza o próximo do último nó para o novo nó
    }

    // Função para remover o elemento do início da lista (como fila)
    void dequeue() {
        if (head == nullptr) {
            cout << "A lista está vazia!" << endl;
            return;
        }
        Node* temp = head; // Armazena o ponteiro do primeiro nó temporariamente
        head = head->next; // Atualiza o ponteiro de início para o próximo nó
        delete temp; // Libera a memória do nó removido
    }

    // Função para imprimir os elementos da lista
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

