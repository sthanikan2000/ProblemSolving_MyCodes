#include<iostream>
using namespace std;

int main(){
    long int sum=0,maximum,minimum;
    for(int i=1;i<=5;i++){
        int x;
        cin>>x;
        sum+=x;
        if(i==1){
            maximum=x;
            minimum=x;
        }
        else{
            if(x>maximum){
                maximum=x;
            }
            if(x<minimum){
                minimum=x;
            }
        }
    }
    cout<<sum-maximum<<' '<<sum-minimum;
    return 0;
}