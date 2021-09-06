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
const ll mod = 1e9+7;
ll a[5][maxn],n;
ll book[5][maxn],mp[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n;
        for(ll i=1;i<=n;i++) mp[i] = 0;
        for(ll i=1;i<=2;i++)
            for(ll j=1;j<=n;j++)
                cin>>a[i][j];
        for(ll i=1;i<=2;i++){
            for(ll j=1;j<=n;j++){
                book[i][a[i][j]] = j;
            }
        }
        ll ans = 1;
        for(ll i=1;i<=n;i++){
            if(mp[i]) continue;
            ll now = a[1][i],num = a[2][i];
            while(num != now){  
                ll index = book[1][num];
                num = a[2][index];
                mp[index] = 1;
            }
            ans *= 2;
            ans %= mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
