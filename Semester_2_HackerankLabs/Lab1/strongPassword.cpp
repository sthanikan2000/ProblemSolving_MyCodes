#include<iostream>
#include<string>
using namespace std;

int main(){
    int minNum=4,n;
    bool anyNum=false,anyLcase=false,anyUcase=false,anyCha=false;
    string num="0123456789";
    string lcase="abcdefghijklmnopqrstuvwxyz";
    string ucase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cha="!@#$%^&*()-+";
    string s;
    
    cin>>n;
    cin>>s;
    
    for (int i=0; i<n;i++){
        char ch=s[i];
        if ((num.find(ch) != string::npos)and(not(anyNum))){
            anyNum=true;
            minNum-=1;   
        }
        else if ((lcase.find(ch) != string::npos)and(not(anyLcase))){
            anyLcase=true;
            minNum-=1;   
        }            
        else if ((ucase.find(ch) != string::npos)and(not(anyUcase))){
            anyUcase=true;
            minNum-=1;   
        }
        else if ((cha.find(ch) != string::npos)and(not(anyCha))){
            anyCha=true;
            minNum-=1;   
        }            
    }

    if ((minNum+n)<6){
        cout<<(6-n);
    }
    else{
        cout<<minNum;
    }             
         
    return 0;
}