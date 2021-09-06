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
const int maxn = 1e2+5;
int dp[2][maxn][maxn*maxn],a[maxn],b[maxn],sum[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,sumb = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum[i] = sum[i-1]+a[i];
        sumb += b[i];
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=a[i];k<=sum[i];k++){
                dp[1][j][k] = max(dp[0][j][k],dp[0][j-1][k-a[i]]+b[i]);
            }
        }
        for(int j=1;j<=i;j++){
            for(int k=a[i];k<=sum[i];k++){
                dp[0][j][k] = dp[1][j][k];
            }
        }
    }
    for(int j=1;j<=n;j++){
        double ans = 0;
        for(int k=0;k<=sum[n];k++){
            ans = max(ans,min(1.0*k,1.0*(dp[0][j][k]+sumb)/2));
        }
        printf("%.10lf ",ans);
    }
    return 0;
}
