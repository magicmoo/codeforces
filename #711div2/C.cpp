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
const ll maxn = 1005;
const int mod = 1e9+7;
ll dp[maxn][maxn],pre[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,k;
    CAS {
        cin>>n>>k;
        for(ll i=1;i<=n;i++) pre[i] = 0;
        for(ll i=1;i<=n;i++) dp[1][i] = 1;
        for(ll i=2;i<k;i++){
            for(ll j=1;j<=n;j++){
                pre[j] = pre[j-1]+dp[i-1][j];
                pre[j] %= mod;
            }
            for(ll j=1;j<=n;j++){
                if(i%2==k%2)
                    dp[i][j] = 1+(pre[n]-pre[j]+mod)%mod;
                else
                    dp[i][j] = 1+pre[j-1];
                dp[i][j] %= mod;
            }
        }
        ll ans = 1;
        for(ll i=1;i<=n;i++){
            ans += dp[k-1][i];
            ans %= mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
