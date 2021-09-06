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
const ll maxn = 1e5+5;

ll a[maxn],sum[maxn];
set<ll> s;
void cal(ll l,ll r){
    if(l >= r) return;
    ll mid = (a[l]+a[r])>>1;
    ll m = upper_bound(a+l,a+r,mid)-a;
    if(m == r && a[r]<=mid) return;
    if(m-1 >= l){
        s.insert(sum[m-1]-sum[l-1]);
        cal(l,m-1);
    }
    if(m <= r){
        s.insert(sum[r]-sum[m-1]);
        cal(m,r);
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,q,num;
    cin>>T; while(T--){
        s.clear();
        cin>>n>>q;
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
        cal(1,n);
        s.insert(sum[n]);
        while(q--){
            cin>>num;
            if(s.count(num)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
