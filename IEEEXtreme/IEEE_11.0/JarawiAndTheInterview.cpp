#include <iostream>
#include<string>
using namespace std;

int main() {
    string s;
    int q;
    cin>>s>>q;
    for(int i=0;i<q;i++){
        string p;
        cin>>p;
        int x=p.size()-1;
        int j=s.size()-1;
        while(j>-1){
            if (x==-1) break;
            if (s[j]==p[x]) x--;
            if (x==-1) break;
            j--;
        }
        cout<<(p.size()-1-x)<<endl;
    }
    
    return 0;
}
