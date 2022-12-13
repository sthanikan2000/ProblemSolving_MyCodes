#include <bits/stdc++.h>
using namespace std;

int main() {
    int m,n;
    string word;
    unordered_map<string, int> wordmap;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>word;
        wordmap[word]++;
    }
    bool wordNotFound=false;
    for(int i=0;i<n;i++){
        cin>>word;
        if (wordmap[word]==0){
            wordNotFound=true;
        }
        else{
            wordmap[word]--;
        }
    }
    if (wordNotFound){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }

    
    return 0;
}
