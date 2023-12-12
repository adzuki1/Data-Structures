#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
};
// Declaring new type "pointer to Node":
typedef Node *NodePtr;

bool isEmpty(NodePtr top);
void push(NodePtr *i, int n);
void pop(NodePtr *i);
void view(NodePtr node);
void seekAndDestroy(NodePtr &node, int n);
int menu();

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



bool isEmpty(NodePtr top){
  // Checks if a pointer to node contains adress
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

void seekAndDestroy(NodePtr &node, int n){
  // Search an element and remove it
  NodePtr temp = node;

  // search through linked list
  while(temp != NULL && temp -> data != n){
      temp = temp -> next;
  }
  // if it finds element
  if(temp != NULL){
      if(temp -> next != NULL)
          temp -> prev -> next = temp -> next;
      // if element is first in list
      else
          node = temp -> next;
      if(temp -> next != NULL)
          temp -> next -> prev = temp -> prev;

      // delete node
      delete temp;
  }
  else
      // if element not found
      cout << "Element " << n << " not found.";
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
