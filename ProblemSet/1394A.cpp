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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn],pre[maxn];
vector<ll> l,r;
bool cmp(ll a,ll b){ return a>b; }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,d,m;
    cin>>n>>d>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    l.push_back(0); r.push_back(0);
    for(ll i=1;i<=n;i++){
        if(a[i] <= m) l.push_back(a[i]);
        else r.push_back(a[i]);
    }
    sort(l.begin(),l.end()); sort(r.begin()+1,r.end(),cmp);
    ll lenl = l.size()-1,lenr = r.size()-1;
    ll small = (lenr+d)/(d+1);
    ll big = min(lenr,(n+d)/(d+1));
    ll ans = 0,last = 0;
    for(ll i=1;i<small;i++) last += r[i];
    for(ll i=1;i<=lenl;i++) pre[i] = l[i] + pre[i-1];
    for(ll i=small;i<=big;i++){
        last += r[i];
        ll num = max(d*(i-1)-(lenr-i),0LL);
        ll temp = last + pre[lenl]-pre[num];
        ans = max(temp,ans);
    }
    cout<<ans<<"\n";
    return 0;
}
