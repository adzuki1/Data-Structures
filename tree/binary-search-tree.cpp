#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *lft, *rgt;
}; 

typedef Node* NodePtr;

bool isEmpty(NodePtr top){
    return (top == NULL);
}

 void insert(NodePtr *i, int n){
    if(isEmpty(*i)){
        *i = new Node;
        (*i) -> data = n;
        (*i) -> lft = NULL;
        (*i) -> rgt = NULL;
    }
    else{
        if(n < (*i) -> data)
            insert(&((*i) -> lft), n);
        else
            insert(&((*i) -> rgt), n);
    }
}

bool search(NodePtr i, int n){
    bool is_found = false;

    if(isEmpty(i))
        cout << "Tree is empty.";
    else{
        if(n == i -> data){
            cout << "Found" << n;
            is_found = true;
        }
        else{
            if(n < i -> data)
                search(i -> lft, n);
            else
                search(i -> rgt, n);
        }
        return is_found;
    }
}

int main(){

    return 0;
}