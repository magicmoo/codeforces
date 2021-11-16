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
const ll maxn = 2e5+5;
const ll mod = 998244353;
ll a[maxn],b[maxn];
vector<ll> vec;
int main(){
    IOS;
    ll n,m;
    cin>>n>>m;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,m) cin>>b[i];
    ll l=0,now=m;
    Dep(i,n,1){
        if(a[i]==b[now]){
            vec.push_back(i);
            now--;
        }
    }
    reverse(vec.begin(),vec.end());
    if(now!=0){
        cout<<"0\n";
        return 0;
    }
    ll ans = 1;
    rep(j,1,vec[0]){
        if(a[j] < b[1]) ans = 0;
    }
    Rep(j,vec.back()+1,n){
        if(a[j] < b[m]) ans = 0;
    }
    rep(i,0,vec.size()-1){
        ll l = vec[i]+1;
        Rep(j,vec[i]+1,vec[i+1]-1){
            if(a[j]<b[i+1]) ans = 0;
            else if(a[j]<b[i+2]) l=j+1;
        }
        if(ans==0) break;
        ans *= (vec[i+1]-l+1);
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}
