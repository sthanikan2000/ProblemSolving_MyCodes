#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void slotMach(int a[],int b[],int s[],int n){
    for (int start=0;start<n-1;start++){
        int a_tem=(a[start]*a[start])+2*b[start]+1;
        a[start+1]=((a_tem%10007)+10007)%10007-5000;
        int b_tem=(b[start]*b[start])+2*a[start]-1;
        b[start+1]=((b_tem%10007)+10007)%10007-5000;
        //c[start+1]=(a[start]+b[start]+c[start])%121-60;
        s[start+1]=a[start+1]+b[start+1]+((s[start])%121+121)%121-60;
        
    }
    
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<endl;
}

long int maxSum(long int a[],int n){
    long int max=a[0];
    long int maxSum1=0;
    for (int i=0;i<n;i++){
        maxSum1+=a[i];
        if( maxSum1<0){
            maxSum1=0;
        }
        else if(max<maxSum1){
            max=maxSum1;
        }
    }
    return max;
}
int main() {
    int n,a0,b0,c0;
    //cin>>n>>a0>>b0>>c0;
    int a[n];
    int b[n];
    //int c[n];
    int s[n];
    a[0]=a0;
    b[0]=b0;
    //c[0]=c0;
    s[0]=a0+b0+c0;
    //slotMach(a,b,s,n);
    //printArray(s,n);
    //cout<<maxSum(s,n);
    //long int Arr[10]={2048,3828,-185,5874,-1823,1717,-3594,3553,-1317,-4052};
    long int Arr[10]={-20,-2,-3,-5,-8,-2,-4,-2,-3,-9};
    cout<<maxSum(Arr,10);
    
    
    return 0;
}
