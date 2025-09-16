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


void mid(Node* head)
{
    Node* s= head; 
    Node* f=head; 
    while (f->next!=nullptr && f->next->next!=nullptr)
    {
        s= s->next;
        f=f->next->next;

    }
    cout<<s->data;


}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next=new Node(50);

    mid(head);
    
    return 0;
}