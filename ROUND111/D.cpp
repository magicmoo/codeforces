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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
const ll mod = 1e9+7;
ll arr[maxn];

ll n,m,k;
ll f[maxn],inv[maxn];
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
void init()
{
	f[0]=inv[0]=1;
	for(ll i=1; i<maxn; i++)
	{
		f[i]=f[i-1]*i%mod;
		inv[i]=qpow(f[i],mod-2);
	}
}
 
ll C(ll n,ll m)
{
	return f[n]*inv[n-m]%mod*inv[m]%mod;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,l,r;
    init();
    CAS {
        cin>>n>>l>>r;
        ll min1 = (r-n),min2 = abs(l-1);
        ll ans = min(min1,min2)*C(n,n/2);
        if(n%2) ans*=2;
        ans %= mod;
        ll l = 0,r = 0;
        for(ll i=min(min1,min2)+1;;i++){
            if(i>min1) r++;
            if(i>min2) l++;
            if(r>(n+1)/2 || l>(n+1)/2) break;
            ll tmp = 0;
            if(n-l-r>0){
                if(n%2==0) tmp =  C(n-l-r,n/2-l);
                else{
                    if(r<(n+1)/2) tmp += C(n-l-r,(n+1)/2-l);
                    if(l<(n+1)/2) tmp += C(n-l-r,(n+1)/2-r);
                }
            }else if(n-l-r==0){tmp = 1;}
            ans += tmp;
            ans %= mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
