#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<ll,ll>
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e6+5;
const ll mod = 998244353;
ll a[maxn],dp[maxn],pre[maxn];
vector<ll> vec;
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0) {
        x=1,y=0;
        return a;
    }
    ll r = exgcd(b,a%b,x,y);
    ll t = x;
        x = y;
        y = t - a/b*y;
    return r;
}
ll INV(ll n,ll m)
{
    ll x,y;
    ll ans = exgcd(n,m,x,y);
    if(ans == 1)
        return (x%m+m)%m;
    //定义：正整数 a, n，如果有 ax ≡ 1(mod n)，则称 x 的最小整数解为 a 模 n的逆元。
    else
        return -1;
}
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ll cnt = 1;
    Rep(i,2,n){
        if(a[i]!=a[i-1]){
            vec.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    vec.push_back(cnt);
    dp[0] = 1;
    Rep(i,1,n) dp[i] = (dp[i-1]*i)%mod;
    pre[0] = 1;
    Rep(i,2,n){
        pre[i] = pre[i-2]*((i*(i-1)/2)%mod)%mod*2%mod;
    }
    cnt = vec[0];
    ll ans = dp[cnt],tmp;
    rep(i,1,vec.size()){
        if(vec[i]%2==0) tmp = vec[i];
        else{
            tmp = vec[i]-1;
            ans *= vec[i];
            ans %= mod;
        }
        ans *= pre[tmp]*INV(dp[tmp/2],mod)%mod*dp[cnt+tmp/2]%mod*INV(dp[cnt],mod)%mod;
        cnt += vec[i];
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}