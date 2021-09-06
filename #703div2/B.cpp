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
const ll maxn = 1005;

ll x[maxn],y[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n;
    cin>>T; while(T--){
        cin>>n;
        for(ll i=0;i<n;i++) cin>>x[i]>>y[i];
        if(n%2 == 1){
            cout<<"1\n";
            continue;
        }
        sort(x,x+n); sort(y,y+n);
        ll xx = x[n/2]-x[n/2-1]+1;
        ll yy = y[n/2]-y[n/2-1]+1;
        cout<<xx*yy<<"\n";
    }
    return 0;
}
