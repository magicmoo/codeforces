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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
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
    ll n,k,x;
    cin>>n>>k>>x;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    multiset<ll> s;
    ll ans = 1;
    for(ll i=2;i<=n;i++){
        if(a[i]-a[i-1] > x){
            s.insert((a[i]-a[i-1]-1)/x);
            ans++;
        }
    }
    // for(auto i=s.begin();i!=s.end();i++){
    //     cout<<*i<<"\n";
    // }
    for(auto i=s.begin();k>0&&i!=s.end();i++){
        if(k >= *i){
            k -= *i; ans--;
        }else break;
    }
    cout<<ans<<"\n";
    return 0;
}
