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
ll a[maxn];
ll b[maxn][30],cnt[30];
ll ans;
void solve(ll cnt,ll l,ll r,ll sum,ll num){
    if(r-l+1 <= 2){
        ans = min(sum,ans);
        return;
    }
    ll index = lower_bound(a+l,a+r+1,num+(1<<cnt))-a;
    ll num1 = index-l;
    ll num2 = r-l+1-num1;
    num2 = max(num2-1,0LL);
    num1 = max(num1-1,0LL);
    if(index>l) solve(cnt-1,l,index-1,sum+num2,num);
    if(r>=index) solve(cnt-1,index,r,sum+num1,num+(1<<cnt));
}
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ans = INF;
    solve(30,1,n,0,0);
    cout<<ans<<"\n";
    return 0;
}