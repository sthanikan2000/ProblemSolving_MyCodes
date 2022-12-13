#include <iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

        string s;
        cin>>s;

        string t="";
        for (int i=s.length();i>0;i--){
            t+=s[i-1];
        }
        
        if (s==t){
            cout<<(-1)<<endl;
        }
        else{
            int i=1;
            bool isAnyPalindrome=false;
            for(i;i<=s.length();i++){
                string y=s;
                y.erase(i-1,1);
                string z="";
                for (int i=y.length();i>0;i--){
                    z+=y[i-1];
                }
                
                if (y==z){
                    cout<<(i-1)<<endl;
                    isAnyPalindrome=true;
                    break;
                }
            }
            if (not(isAnyPalindrome)){
                cout<<(-1)<<endl;
            }

        }
    }
    return 0;
}

