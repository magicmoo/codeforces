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
const ll maxv = 1e9;

ll solve(ll a,ll b){
    ll ans = 0;
    for(ll i=1;true;i++){
        if(i*(i+1) > a || i>=b) break;
        ans += min(b,a/i-1)-i;
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,x,y;
    cin>>T;
    while(T--){
        cin>>x>>y;
        cout<<solve(x,y)<<"\n";
    }
    return 0;
}
