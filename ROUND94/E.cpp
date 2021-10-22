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
const ll maxn = 5e3+5;
ll a[maxn],n;
ll solve(ll l,ll r){
    if(r == l){
        if(a[l]==0) return 0;
        return 1;
    }
    ll ans = INF;
    Rep(i,l,r) ans = min(ans,a[i]);
    Rep(i,l,r) a[i] -= ans;
    ll last = -1;
    Rep(i,l,r){
        if(last==-1 && a[i]!=0) last = i;
        else if(last!=-1 && a[i]==0){
            ans += solve(last,i-1);
            last = -1;
        }
    }
    if(last!=-1 && last<=r) ans += solve(last,r);
    return min(ans,r-l+1);
}
int main(){
    IOS;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    cout<<solve(1,n)<<"\n";
    return 0;
}
