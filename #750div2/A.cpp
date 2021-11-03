#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;

int main(){
    IOS;
    int a,b,c;
    CAS {
        cin>>a>>b>>c;
        if(c%2==0){
            if(b%2==0){
                if(a%2==0) cout<<"0\n";
                else cout<<"1\n";
            }else{
                if(a%2==0) cout<<"0\n";
                else cout<<"1\n";
            }
        }else{
            if(b%2==0){
                if(a%2==0) cout<<"1\n";
                else cout<<"0\n";
            }else{
                if(a%2==0) cout<<"1\n";
                else cout<<"0\n";
            }
        }
    }
    return 0;
}
