#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 85;
const int maxv = 1e5+5;
PII a[maxn];
int dp[maxn][maxv];
int main(){
    IOS;
    int n,m;
    cin>>n>>m;
    Rep(i,1,n) cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    Rep(i,1,n){
        Rep(j,0,m) dp[i][j] = dp[i-1][j];
        Rep(j,a[i].second,m){
            int l = max(1,a[i].first-j);
            int r = min(m,a[i].first+j);
            dp[i][r] = min(dp[i-1][l-1]+j-a[i].second,dp[i][r]);
        }
        int Min = INF;
        Dep(j,m,0){
            dp[i][j] = min(dp[i][j],Min);
            Min = min(Min,dp[i][j]);
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}
