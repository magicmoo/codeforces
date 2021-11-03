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
const int mod = 998244353;
const int maxn = 505;
const ll maxv = 505;
ll C[maxv][maxv];   
void init(){
	for(ll i=0;i<maxv;i++) C[i][0]=1;
	for(ll i=1;i<maxv;i++)
	    for(ll j=1;j<maxv;j++)
	        C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
}
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
int dp[maxn][maxn],sum[maxn][maxn];
int main(){
    IOS;
    int n,x;
    cin>>n>>x;
    init();
    ll ans = 0;
    Rep(j,0,x) sum[0][j] = 1;
    Rep(i,2,n){
        memset(dp,0,sizeof(dp));
        Rep(j,0,x){
            if(j<i){
                dp[j][0] = quick_pow(min(i-1,j),i,mod);
                sum[i][j] = dp[j][0];
                continue;
            }
            Rep(k,0,i){
                if(k==1) continue;
                dp[j][k] = sum[k][j-(i-1)]*quick_pow(i-1,i-k,mod)%mod*C[i][k]%mod;
            }
            Rep(k,0,i){
                if(k==1) continue;
                sum[i][j] += dp[j][k];
                sum[i][j] %= mod;
            }
        }
    }
    Rep(k,0,n){
        if(k==1) continue;
        ans += dp[x][k];
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}
