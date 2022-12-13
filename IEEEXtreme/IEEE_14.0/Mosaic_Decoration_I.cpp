#include <iostream>

using namespace std;

int main() {
    int N,CB,CP;
    cin >> N>> CB>>CP;
    int B=0,P=0;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        B+=x;
        P+=y;
    }
    cout<<(CB*(((B-1)/10)+1)+CP*(((P-1)/10)+1));
    return 0;
}
