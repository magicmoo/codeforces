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
const ll maxn = 100;
ll a[maxn];
ll quick_pow(ll a,ll b){
    ll ans = 1;
    ll base = a;
    while(b){
        if(b & 1) ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        ll cnt0=0,cnt1=0;
        Rep(i,1,n){
            if(a[i]==0) cnt0++;
            if(a[i]==1) cnt1++;
        }
        cout<<cnt1*quick_pow(2,cnt0)<<"\n";
    }
    return 0;
}
