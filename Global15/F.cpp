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
const ll mod = 998244353;
const ll maxn = 2e5+5;
ll x[maxn],y[maxn],s[maxn];
ll dp[maxn],pre[maxn];
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>x[i]>>y[i]>>s[i];
    Rep(i,1,n){
        ll index = lower_bound(x+1,x+1+n,y[i])-x;
        if(index == i) dp[i] = (x[i]-y[i])%mod;
        else{
            dp[i] = (x[i]-y[i])+(pre[i-1]-pre[index-1]);
            dp[i] = (dp[i]+mod)%mod;
        }
        pre[i] = pre[i-1]+dp[i];
    }
    ll ans = (x[n]+1)%mod;
    Rep(i,1,n){
        if(s[i] == 1) ans += dp[i];
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}
