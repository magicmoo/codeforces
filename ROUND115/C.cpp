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
map<ll,ll> mp;
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        mp.clear();
        Rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        ll sum = 0,ans = 0;
        Rep(i,1,n){
            sum += a[i];
        }
        if((sum*2)%n!=0){
            cout<<"0\n";
            continue;
        }
        Dep(i,n,1){
            ll num = 2*sum/n-a[i];
            ans += mp[num];
            mp[a[i]]++;  
        }
        cout<<ans<<"\n";
    }
    return 0;
}
