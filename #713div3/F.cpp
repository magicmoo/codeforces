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
ll a[maxn],b[maxn];
int main(){
    IOS;
    ll n,c;
    CAS {
        cin>>n>>c;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n-1) cin>>b[i];
        ll last = 0,time = 0;
        ll ans = INF;
        Rep(i,1,n){
            ans = min(ans,time+(c-last+a[i]-1)/a[i]);
            if(last >= b[i]){
                last -= b[i];
                time++;
            }else{
                time += (b[i]-last+a[i]-1)/a[i]+1;
                last += (b[i]-last+a[i]-1)/a[i]*a[i];
                last -= b[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
