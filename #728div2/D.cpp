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
const ll maxn = 205;
const ll mod = 1e9+7;
ll dp[maxn][maxn];
ll cnt[maxn];
vector<ll> v[maxn];
ll pre[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0) {
        x=1,y=0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
        x = y;
        y = t - a/b*y;
    return r;
}
ll inv(ll n,ll m)
{
    ll x,y;
    ll ans = exgcd(n,m,x,y);
    if(ans == 1)
        return (x%m+m)%m;
    //定义：正整数 a, n，如果有 ax ≡ 1(mod n)，则称 x 的最小整数解为 a 模 n的逆元。
    else
        return -1;
}
void dfs(ll now,ll last,ll len){
    pre[now] = last;
    cnt[now] = len;
    rep(i,0,v[now].size()){
        ll nxt = v[now][i];
        if(nxt == last) continue;
        dfs(nxt,now,len+1);
    }
}
ll LCA(ll x,ll y){
    while(x!=y){
        if(cnt[x]>cnt[y]) x = pre[x];
        else if(cnt[x]<cnt[y]) y = pre[y];
        else x=pre[x],y=pre[y];
    }
    return x;
}
int main(){
    IOS;
    Rep(i,1,200) dp[0][i] = 1;
    Rep(i,1,200){
        Rep(j,1,200){
            dp[i][j] = ((dp[i-1][j]+dp[i][j-1])%mod*inv(2,mod))%mod;
        }
    }
    ll n,l,r;
    cin>>n;
    Rep(i,1,n-1){
        cin>>l>>r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    ll ans = 0;
    Rep(now,1,n){
        dfs(now,-1,0);
        Rep(i,1,n){
            Rep(j,i+1,n){
                ll index = LCA(i,j);
                if(index==i || index==j){
                    if(cnt[i] > cnt[j]) ans += inv(n,mod);
                }else{
                    ans += dp[cnt[j]-cnt[index]][cnt[i]-cnt[index]]*inv(n,mod)%mod;
                }
                ans = (ans+mod)%mod;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
