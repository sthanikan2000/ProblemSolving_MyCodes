#include <bits/stdc++.h>

using namespace std;


int stepPerms(int n) {
    int arr[3]={1,2,4};
    if (n==1){
        return (arr[0]);
    }
    if (n==2){
        return (arr[1]);
    }
    if (n==3){
        return (arr[2]);
    }
    //return ((stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3))%10000007);
    int i=1;
    while (i<n-2){
        int sum=arr[0]+arr[1]+arr[2];
        arr[0]=arr[1];
        arr[1]=arr[2];
        arr[2]=sum;
        i++;
    }
    return(arr[2]%10000000007);



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