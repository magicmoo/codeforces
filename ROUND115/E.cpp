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
ll a[maxn][maxn];
ll n,m,q;
ll calc(ll x,ll y){
    ll cnt1=0,cnt2=0,cnt11=0,cnt22=0;
    ll tx = x,ty = y,fx = 0;
    while(tx>=1 && ty>=1 && !a[tx][ty]){
        cnt1++;
        if(fx==1) tx--;
        else ty--;
        fx = !fx;
    }
    tx = x,ty = y,fx = 1;
    while(tx>=1 && ty>=1 && !a[tx][ty]){
        cnt2++;
        if(fx==1) tx--;
        else ty--;
        fx = !fx;
    }
    tx = x,ty = y,fx = 1;
    while(tx<=n && ty<=m && !a[tx][ty]){
        cnt11++;
        if(fx==1) tx++;
        else ty++;
        fx = !fx;
    }
    tx = x,ty = y,fx = 0;
    while(tx<=n && ty<=m && !a[tx][ty]){
        cnt22++;
        if(fx==1) tx++;
        else ty++;
        fx = !fx;
    }
    return cnt1*cnt11+cnt2*cnt22;
}
int main(){
    IOS;
    ll x,y;
    cin>>n>>m>>q;
    ll ans = n*m;
    Rep(i,1,m){
        ll cnt = 1+min(n-1,m-i)+min(n,m-i);
        ans += cnt*(cnt-1)/2;
    }
    Rep(i,1,n){
        ll cnt = 1+min(m-1,n-i)+min(m,n-i);
        ans += cnt*(cnt-1)/2;
    }
    while(q--){
        cin>>x>>y;
        if(a[x][y]){
            a[x][y] = 0;
            ans += calc(x,y)-1;
        }else{
            ans -= calc(x,y)-1;
            a[x][y] = 1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
