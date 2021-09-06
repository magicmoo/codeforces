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
const ll mod = 1e9+7;
const ll maxn = 1e5+5;
ll val[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif  
    ll n,k;
    val[1] = 1;
    for(ll i=2;i<=1e5;i++) val[i] = (val[i-1]*i)%mod;
    CAS {
        cin>>n>>k;
        ll ans = 1;
        for(ll i=0;i<k;i++) ans = (ans*n)%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
