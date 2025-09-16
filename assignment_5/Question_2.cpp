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
 void countAndDelete(Node*& head, int key) {
    int count = 0;
    Node* current = head;
    
  
    while (current != nullptr) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    
    cout << "Count of " << key << ": " << count << endl;
    

    if (count == 0) {
        return;
    }


    Node* prev = nullptr;
    current = head;
    
    while (current != nullptr) {
        if (current->data == key) {
          
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head; 
            } else {
                
                prev->next = current->next;
                delete current;
                current = prev->next; 
            }
        } else {
            
            prev = current;
            current = current->next;
        }
    }
}

void printList(Node* head) {

   Node* temp =head; 
    while (temp != nullptr) {

        
        cout << temp->data<<" ";
       
        temp = temp->next;
    }
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);

    int key = 1;

    countAndDelete(head, key);

     return 0;
}