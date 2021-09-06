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
const ll maxn = 1e5+5;
struct Node{
    ll a,b;
}nodes[maxn];
bool cmp(Node n1,Node n2){
    return n1.b < n2.b;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>nodes[i].a>>nodes[i].b;
    ll ans = 0,last = 0;
    for(ll i=1;i<=n;i++){
        last += nodes[i].a;
        ans += nodes[i].a*2;
    }
    sort(nodes+1,nodes+1+n,cmp);
    for(ll i=n;i>0;i--){
        if(nodes[i].b < last){
            ll num = min(last-nodes[i].b,nodes[i].a);
            last -= num; ans -= num;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
