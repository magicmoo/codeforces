#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;

int main(){
    IOS;
    ll x,y;
    CAS{
        cin>>x>>y;
        if(y < x){
            cout<<(x+y)<<"\n";
        }else if(y==x){
            cout<<x<<"\n";
        }else{
            ll dis = max(y/x-1,1LL);
            cout<<(y+dis*x)/2<<"\n";
        }
    }
    return 0;
}
