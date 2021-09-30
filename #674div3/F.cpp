#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
const ll mod = 1e9+7;
char str[maxn];
ll prea[maxn],preb[maxn],prec[maxn],pre[maxn];
ll bs[maxn];
int main(){
    // IOS;
    ll n;
    scanf("%d",&n);
    scanf("%s",str+1);
    Rep(i,1,n){
        prea[i] = prea[i-1];
        preb[i] = preb[i-1];
        prec[i] = prec[i-1];
        pre[i] = pre[i-1];
        if(str[i]=='a') prea[i]++;
        if(str[i]=='b') preb[i]++;
        if(str[i]=='c') prec[i]++;
        if(str[i]=='?') pre[i]++;
    }
    ll k = pre[n];
    bs[0] = 1;
    Rep(i,1,n){
        bs[i] = (3*bs[i-1])%mod;
    }
    ll ans = 0;
    ll a = 0,ab = 0;
    Rep(i,1,n){
        if(str[i]=='a') a++;
        if(str[i]=='b') ab+=a;
        if(str[i]=='c') ans+=(ab*bs[k])%mod;
        if(str[i]=='?') ans += (ab*bs[k-1])%mod;
        ab %= mod;
        ans %= mod;
    }
    Rep(i,1,n){
        if(str[i]!='?') continue;
        ans += prea[i]*(prec[n]-prec[i])%mod*bs[k-1]%mod;
        ans %= mod;
    }
    ll c = 0,bc = 0;
    Dep(i,n,1){
        if(str[i]=='c') c++;
        if(str[i]=='b') bc+=c;
        if(str[i]=='?') ans+=bc*bs[k-1]%mod;
        bc %= mod;
        ans %= mod;
    }
    if(k>=2){
        Rep(i,1,n){
            if(str[i]=='?') continue;
            if(str[i]=='a'){
                ll cnt = pre[n]-pre[i];
                ans += (cnt*(cnt-1)/2)%mod*bs[k-2]%mod;
            }else if(str[i]=='b'){
                ans += pre[i]*(pre[n]-pre[i])%mod*bs[k-2]%mod;
            }else if(str[i]=='c'){
                ll cnt = pre[i];
                ans += (cnt*(cnt-1)/2)%mod*bs[k-2]%mod;
            }
            ans %= mod;
        }
    }
    if(k>=3) ans += (k*(k-1)*(k-2)/6)%mod*bs[k-3]%mod;
    ans %= mod;
    cout<<ans<<"\n";
    return 0;
}
