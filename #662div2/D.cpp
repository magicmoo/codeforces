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
const ll maxn = 2e3+5;
char a[maxn][maxn];
ll dp[4][maxn][maxn];
ll n,m;
int main(){
    IOS;
    cin>>n>>m;
    Rep(i,1,n){
        Rep(j,1,m){
            cin>>a[i][j];
        }
    }
    Rep(i,1,n){
        Rep(j,1,m){
            if(a[i][j]!=a[i-1][j] || a[i][j]!=a[i][j-1]) dp[0][i][j] = 1;
            else dp[0][i][j] = min(dp[0][i-1][j],dp[0][i][j-1])+1;
        }
    }
    Rep(i,1,n){
        Dep(j,m,1){
            if(a[i][j]!=a[i-1][j] || a[i][j]!=a[i][j+1]) dp[1][i][j] = 1;
            else dp[1][i][j] = min(dp[1][i-1][j],dp[1][i][j+1])+1;
        }
    }
    Dep(i,n,1){
        Rep(j,1,m){
            if(a[i][j]!=a[i+1][j] || a[i][j]!=a[i][j-1]) dp[2][i][j] = 1;
            else dp[2][i][j] = min(dp[2][i+1][j],dp[2][i][j-1])+1;
        }
    }
    Dep(i,n,1){
        Dep(j,m,1){
            if(a[i][j]!=a[i+1][j] || a[i][j]!=a[i][j+1]) dp[3][i][j] = 1;
            else dp[3][i][j] = min(dp[3][i+1][j],dp[3][i][j+1])+1;
        }
    }
    ll ans = 0;
    Rep(i,1,n){
        Rep(j,1,m){
            ll cnt = INF;
            rep(k,0,4) cnt = min(cnt,dp[k][i][j]);
            ans += cnt;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
