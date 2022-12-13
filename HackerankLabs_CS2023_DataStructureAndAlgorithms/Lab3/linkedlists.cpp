#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while ((n != NULL) ) {
        cout << n->data << " ";
        n = n->next;
    }
}

void insertNode(Node** head_ref, int new_data)
{
    Node* temp = new Node();
    temp->data=new_data;
    temp->next=*head_ref;
    *head_ref=temp;
}

void deleteNode(Node** head_ref, int key)
{
    if (*head_ref==NULL){
        cout<<key<<" is not found\n";
        return;
    }
    Node* head=*head_ref;
    if(head->data==key){
        *head_ref=head->next;
        return;
    }
    Node* current=*head_ref;
    while(current->next!=NULL){
        if (current->next->data==key) {
                current->next=current->next->next;
                return;
            }
            current=current->next;
    }
    cout<<key<<" is not found\n";
}

void searchNode(Node** head_ref, int key)
{
    
    Node* current=*head_ref;
        while(current!=NULL) {
            if(current->data==key) {
                cout<<key<<" is found\n";
                return;
            }
            current=current->next;
        }
    cout<<key<<" is not found\n";
}


int main()
{   
    int a, b;
    Node* head = NULL;
    
    while(true){
        
        cin >> a;
        
        if(a == -1){
            printList(head);
            break;
        }
        
        cin >> b;
        
        switch (a) {
          case 1:
            insertNode(&head, b);
            break;
          case 2:
            deleteNode(&head, b);
            break;
          case 3:
            searchNode(&head, b);
            break;
        }
        
    }

    return 0;
}