#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9+7;
const ll maxn = 2e5+5;
ll n,k;
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
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
ll post(ll i){
    return quick_pow(2,(k-i)*n,mod)%mod;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    init();
    CAS {
        cin>>n>>k;
        if(k == 0){
            cout<<"1\n";
            continue;
        }
        ll ans = 0;
        ll tmp1 = 0,tmp2 = 0;
        Rep(i,0,n){
            if(i%2 == 0){
                tmp1 += C(n,i);
                tmp1 %= mod;
            }else{
                tmp2 += C(n,i);
                tmp2 %= mod;
            }
        }
        // ll tmp3 = (quick_pow(2,k,mod)-1+mod)%mod;
        ll pre = 1;
        if(n%2 == 0){
            Rep(i,1,k){
                ans += pre*post(i);
                pre *= (tmp1-1);
                ans%=mod; pre%=mod;
            }
            ans += quick_pow(tmp1-1,k,mod);
        }else{
            ans = 1;
            Rep(i,1,k){
                ans *= (1+tmp1)%mod;
                ans %= mod;
            }
        }
        cout<<ans%mod<<"\n";
    }
    return 0;
}

