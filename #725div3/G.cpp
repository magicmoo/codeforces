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
ll x,y,a,b;
bool check(ll n){
    ll num1 = (x-b*n)/(a-b);
    ll num2 = (a*n-y+a-b-1)/(a-b);
    num1 = min(n,num1);
    num2 = max(0LL,num2);
    return num1>=num2;
}
int main(){
    IOS;
    CAS {
        cin>>x>>y>>a>>b;
        if(a<b) swap(a,b);
        if(x<y) swap(x,y);
        if(a == b){
            cout<<min(x/a,y/a)<<"\n";
            continue;
        }
        ll l = 0,r = 1e9;
        while(r-l > 1){
            ll m = (l+r)/2;
            if(check(m)) l = m;
            else r = m;
        }
        if(check(r)) cout<<r<<"\n";
        else cout<<l<<"\n";
    }
    return 0;
}
