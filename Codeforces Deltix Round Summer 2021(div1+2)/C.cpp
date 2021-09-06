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
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    // Rep(i,1,n){
    //     pre1[i] = pre1[i-1];
    //     pre2[i] = pre2[i-1];
    //     if(i%2 == 1) pre1[i] += a[i];
    //     else pre2[i] += a[i];
    // }
    ll ans = 0;
    for(ll l=1;l<=n;l+=2){
        if(l==n) continue;
        ans += min(a[l],a[l+1]);
        if(a[l]<a[l+1]) continue;
        ll last = 0;
        ll left = a[l]-a[l+1];
        for(ll r=l+3;r<=n;r+=2){
            if(last < 0){
                left += last;
                last = 0;
                if(left < 0) break;
            }
            if(a[r] < a[r-1]){
                last += a[r-1];
                last -= a[r];
                continue;
            }
            last += a[r-1];
            if(last > a[r]){
                last -= a[r];
                continue;
            }else ans += min(left,a[r]-last)+1;
            last -= a[r];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
