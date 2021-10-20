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
const ll maxn = 105;
ll a[maxn][maxn];
ll dp[maxn][maxn][maxn];
ll dp2[2][maxn];
int main(){
    IOS;
    ll N,M,K;
    cin>>N>>M>>K;
    Rep(i,1,N){
        Rep(j,1,M){
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    Rep(i,1,N){
        dp[i][0][0] = 0;
        Rep(j,1,M){
            Dep(jj,min(j,M/2),1){
                rep(k,0,K){
                    if(dp[i][jj-1][k]<0) continue;
                    dp[i][jj][(k+a[i][j])%K] = max(dp[i][jj-1][k]+a[i][j],dp[i][jj][(k+a[i][j])%K]);
                }
            }
        }
    }
    memset(dp2,-1,sizeof(dp2));
    dp2[0][0] = 0;
    Rep(i,1,N){
        Rep(j,0,M/2){
            rep(k,0,K){
                if(dp2[0][k]<0) continue;
                rep(kk,0,K){
                    if(dp[i][j][kk]<0) continue;
                    dp2[1][(k+dp[i][j][kk])%K] = max(dp2[0][k]+dp[i][j][kk],dp2[1][(k+dp[i][j][kk])%K]);
                }
            }  
        }
        rep(k,0,K){
            dp2[0][k] = dp2[1][k];
            dp2[1][k] = -1;
        }
    }
    cout<<dp2[0][0]<<"\n";
    return 0;
}
