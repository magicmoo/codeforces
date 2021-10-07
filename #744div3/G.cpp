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
const ll maxn = 1e4+5;
const ll maxv = 1e3+5;
ll a[maxn];
ll dp[2][maxv*2];
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        dp[0][0] = 0;
        Rep(i,1,2e3) dp[0][i] = INF;
        Rep(j,1,n){
            Rep(i,0,2e3) dp[1][i] = INF;
            Rep(i,0,2e3){
                if(i+a[j] <= 2e3){
                    if(dp[0][i]<=a[j]) dp[1][i+a[j]] = 0;
                    else dp[1][i+a[j]] = min(dp[1][i+a[j]],dp[0][i]-a[j]);
                }
                if(i <= a[j]) dp[1][0] = min(dp[1][0],dp[0][i]+a[j]);
                else dp[1][i-a[j]] = min(dp[1][i-a[j]],dp[0][i]+a[j]);
            }
            Rep(i,0,2e3){
                dp[0][i] = dp[1][i];
            }
        }
        ll cnt = INF;
        Rep(i,0,2e3){
            cnt = min(dp[0][i]+i,cnt);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
