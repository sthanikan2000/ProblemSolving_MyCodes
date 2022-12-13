#include <iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;

        if (s==string(s.rbegin(),s.rend())){
            cout<<(-1)<<endl;
        }
        else{
            
            bool isAnyPalindrome=false;
            for(int i=1;i<=s.length();i++){
                string y=s;
                y.erase(i-1,1);
                
                if (y==string(y.rbegin(),y.rend())){
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

