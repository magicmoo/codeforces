#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn],book[maxn*2];
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        for(ll i=1;i<=2*n;i++) book[i] = 0;
        ll ans = 0;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) book[a[i]] = i;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j*a[i]<=2*n;j++){
                ll num = a[i]*j;
                if(j == a[i] || book[j]==0) continue;
                if(i+book[j] == num){
                    ans++;
                }
            }
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}