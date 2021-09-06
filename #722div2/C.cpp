#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
pair<ll,ll> a[maxn];
vector<ll> v[maxn];
ll dp[maxn][2];
ll cal(ll last,ll now,ll num){
    ll ans = 0;
    for(ll i=0;i<v[now].size();i++){
        if(v[now][i] == last) continue;
        ll nex = v[now][i];
        ans += max(abs(num-a[nex].first)+dp[nex][0],abs(num-a[nex].second)+dp[nex][1]);
    }
    return ans;
}
void dfs(ll last,ll now){
    for(ll i=0;i<v[now].size();i++){
        if(v[now][i] == last) continue;
        dfs(now,v[now][i]);
    }
    dp[now][0] = cal(last,now,a[now].first);
    dp[now][1] = cal(last,now,a[now].second);
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,l,r;
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++) v[i].clear();
        for(ll i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
        for(ll i=0;i<n-1;i++){
            cin>>l>>r;
            v[l].push_back(r);
            v[r].push_back(l);
        }
        dfs(0,1);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    }
    return 0;
}
