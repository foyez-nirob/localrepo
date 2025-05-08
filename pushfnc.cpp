#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* temp = new Node(val);
        if(head == NULL){
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout <<"no value available"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL){
            cout<<"no value available"<<endl;
            return ;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail ;
        tail = temp;
        
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data <<" ";
            temp = (*temp).next;
        }
        cout << endl;
    }

};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(10);
    ll.push_back(80);
    ll.push_back(20);
    
    ll.print();
}