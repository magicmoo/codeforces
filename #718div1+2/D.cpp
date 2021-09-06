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
const int maxn = 505;
int a[maxn][maxn],b[maxn][maxn],dp[maxn][maxn][30],n,m,k;
bool check(int x,int y){
    if(x<=0 || x>n || y<=0 || y>m) return 0;
    return 1;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    if(k%2 == 1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<"-1 ";
            }
            cout<<"\n";
        }
        return 0;
    }
    for(int len=1;len<=(k/2);len++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int temp = INF;
                if(check(i-1,j)) temp = min(temp,dp[i-1][j][len-1]+b[i-1][j]);
                if(check(i+1,j)) temp = min(temp,dp[i+1][j][len-1]+b[i][j]);
                if(check(i,j-1)) temp = min(temp,dp[i][j-1][len-1]+a[i][j-1]);
                if(check(i,j+1)) temp = min(temp,dp[i][j+1][len-1]+a[i][j]);
                dp[i][j][len] = temp;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dp[i][j][k/2]*2<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
