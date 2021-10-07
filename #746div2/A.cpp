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
const ll maxn = 1e3+5;
ll a[maxn];
int main(){
    IOS;
    ll n,h;
    CAS {
        cin>>n>>h;
        Rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        ll ans = 0;
        ll sum = 0;
        sum = a[n]+a[n-1];
        ans += (h/sum)*2;
        h -= h/sum*sum;
        if(h == 0);
        else if(h <= a[n]) ans++;
        else ans += 2;
        cout<<ans<<"\n";
    }
    return 0;
}
