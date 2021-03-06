#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2005;
int a[maxn];
int dp[maxn][maxn];
int main(){
    IOS;
    int n,k;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) cin>>a[i];
        int ans = INF;
        Rep(i,1,n){
            Rep(j,1,i){
                if(a[i] == j) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        Rep(j,1,n){
            if(dp[n][j] >= k) ans = min(ans,n-j);
        }
        if(ans == INF) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
