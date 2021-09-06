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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll MAXN = 5000+5;
const ll mod = 1e9+7;

ll n,k,q,ans;
ll m[MAXN];
ll book[MAXN];
ll dp[MAXN][MAXN];
// ll road[MAXN];
// void dfs(ll now,ll t){
//     road[t] = now;
//     if(t == k){
//         for(ll i=0;i<k+1;i++){
//             book[road[i]]++;
//             ans += m[road[i]];
//         }
//         return;
//     }
//     if(now>0) dfs(now-1,t+1);
//     if(now<n-1) dfs(now+1,t+1);
// }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin);
    // freopen("../out.txt","w",stdout);
    cin>>n>>k>>q;
    for(ll i=1;i<=n;i++) cin>>m[i];
    // dp[0][1] = dp[0][n] = 1;
    for(ll i=1;i<=n;i++) dp[0][i] = 1;
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++){
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=k;j++){
            book[i] = (book[i]+dp[j][i]*dp[k-j][i]%mod)%mod;    
        }
    }
    for(ll i=1;i<=n;i++){ ans += book[i]*m[i]%mod; ans %= mod; }
    //for(ll i=1;i<=n;i++) cout<<book[i]<<"\n";
    while(q--){
        ll ii,x;
        cin>>ii>>x;
        ans += (x-m[ii])%mod*book[ii]%mod;
        ans = (ans+mod)%mod;
        m[ii] = x;
        cout<<ans<<"\n";
    }
    return 0;
}
