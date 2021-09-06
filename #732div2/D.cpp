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
const ll mod = 998244353;
const ll maxn = 1e5+5;
ll arr[maxn];
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
 
ll C(ll n,ll m) //n>=m
{
	return f[n]*inv[n-m]%mod*inv[m]%mod;
}
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    init();
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++) scanf("%1d",&arr[i]);
        ll num = 0,num0 = 0;
        for(ll i=1;i<=n;i++){
            if(arr[i] == 0) num0++;
            if(arr[i]==1 && arr[i+1]==1){
                num++; ++i;
            }
        }
        cout<<C(num0+num,num)<<"\n";
    }
    return 0;
}
