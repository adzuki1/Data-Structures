/*
## LISTA DUPLAMENTE ENCADEADA SIMPLES:

Um nó de uma lista duplamente encadeada possui um campo para dado e dois
ponteiros, que apontam para o nó anterior e o nó seguinte. O primeiro e 
o último elemento não possuem ligação (não compartilham endereço)

Funções:

*/
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* top = NULL;
struct Node* bot = NULL;

void insert(int n)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node -> data = n;
    new_node -> next = top;
    new_node -> prev = NULL;

    if(top != NULL)
    {
        top -> prev = new_node;
    }

    if()
}

void delete()
{
    // checar se a lista está vazia
    if(!top){
        printf("list is empty.");
    }
}
