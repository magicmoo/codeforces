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
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
const int mod = 998244353;

ll quick(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
inline ll inverse(ll a,ll p){return quick(a,p-2,p);}
ll comb(ll a,ll b,ll m){
    if(a<b) return 0;
    if(a==b) return 1;
    else b=min(b,a-b);
    ll ans=1,ca=1,cb=1; 
    for(int i=0;i<b;i++){
    ca=(ca*(a-i))%m;
    cb=(cb*(b-i))%m;
    }
    ans=(ca*inverse(cb,m))%m;
    return ans;
}
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    ll ans = 0;
    for(int i=n+1;i<=2*n;i++){
        ans += a[i]-a[i-n];
        ans %= mod;
    }
    ans *= comb(2*n,n,mod);
    ans %= mod;
    cout<<ans<<"\n";
    return 0;
}

