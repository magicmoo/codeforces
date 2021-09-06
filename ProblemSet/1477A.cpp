#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
ll a[maxn];


int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,k;
    cin>>T; while(T--){
        cin>>n>>k;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=1;i<n;i++){ a[i] -= a[0]; a[i] = abs(a[i]); }
        k -= a[0];
        k = abs(k);
        ll ans = a[1];
        for(ll i=2;i<n;i++){
            ans = __gcd(ans,a[i]);
        }
        if(k%ans==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
