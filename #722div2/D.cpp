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
const ll mod = 998244353;
const ll maxn = 1e6+5;
ll dp[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,sum = 0,j;
    cin>>n;
    dp[1] = 1;
    for(ll i=2;i<=n;i++){
        sum += dp[i-1];
        dp[i] += sum + 2;
        sum%=mod; dp[i]%=mod;
        for(int j=i*2;j<=n;j+=i){
            dp[j]++;
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}
