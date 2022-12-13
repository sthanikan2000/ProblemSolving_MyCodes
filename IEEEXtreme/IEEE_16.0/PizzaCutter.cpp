#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int N;
        cin>>N;
        if(N==0){
            cout<<1<<"\n";
            continue;
        }
        vector<int> offsets;
        for(int j=0;j<N;j++){
            int temp;
            cin>>temp;
            if(temp>=360){
                while(temp>=360){
                    temp-=360;
                }
            }
            if(temp<0){
                while(temp<0){
                    temp+=360;
                }
            }
            if(temp>=180){
                temp-=180;
            }
            if (find(offsets.begin(), offsets.end(), temp) == offsets.end()) {
                offsets.push_back(temp);
            }
        }
       cout<<offsets.size() * 2<<endl;
    }
    return 0;
}
