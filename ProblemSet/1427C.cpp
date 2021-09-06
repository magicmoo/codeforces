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
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
struct Node{
    int t,x,y;
}nodes[maxn];
int dp[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int r,n;
    cin>>r>>n;
    for(int i=1;i<=n;i++) cin>>nodes[i].t>>nodes[i].x>>nodes[i].y;
    nodes[0].x = nodes[0].y = 1;
    nodes[0].t = 0;
    for(int i=1;i<=n;i++) dp[i] = -INF;
    int Max = -INF;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i-2*r >= 0) Max = max(Max,dp[i-2*r]);
        dp[i] = Max+1;
        for(int j=max(0,i-2*r+1);j<i;j++){
            if(abs(nodes[i].x-nodes[j].x)+abs(nodes[i].y-nodes[j].y) <= nodes[i].t-nodes[j].t)
                dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;   
}
