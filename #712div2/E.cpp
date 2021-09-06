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
const ll maxn = 1e5+5;
pair<ll,ll> a[maxn];
namespace A{
ll a[maxn];
ll maxsum[maxn][20],minsum[maxn][20];
void RMQ(ll num){  //共num个数
    for(ll i=1;i<=num;i++)
        maxsum[i][0] = minsum[i][0] = a[i];
    for(ll j=1;j<20;j++){
        for(ll i=1;i<=num;i++){
            if(i+(1<<j)-1 <= num){
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
        }
    }
}
ll maxl,minl;
void Query(ll l,ll r){
    ll k = (ll)(log(r-l+1)/log(2.0));
    maxl = max(maxsum[l][k],maxsum[r-(1<<k)+1][k]);
    minl = min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}
}
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n) cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n);
    Rep(i,1,n) A::a[i] = a[i].first+a[i].second;
    ll ans = 0;
    Rep(i,1,n) ans += a[i].second;
    A::RMQ(n);
    Rep(i,2,n){
        A::Query(1,i-1);
        ll tmp = A::maxl;
        ans += max(0LL,a[i].first-tmp);
    }
    cout<<ans<<"\n";
    return 0;
}
