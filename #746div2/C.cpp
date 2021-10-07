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
const ll maxn = 1e5+5;
ll a[maxn],dp[maxn];
vector<ll> v[maxn];
ll sum,cnt;
ll dfs(ll now,ll last){
    dp[now] = a[now];
    ll tmp = 0;
    rep(i,0,v[now].size()){
        ll nxt = v[now][i];
        if(nxt == last) continue;
        tmp += dfs(nxt,now);
        dp[now] ^= dp[nxt];
    }
    if(tmp==0 && dp[now]==sum){
        cnt++;
        return 1;
    }
    if(tmp==1 && dp[now]==0){
        cnt++;
        return 1;
    }
    return tmp;
}
int main(){
    IOS;
    ll n,k,l,r;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) dp[i] = 0;
        Rep(i,1,n) v[i].clear();
        Rep(i,1,n-1){
            cin>>l>>r;
            v[l].push_back(r);
            v[r].push_back(l);
        }
        sum = 0;
        Rep(i,1,n) sum ^= a[i];
        if(sum == 0){
            cout<<"YES\n";
            continue;
        }
        cnt = 0;
        dfs(1,-1);
        if(cnt>=2 && k>2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
