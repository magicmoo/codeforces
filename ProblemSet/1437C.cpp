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
const int maxn = 205;
int a[maxn];
int dp[maxn][2*maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    CAS {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        for(int j=1;j<=2*n;j++) dp[1][j] = abs(a[1]-j);
        for(int i=2;i<=n;i++){
            int Min = INF;
            for(int j=i;j<=2*n;j++){
                Min = min(Min,dp[i-1][j-1]);
                dp[i][j] = Min+abs(a[i]-j);
            }
        }
        int ans = INF;
        for(int j=n;j<=2*n;j++){
            ans = min(ans,dp[n][j]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
