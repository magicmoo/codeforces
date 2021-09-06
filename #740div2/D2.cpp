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
const ll maxn = 4e6+5;
ll dp[maxn],pre[maxn],s[maxn];
ll n,m;
int main(){
    IOS;
    cin>>n>>m;
    // Rep(i,1,n) dp[i] = 1;
    dp[1] = 1,pre[1] = 1;
    ll now = 0;
    Rep(i,2,n){
        s[i] += s[i-1]+1;
        s[i] %= m;
        dp[i] += pre[i-1]+s[i];
        dp[i] %= m;
        for(ll j=i*2;j<=n;j+=i){
            s[j] += (dp[i]-dp[i-1]+m)%m;
            s[j] %= m;
        }
        dp[i] %= m;
        pre[i] = (pre[i-1]+dp[i])%m;
    }
    cout<<dp[n]<<"\n";
    return 0;
}
