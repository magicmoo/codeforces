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
const ll INF = 2e18;
const ll maxn = 1e5+5;
const ll maxv = 5e2+5;
ll a[maxn],pre[maxn];
ll dp[maxn][maxv];
int main(){
    IOS;
    ll n,sum;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n+1){
            Rep(j,0,500) dp[i][j] = 0;
        }
        Rep(i,1,n) pre[i] = pre[i-1]+a[i];
        ll ans = 0;
        dp[n+1][0] = INF;
        Dep(i,n,1){
            dp[i][0] = INF;
            Rep(j,1,500){
                if(n-i+1 < j*(j+1)/2) break;
                sum = pre[i+j-1]-pre[i-1];
                dp[i][j] = max(dp[i+1][j],dp[i+1][j]);
                if(dp[i+j][j-1] <= sum) continue;
                dp[i][j] = max(dp[i][j],sum);
                ans = max(ans,j);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
