#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
    
        //constructor : 
        Node(int d){
            this->data = d;
            this->prev = NULL;
            this->next = NULL;
        }
};

// Linked List Traversal 
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Gives Length of Linked List
void getLength(Node* &head){
    int length = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    cout<<length<<" ";
}

// Insert at Head 
void insetAtHead(Node* &tail,Node* &head, int d){
    Node* temp = new Node(d);
    if(head==NULL){
        head = temp;
        tail = temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
}

// Insert at Tail 
void insetAtTail(Node* &tail,Node* &head, int d){
    Node* temp = new Node(d);
    if(head==NULL){
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Insert at Position
void insetAtPosition(Node* &head, Node* &tail, int pos, int d){
    if(pos==1){
        insetAtHead(tail,head,d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    int count = 1;
    Node* temp = head;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insetAtTail(tail,head,d);
        return;
    }

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insetAtHead(tail,head,11);
    insetAtHead(tail,head,12);
    insetAtHead(tail,head,13);


    insetAtTail(tail,head,9);    
    insetAtTail(tail,head,8);
    insetAtTail(tail,head,7);

    insetAtPosition(head,tail,2,100);
    insetAtPosition(head,tail,5,107);
    insetAtPosition(head,tail,8,99);
    insetAtPosition(head,tail,10,69);

    print(head);
    getLength(head);
return 0;
}