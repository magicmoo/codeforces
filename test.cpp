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
const ll maxn = 1e5+5;
const ll mod = 1e9+7;
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
PII a[maxn];
unordered_map<ll,ll> mp;
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i].first>>a[i].second;
        Rep(i,1,n) mp[a[i].first] = a[i].second;
        sort(a+1,a+1+n);
        ll ans = 1;
        Rep(i,1,n){
            
        }
        cout<<ans<<"\n";
    }
    return 0;
}
