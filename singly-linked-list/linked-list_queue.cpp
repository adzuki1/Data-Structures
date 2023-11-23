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

void enqueue(int num)
// insere um novo nó na lista encadeada
{
    Node *temp;
    Node *new_node = new Node;
    int num;

    

    new_node->data = num;
    new_node->next = top;

    top = new_node;

}

void pop()
// remove um nó
{
    Node* new_node = top;

    if(top != NULL)
    {
        top = top->next;
        delete(new_node);
        cout << "\nItem removed from queue" << endl;
    }
    else
        cout << "\nNULL list" << endl;
}

int main()
{
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
        case 1: enqueue(num); break;
        case 2: pop(); break;
        }
    } while(op != 0);
    
    return 0;
}

