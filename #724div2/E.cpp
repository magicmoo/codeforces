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
const int maxn = 2e3+5;
const int mod = 1e9+7;
char a[maxn][maxn];
const ll maxv = 4e6+5;
ll f[maxv],inv[maxv];
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
	for(ll i=1; i<maxv; i++)
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
    IOS;
    int n,m;
    init();
    CAS {
        cin>>n>>m;
        int cnt = 0;
        Rep(i,1,n){
            Rep(j,1,m){
                cin>>a[i][j];
                if(a[i][j] == '#') cnt++;
            }
        }
        ll ans = 0;
        Rep(i,1,cnt){
            ans += C(cnt,i);
            ans %= mod;
        }
        if(cnt != n*m) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
