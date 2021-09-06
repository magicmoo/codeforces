#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 205;
const ll maxv = 1e5+5;
ll t[maxn],x[maxn],y[maxn];
ll dp[maxn][maxv],ans[maxv];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];
    dp[0][0] = 1;
    for(ll i=1;i<=n;i++){
        dp[i][0] = 1;
        for(ll j=0;j<=m;j++){
            if(!dp[i-1][j]) continue;
            ll now = j;
            for(ll k=0;k<y[i];k++){
                double temp;
                if(t[i]==1) temp = now+1.0*x[i]/1e5;
                else temp = now*1.0*x[i]/1e5;
                now = ceil(temp);
                if(now>m || dp[i-1][now]) break;
                dp[i][now] = 1; ans[now] = i;
            }
        }
        for(ll j=0;j<=m;j++){
            if(dp[i-1][j] && !dp[i][j]) dp[i][j] = 1; 
        }
    }
    for(ll i=1;i<=m;i++){
        if(ans[i] == 0) cout<<"-1 ";
        else cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
