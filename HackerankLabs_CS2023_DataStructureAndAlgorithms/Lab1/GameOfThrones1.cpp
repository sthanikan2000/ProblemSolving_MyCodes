#include <iostream>
#include<string>
using namespace std;


int main() {
    string s;
    string excessCh="";
    cin>>s;
    
    while(s.length()>1){
        char ch=s[0];
        s.erase(0,1);
        
        if (s.find(ch) != string::npos){
            s.erase(s.find(ch),1);
        }
        else if(excessCh.length()==0){
            excessCh+=(ch);
        }
        else{
            break;
        }   
    }
    if((excessCh.length()==0)and(s.length()==1)){
        cout<<"YES";
    }
    else if((excessCh.length()==1)and(s.length()==0)){
        cout<<"YES";
    }
    else if((excessCh.length()==0)and(s.length()==0)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
/*
############the last segment canbe replase as follows to reduce exicution time####
if(((excessCh.length()==0)and(s.length()==1))or((excessCh.length()==1)and(s.length()==0))or((excessCh.length()==0)and(s.length()==0))){
        cout<<"YES";
    }


*/