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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
ll pre[20];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    ll num = 1e14,cnt = 0;
    while(num){
        pre[cnt++] = 2050*num;
        num /= 10;
    }
    CAS {
        cin>>n;
        ll now = 0,ans = 0;
        while(n && now<cnt){
            while(n<pre[now]) now++;
            n -= pre[now];
            ans++;
        }
        if(n) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
