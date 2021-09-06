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

ll a[maxn],b[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,x,y;
    cin>>T; while(T--){
        cin>>n;
        ll nowa = 0,nowb = 0;
        for(ll i=0;i<2*n;i++){
            cin>>x>>y;
            if(x == 0) a[nowa++] = abs(y);
            else b[nowb++] = abs(x);
        }
        double ans = 0.0;
        sort(a,a+n); sort(b,b+n);
        for(ll i=0;i<n;i++){
            ans += sqrt(a[i]*a[i]+b[i]*b[i]);
        }
        printf("%.15lf\n",ans);
    }
    return 0;
}
