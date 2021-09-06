#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[5][maxn],pre[5][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll m;
    CAS{
        cin>>m;
        Rep(i,1,2) Rep(j,1,m) cin>>a[i][j];
        ll sum1 = 0,sum2 = 0;
        Rep(j,1,m) sum1 += a[1][j];
        Rep(j,1,m) sum2 += a[2][j];
        Rep(i,1,2){
            Rep(j,1,m){
                pre[i][j] = pre[i][j-1]+a[i][j];
            }
        }
        ll ans = 1e18;
        Rep(i,1,m){
            ll tmp = max(pre[1][m]-pre[1][i],pre[2][i-1]);
            ans = min(ans,tmp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
