#include <iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

        string s;
        cin>>s;
//##############################################################################################################
        int n=s.length();
        if (n%2==1){
            string y=s.substr(0,n/2);
            string z=s.substr((n/2)+1,n/2);
            cout<<y<<endl<<z<<endl;
            char extra=s[n/2];
            if (y==string(z.rbegin(),z.rend())){
                cout<<-1<<endl;
            }
            for (int i=0;i<=n/2;i++){
                string y1=y.substr(0,i)+y.substr(i+1,(n/2)-i-1)+extra;
                if(y1==string(z.rbegin(),z.rend())){
                    cout<<i<<endl;
                }
            }
            for (int i=0;i<=n/2;i++){
                string z1=extra+z.substr(0,i)+z.substr(i+1,(n/2)-i-1);
                if(z1==string(y.rbegin(),y.rend())){
                    cout<<i+(n/2)+1<<endl;
                }
            }
        }
        else{
            string p=s.substr(0,n/2);
            string q=s.substr((n/2),n/2);
            //char extra=s[n/2];
            if (p==string(q.rbegin(),q.rend())){
                cout<<-1<<endl;
            }
            for (int i=0;i<=n/2;i++){
                string y1=p.substr(0,i)+p.substr(i+1,(n/2)-i-1);
                string t=q.substr(1,n/2-1);
                if(y1==string(t.rbegin(),t.rend())){
                    cout<<i<<endl;
                }
            }
            for (int i=0;i<=n/2;i++){
                string z1=q.substr(0,i)+q.substr(i+1,(n/2)-i-1);
                string u=p.substr(0,n/2-1);
                if(z1==string(u.rbegin(),u.rend())){
                    cout<<i+(n/2)<<endl;
                }
            }
        }


//##############################################################################################################
    }
    return 0;
}

