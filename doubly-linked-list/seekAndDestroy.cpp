#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
};
// definindo novo tipo 'ponteiro para nó':
typedef Node *NodePtr;

bool isEmpty(NodePtr top){
  return (top == NULL);
}

void push(NodePtr *i, int n){
  NodePtr node = new Node;
  node -> data = n;
  node -> prev = NULL;

  if(isEmpty(*i))
    node -> next = NULL;
  else
  {
    node -> next = *i;
    (*i) -> prev = node;
  }
  *i = node;
}

void pop(NodePtr *i){
// remove o último elemento adicionado (pilha)
  NodePtr node = *i;

  if(!isEmpty(*i))
  {
    if(node -> next == NULL)
      *i = NULL;
    else
    {
      *i = node -> next;
      (*i) -> prev = NULL;
    }
    delete(node);

    cout << "\nRemovido.\n";
  }
  else cout << "\n\nNULL\n";
}

void view(NodePtr node){
  if(!isEmpty(node))
  {
    cout << "\nElementos: ";

    while(node != NULL)
    {
      cout << node -> data << " ";
      node = node -> next;
    }
    cout << "\n\n";
  }
  else cout << "\nNULL\n";
}

void seekAndDestroy(NodePtr& node, int n){
    NodePtr temp = node;

    // procurar o elemento na lista
    while(temp != NULL && temp -> data != n){
        temp = temp -> next;
    }
    // se o elemento for encontrado
    if(temp != NULL){
        // pular os nós
        if(temp -> next != NULL)
            temp -> prev -> next = temp -> next;
        else
            // se o elem. é o primeiro da lista
            node = temp -> next;
        if(temp -> next != NULL)
            temp -> next -> prev = temp -> prev;

        // deletar o nó
        delete temp;
    }
    else
        // elem. não encontrado
        cout << "Elemento " << n << " não encontrado";
}

int menu()
{
    int x;

    cout << "0. Exit\n"
         << "1. push\n"
         << "2. pop\n"
         << "3. View\n"
         << "4. Find and remove\n";
    cin >> x;

    return x;
}

int main()
{
  NodePtr top = NULL;
  int option;
  int n;

  do {
    option = menu();
    
    switch(option) {
      case 1: 
        cout << "Data: ";
        cin >> n;
        push(&top, n); break;
      case 2: pop(&top); break;
      case 3: view(top); break;
      case 4:
        cout << "Data: ";
        cin >> n;
        seekAndDestroy(top, n); break;
    }
  }
  while(option != 0);

  return 0;
}
