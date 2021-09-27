#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;

int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        if(n%2 == 0){
            for(int i=1;i<=n;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"3 1 2 ";
            for(int i=4;i<=n;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}