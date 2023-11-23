#include <iostream>
using namespace std;

// definindo a estrutra nó
struct Node
{
    int data; // var tipo int que recebe um dado;
    Node* next; // var tipo pointer que recebe o endereço do próximo nó
};
Node* top = NULL;

/*
void printLinkedList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
*/

void push(int num)
// insere um novo nó na lista encadeada
{
    Node* new_node;
    new_node = new Node;

    new_node->data = num;
    new_node->next = top;

    top = new_node;

}

void pop()
// remove um elemento do topo da pilha
{
    Node* temp = top;

    if(top != NULL)
    {
        top = top->next;
        delete temp;
        cout << "\nItem removed from stack" << endl;
    }
    else
        cout << "\nNULL list" << endl;
}

int main()
{
    /* criando nós
    Node* head = NULL; 
    Node* two = NULL;
    Node* three = NULL;

    head = new Node;
    two = new Node;
    three = new Node;

    // define o dado para o primeiro nó e aponta para o próximo
    head->data = 1;
    head->next = two;

    two->data = 2;
    two->next = three;

    three->data = 3;
    three->next = NULL;*/

    //printLinkedList(head);
    //cout << head->data << endl;
    int num;
    cout << "insert a number into List: ";
    cin >> num;

    int op;

    do
    {
        cout << "inform operation: 1 to insert, 2 to remove, 0 to exit" 
             << endl;
        cin >> op;
        switch (op)
        {
        case 1: push(num); break;
        case 2: pop(); break;
        }
    } while(op != 0);
    
    return 0;
}

