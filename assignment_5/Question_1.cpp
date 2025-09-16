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

void deletehead(Node* head)
{
    Node* temp = head;
    head=head->next;
    printList(head);
    delete temp; 
}
void deletelast(Node* head){

    Node* temp = head;


    while (temp->next->next != nullptr)     
    {
        temp= temp->next;
    }
    Node* temp2 = temp->next;
    temp->next= nullptr;
    delete temp2; 
    printList(head);
}
void insertatend(Node* head, int v)
{
    Node* n1= new Node(v);
    Node* temp =head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;

    }
    temp->next=n1;
}

void insertatindx(Node* head,int v,int idx)

{
    Node* n1= new Node(v);
    Node* temp= head;
    for(int i=1;i<=idx-1;i++)
    {
        temp= temp->next;

    }
    Node* temp2= temp->next;
    temp->next=n1;
    n1->next=temp2;
}
void deleteatnode(Node* head,int idx)
{
    Node* temp=head;
    for(int i=1;i<idx-1;i++)
    {
        temp=temp->next;
    }
    Node*temp2=temp->next->next;
    temp->next=temp2;


}
void search(Node* head, int v)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        if(temp->data==v)
        {
            return;
        }
        temp=temp->next;

    }
}
int main() {
 
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    insertatend(head,90);
    search(head,20);
  
    deleteatnode(head,3);
    printList(head);
    


    
    return 0;
}