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
const int maxn = 2e5+5;
const int maxv = 1e3; //注意修改maxv数值
int vis[maxv],prime[maxv],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxv;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(int j=0;j<tol&&i*prime[j]<maxv;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
int a[maxn],book[maxn],dp[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,Max,Min;
    // liner_shai();
    cin>>T; while(T--){
        cin>>n;
        Max = 0,Min = INF;
        memset(book,0,sizeof(book));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){ cin>>a[i]; Max = max(Max,a[i]); Min = min(Min,a[i]); }
        for(int i=1;i<=n;i++) book[a[i]]++;
        int ans = 0;
        // for(int i=Min;i<=Max;i++){
        //     dp[i] = dp[1];
        //     for(int j=0;j<tol&&prime[j]*prime[j]<=i;j++){
        //         if(i%prime[j] == 0){
        //             dp[i] = max(dp[i],dp[i/prime[j]]);
        //             dp[i] = max(dp[i],dp[prime[j]]);
        //         }
        //     }
        //     dp[i] += book[i];
        //     ans = max(dp[i],ans);
        // }
        for(int i=1;i<=Max;i++){
            dp[i] += book[i];
            for(int j=i*2;j<=Max;j+=i){
                dp[j] = max(dp[j],dp[i]);
            }
            ans = max(ans,dp[i]);
        }
        cout<<n-ans<<"\n";
    }
    return 0;
}
