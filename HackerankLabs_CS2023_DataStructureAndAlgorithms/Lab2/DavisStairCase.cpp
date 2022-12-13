#include <bits/stdc++.h>

using namespace std;


int stepPerms(int n) {
    
    if (n==1){
        return 1;
    }
    if (n==2){
        return 2;
    }
    if (n==3){
        return 4;
    }
    return (stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3));
    



}

int main()
{
    int s;
  	cin >> s;
  	for (int i = 0; i < s; i++) {
    	int n;
      	cin >> n;
      	cout << stepPerms(n) << endl;
    }
    return 0;
}