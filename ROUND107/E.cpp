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
const ll maxn = 3e5+5;
const ll mod = 998244353;
vector<char> v[maxn];
ll cnt[maxn],pre[maxn];
ll dp[maxn];
int main(){
    IOS;
    ll n,m,w=0;
    char ch;
    cin>>n>>m;
    Rep(i,1,n) v[i].push_back('.');
    Rep(i,1,n){
        Rep(j,1,m){
            cin>>ch;
            v[i].push_back(ch);
            if(ch == 'o') w++;
        }
    }
    cnt[w] = 1;
    Dep(i,w-1,1){
        cnt[i] = (cnt[i+1]*2)%mod;
    }
    ll now = 2;
    Rep(i,2,w){
        if(i%2==0) pre[i] = (pre[i-1]+cnt[i])%mod;
        else pre[i] = (pre[i-1]-cnt[i]+mod)%mod;
    }
    ll ans = 0;
    Rep(i,1,n){
        Rep(j,1,m) dp[j] = 0;
        Rep(j,1,m){
            if(v[i][j]=='*') continue;
            dp[j] = dp[j-1]+1;
            ans += pre[dp[j]];
            ans %= mod;
        }
    }
    Rep(j,1,m){
        Rep(i,1,n) dp[i] = 0;
        Rep(i,1,n){
            if(v[i][j]=='*') continue;
            dp[i] = dp[i-1]+1;
            ans += pre[dp[i]];
            ans %= mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
