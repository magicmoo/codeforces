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
const int INF = 0x3f3f3f3f;
const int maxn = 5005;
int dp[maxn][maxn];
char a[maxn],b[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m,now,ans = 0;
    cin>>n>>m;
    scanf("%s%s",(a+1),(b+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+2;
            else dp[i][j] = max(max(dp[i-1][j],dp[i][j-1])-1,0);
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
