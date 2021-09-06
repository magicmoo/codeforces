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

int dp[maxn];
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        int ans = 0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=n;i>0;i--){
            if(a[i]+i <= n) dp[i] = dp[a[i]+i]+a[i];
            else dp[i] = a[i];
            ans = max(dp[i],ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
