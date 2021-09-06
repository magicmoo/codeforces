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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
const ll mod = 1e9+7;
ll a[maxn],book[maxn];
ll fact[maxn],invFact[maxn],pre[maxn];
ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
ll cal(ll n,ll m){
    if(n > m) return 0;
    return fact[m] * invFact[n] % mod * invFact[m - n] % mod;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,m,k;
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i],mod-2);
    }
    cin>>T; while(T--){
        cin>>n>>m>>k;
        ll ans = 0;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) book[i] = 0;
        for(ll i=1;i<=n;i++) book[a[i]]++;
        for(int i=1;i<=n;i++) pre[i] = pre[i-1]+book[i];
        for(ll i=1;i<=n;i++){
            if(!book[i]) continue;
            ll next = (i+k)>n?n:(i+k);
            ll sum = 0;
            sum = pre[next] - pre[i-1];
            ans += (cal(m,sum)+mod)-cal(m,sum-book[i]);
            ans %= mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
