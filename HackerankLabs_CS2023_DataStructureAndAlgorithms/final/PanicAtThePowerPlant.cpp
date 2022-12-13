#include <bits/stdc++.h>
using namespace std;

long long int maxPow(){
    long long int n;
    cin >> n;
    
    vector<vector<long long int>> machine(n, vector<long long int>(1));
    
    for (int i = 0; i < n; i++){
        long long int tri,tru;
        cin >> tri >> tru;
        long long int  ratio = tri-tru;
        machine[i].push_back(ratio);
        machine[i].push_back(tri);
        machine[i].push_back(tru);
    }
    
    
    sort(machine.begin(), machine.end());
    long long int powMax = 0;
    
    for (int i = 0; i < n; i++){
        powMax += i*machine[i][2] + (n - 1 - i)*machine[i][3];
    }
    return powMax;
}
int main() {    
    long long int res;
    res=maxPow();
    cout<< res;
    return 0;
}
