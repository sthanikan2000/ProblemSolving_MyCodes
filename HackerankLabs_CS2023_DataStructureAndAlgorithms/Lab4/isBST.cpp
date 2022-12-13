#include <iostream>
#include<vector>

using namespace std;

struct Node {
            int data;
            Node* left;
            Node* right;
}

void inorder(Node *root,vector<int> &a){
     if(root){
         inorder(root ->left,a);
         a.push_back(root -> data);
         inorder(root ->right,a);
     }
    return;    
         
}
bool checkBST(Node* root) {
       vector<int> a;
       inorder(root,a);
       bool found = true;
       for(int i = 0 ; i < a.size() - 1; i++ ){
           if(a[i] >= a[i+1]){
               found = false;
               break;
           }               
       }
       return found;
}