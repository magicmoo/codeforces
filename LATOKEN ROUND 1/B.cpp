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
const ll maxn = 4e5+5;
ll a[maxn],n;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        a[n+1] = 0;
        ll ans = 0;
        for(ll i=1;i<=n+1;i++){
            ans += abs(a[i]-a[i-1]);
        }
        for(ll i=1;i<=n;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                ans -= a[i]-max(a[i-1],a[i+1]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
