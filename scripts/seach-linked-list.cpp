/*
## LISTA ORDENADA ##

1. struct
2. funções
    a. checar se está vazia - ok
    b. inserir - ok
    c. printar - ok
    d. find - ok (indicar posição)
    e. menu - ok
    f. main - ok
    
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty()
{
    if (top) {
        return false;
    }
    else {
        return true;
    }
}

void insert(int n)
{
    Node* aux = NULL;
    Node* prev = NULL;
    Node* new_node = new Node;

    new_node -> data = n;

    // checar se a lista está vazia
    if (isEmpty()) {
        new_node -> next = top;
        top = new_node;
    }
    else {
        aux = top;
        prev = NULL;

        while (aux != NULL && new_node->data > aux->data) {
            prev = aux;
            aux = aux->next;
        }

        if (aux == top) {
            new_node->next = aux;
            top = new_node;
        }
        else {
            new_node->next = aux;
            prev->next = new_node;
        }
    }
}

void find()
{
    Node* new_node = top;
    int x;
    bool done = false;
  int index = 0;

    if (!isEmpty()) {
        cout << "Target element: ";
        cin >> x;

        while (new_node != NULL) {
            if (new_node -> data == x) {
                cout << "Found at index " << index << endl;
                done = true;
                break;
            }
            if(new_node -> data > x)
            {
              break;
            }
            new_node = new_node -> next;
            ++index;
        }

        if (!done) {
            cout << "Not found.\n";
        }
    }
    else {
        cout << "Empty list.\n";
    }
}

void printLinkedList()
{
  // ponteiro que aponta sempre pro nó atual:
  Node *current = top;
  
  if(isEmpty())
    cout << "Empty list.\n";
  
  while(current != NULL)
  {
    cout << current -> data << " ";
    current = current -> next;
  }
  cout << "\n" << endl;
}

int menu()
{
    int x;

    cout << "0. Exit\n"
         << "1. Insert\n"
         << "2. Find\n"
         << "3. Print\n";
    cin >> x;

    return x;
}

int main()
{
    int option;

    do {
        option = menu();
        switch (option)
        {
          case 1:
              int n;
              cout << "Insert data: ";
              cin >> n;
              insert(n); break;
          case 2:
              find(); break;
          case 3:
              printLinkedList(); break;
        }
    } while (option != 0);

    return 0;
}
