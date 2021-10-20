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
    ll n,k;
    CAS {
        cin>>n>>k;
        ll tmp = 1;
        ll ans = 0;
        while(k){
            if(k%2) ans += tmp;
            k /= 2;
            tmp *= n; 
            tmp %= mod;
            ans %= mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
