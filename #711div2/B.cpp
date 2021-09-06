#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,W;
    CAS {
        cin>>n>>W;
        for(ll i=1;i<=n;i++) cin>>a[i];
        multiset<ll> s;
        for(ll i=1;i<=n;i++) s.insert(a[i]);
        ll ans = 1,now = W;
        while(!s.empty()){
            auto i = s.upper_bound(now);
            if(i == s.begin()){
                now = W; ans++; continue;
            }
            i--;
            now -= *i; s.erase(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
