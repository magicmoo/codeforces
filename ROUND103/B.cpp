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
const ll maxn = 105;

ll p[maxn],x[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ll ans = 0;
        memset(x,0,sizeof(x));
        for(ll i=1;i<=n;i++){ cin>>p[i]; x[i] = x[i-1]+p[i];}
        // for(ll i=n-1;i>0;i--){
        //     if(1.0*(p[i+1]+a[i+1])/x[i] <= 1.0*k/100) continue;
        //     a[i] = ((100*(p[i+1]+a[i+1])-k*x[i])+k+99)/(k+100);
        //     if(a[i] > a[i+1]){
        //         a[i] = ((100*p[i+1]-k*x[i])+k-1)/k;
        //         ll last = a[i];
        //         for(ll j=i+1;j<n;j++){
        //             if(a[j] >= last){
        //                 a[j] = a[j]-last;
        //                 break;
        //             }
        //             last -= a[j];
        //             a[j] = 0;
        //         }
        //         ans += last;
        //     }else a[i+1] -= a[i];
        // }
        ll now = p[1];
        for(ll i=2;i<=n;i++){
            if(1.0*(p[i])/now <= 1.0*k/100){ now += p[i]; continue; }
            ll num = (100*p[i]+k-1)/k-now;
            now += num+p[i];
            ans += num;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
