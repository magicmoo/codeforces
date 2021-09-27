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
const ll maxn = 105;
ll dp[maxn][maxn];
ll dp2[maxn][maxn];
vector<ll> v[maxn];
ll ans;
void dfs(ll now,ll last,ll num,ll len){
    dp[num][len]++;
    rep(i,0,v[now].size()){
        ll nxt = v[now][i];
        if(nxt == last) continue;
        dfs(nxt,now,num,len+1);
    }
}
int main(){
    IOS;
    ll n,k,l,r;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) v[i].clear();
        ans = 0;
        Rep(i,2,n){
            cin>>l>>r;
            v[l].push_back(r);
            v[r].push_back(l);
        }
        if(k == 2){
            cout<<n*(n-1)/2<<"\n";
            continue;
        }
        Rep(i,1,n){
            memset(dp,0,sizeof(dp));
            rep(j,0,v[i].size()) dfs(v[i][j],i,j+1,1);
            Rep(len,1,n){
                memset(dp2,0,sizeof(dp2));
                dp2[0][0] = 1;
                Rep(now,1,v[i].size()){
                    dp2[now][0] = 1;
                    Rep(j,1,min(k,now)){
                        dp2[now][j] = (dp2[now-1][j-1]*dp[now][len])%mod;
                        if(j <= now) dp2[now][j] = (dp2[now][j]+dp2[now-1][j])%mod;   
                    }
                }
                ans += (dp2[v[i].size()][k])%mod;
                ans %= mod;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
