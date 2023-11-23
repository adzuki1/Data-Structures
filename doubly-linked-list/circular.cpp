#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};
typedef Node* NodePtr;

bool isEmpty(NodePtr top){
    return(top == nullptr);
}

void push(NodePtr& i, int n){
    NodePtr node = new Node;
    node -> data = n;

    if(isEmpty(i)){
        node -> next = node;
        node -> prev = node;
    }
    else{
        node -> next = i;
        node -> prev = i -> prev;
        i -> prev -> next = node;
        i -> prev = node;
    }
    i = node;
}

void pop(NodePtr& i){
    if(!isEmpty(i)){
        if(i->next == i){
            delete i;
            i = nullptr;
        }
        else{
            NodePtr temp = i;
            i->prev->next = i->next;
            i->next->prev = i->prev;
            i = i->next;
            delete temp;
        }
    }
    else{
        cout << "\n\nNULL\n";
    }
}

void view(NodePtr node){
    if(!isEmpty(node)){
        NodePtr temp = node;

        do{
            cout << temp -> data << " ";
            temp = temp -> next;
        } while(temp != node);

        cout << "\n\n";
    }
    else
        cout << "\nNULL\n";
}

int menu() {
    int x;

    cout << "0. Exit\n"
         << "1. Push\n"
         << "2. Pop\n"
         << "3. View\n";
    cin >> x;

    return x;
}

int main() {
    NodePtr top = nullptr;
    int option;
    int n;

    do {
        option = menu();

        switch(option){
            case 1:
                cout << "Data: ";
                cin >> n;
                push(top, n);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                view(top);
                break;
        }
    } while(option != 0);

    return 0;
}