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
const ll maxn = 4e5+5;
ll a[maxn],b[maxn];
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    ll ans = 0;
    rep(j,0,30){
        ll cnt = 0;
        Rep(i,1,n) b[i] = a[i]%(1<<(j+1));
        sort(b+1,b+1+n);
        Rep(i,1,n){
            ll l = (1<<j)-b[i],r = (1<<(j+1))-1-b[i];
            ll index1 = lower_bound(b+i+1,b+1+n,l)-b;
            ll index2 = upper_bound(b+i+1,b+1+n,r)-b;
            cnt += index2-index1;
            l += (1<<(j+1));
            r += (1<<(j+1));
            index1 = lower_bound(b+i+1,b+1+n,l)-b;            
            index2 = upper_bound(b+i+1,b+1+n,r)-b;
            cnt += index2-index1;
        }
        if(cnt%2==1) ans += 1<<j; 
    }
    cout<<ans<<"\n";
    return 0;
}
