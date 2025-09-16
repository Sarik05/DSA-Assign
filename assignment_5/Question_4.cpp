#include <iostream>
#include <string>
                  
using namespace std;
               

class Node {
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next= nullptr;
    }
};

void printList(Node* head) {

   Node* temp =head; 
    while (temp != nullptr) {

        
        cout << temp->data<<" ";
       
        temp = temp->next;
    }
}

void reverse(Node* head)
{
    Node* curr= head;
    Node* prev = nullptr;
    while(curr!= nullptr){
        Node* curr1 = curr->next;
        curr->next= prev;
        prev= curr;
        curr= curr1;

    }
    head= prev;
    printList(head);

}




int main(){

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    reverse(head);
    
    return 0;
}