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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 5e3+5;
ll a[maxn],b[maxn];
ll dp[maxn][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) cin>>b[i];
    ll ans = 0;
    for(ll size=2;size<=n;size++){
        for(ll l=1;l+size-1<=n;l++){
            ll r = l+size-1;
            dp[l][size] = dp[l+1][size-2]+(-a[l]*b[l]-a[r]*b[r]+a[l]*b[r]+a[r]*b[l]);
            ans = max(dp[l][size],ans);
        }
    }
    ll temp = 0;
    for(ll i=1;i<=n;i++) temp += a[i]*b[i];
    cout<<temp+ans<<"\n";
    return 0;
}
