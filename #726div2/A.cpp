#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
const ll maxn = 55;
ll a[maxn];
int main(){
    ll n;
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll sum = 0;
        for(ll i=1;i<=n;i++) sum += a[i];
        if(sum == n) cout<<"0\n";
        else if(sum < n) cout<<"1\n";
        else cout<<(sum-n)<<"\n";
    }
    return 0;
}