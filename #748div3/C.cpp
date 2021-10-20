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
const ll maxn = 4e5+5;
ll a[maxn];
ll n,k;
bool check(ll num){
    ll cnt = 0;
    Rep(i,k-num+1,k){
        cnt += n-a[i];
    }
    return cnt < n;
}
int main(){
    IOS;
    CAS {
        cin>>n>>k;
        Rep(i,1,k) cin>>a[i];
        sort(a+1,a+1+k);
        ll l = 0,r = k;
        while(r-l > 1){
            ll mid = (l+r)/2;
            if(check(mid)) l = mid;
            else r = mid-1;
        }
        if(check(r)) cout<<r<<"\n";
        else cout<<l<<"\n";
    }
    return 0;
}
