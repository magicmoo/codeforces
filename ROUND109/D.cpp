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
const int maxn = 5005;
int a[maxn];
vector<int> v0,v1;
int dp[maxn][maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    v0.push_back(0); v1.push_back(0);
    for(int i=1;i<=n;i++){
        if(a[i]) v1.push_back(i);
        else v0.push_back(i);
    }
    int ans = INF;
    for(int i=1;i<v1.size();i++){
        int tmp = INF;
        for(int j=i;j<v0.size();j++){
            tmp = min(tmp,dp[i-1][j-1]);
            dp[i][j] = tmp + abs(v0[j]-v1[i]);
            if(i==v1.size()-1) ans = min(dp[i][j],ans);
        }
    }
    if(ans != INF)cout<<ans;
    else cout<<"0";
    return 0;
}
