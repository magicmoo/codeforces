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
const int maxn = 105;
int a[maxn],n,dp[maxn*2000];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum = 0;
    for(int i=1;i<=n;i++) sum += a[i];
    if(sum%2==1){
        cout<<"0\n";
    }else{
        dp[0] = 1;
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.clear();
            for(int j=0;j<=sum/2;j++){
                if(dp[j]) v.push_back(j+a[i]);
            }
            for(int i=0;i<v.size();i++) dp[v[i]] = 1;
        }
        if(dp[sum/2] == 0) cout<<"0\n";
        else {
            cout<<"1\n";
            while(1){
                for(int i=1;i<=n;i++){
                    if(a[i]%2 == 1){
                        cout<<i<<"\n";
                        return 0;
                    }
                    a[i] /= 2;
                }
            }
        }
    }
    return 0;
}
