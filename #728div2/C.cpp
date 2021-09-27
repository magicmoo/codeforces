#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn];
int main(){
    IOS;
    ll n;
    CAS{
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        ll last = 0,ans = 0;
        for(ll i=2;i<=n;i++){
            ans -= (a[i]-a[i-1])*(i-2);
            ans -= last;
            last += (a[i]-a[i-1])*(i-1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}