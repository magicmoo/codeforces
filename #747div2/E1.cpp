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
const ll mod = 1e9+7;
int main(){
    IOS;
    ll k;
    cin>>k;
    if(k==1){
        cout<<"6\n";
        return 0;
    }
    ll ans = 1;
    ll last = 4;
    Rep(i,2,k){
        ans = 6*last%mod*last%mod;
        last = 4*last%mod*last%mod;
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}
