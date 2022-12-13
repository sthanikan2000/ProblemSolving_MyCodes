#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void appendNode(Node** head_ref,Node** tail_ref, int new_data)
{
    Node* temp = new Node();
    temp->data=new_data;
    if (*tail_ref==NULL){
        *tail_ref=temp;
        *head_ref=*tail_ref;
        return;
    }
    Node* tail=*tail_ref;
    tail->next=temp;
    tail=temp;
}
int poisonousPlants(Node** head_ref) {
    int days=0;
    Node* current=*head_ref;
    if ((current==NULL)or(current->next==NULL)){
            return days;
        }
    
    bool decendingOrder=false;
    while(not(decendingOrder)){
        decendingOrder=true;
        Node* currentNext=current->next;
        while (currentNext!=NULL){
            if((current->data)<(currentNext->data)){
                decendingOrder=false;
                while((currentNext->next)!=NULL){
                    if((currentNext->data)>=(currentNext->next->data)){
                        break;   
                    }
                    currentNext=currentNext->next;
                }
                current->next=currentNext->next;
            }
            current=currentNext;
            currentNext=current->next;
        }
        
         
    }

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
    int n,i;
    Node* head = NULL;
    Node* tail = NULL;
    cin>>n;
    
    for(int x=0;x<n;x++){
        cin >> i;
        appendNode(&head,&tail,i);  
    }

    return 0;
}