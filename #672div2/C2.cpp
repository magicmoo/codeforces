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
const ll maxn = 3e5+5;
ll a[maxn],ans,n,q,l,r;
ll calc(ll num){
    if(num<=0 || num>n) return 0;
    if(a[num]>a[num-1] && a[num]>a[num+1]) return a[num];
    if(a[num]<a[num-1] && a[num]<a[num+1]) return -a[num];
    return 0;
}
set<ll> s;
int main(){
    IOS;
    CAS {
        ans = 0;
        cin>>n>>q;
        Rep(i,1,n) cin>>a[i];
        ll flag = 0;
        ll l = 1;
        a[0] = a[n+1] = -INF;
        Rep(i,1,n){
            if(a[i]>a[i-1] && a[i]>a[i+1]) ans += a[i];
            if(a[i]<a[i-1] && a[i]<a[i+1]) ans -= a[i];
        }
        cout<<ans<<"\n";
        while(q--){
            s.clear();
            cin>>l>>r;
            Rep(i,l-1,l+1){
                ans -= calc(i);
                s.insert(i);
            }
            Rep(i,r-1,r+1){
                if(s.count(i)) continue;
                ans -= calc(i);
            }
            swap(a[l],a[r]);
            s.clear();
            Rep(i,l-1,l+1){
                ans += calc(i);
                s.insert(i);
            }
            Rep(i,r-1,r+1){
                if(s.count(i)) continue;
                ans += calc(i);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
