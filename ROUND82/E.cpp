#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 500;
char a[maxn],b[maxn];
int dp[2][maxn][maxn];
int main(){
    // IOS;
    CAS{
        scanf("%s %s",a+1,b+1);
        int n = strlen(a+1),m = strlen(b+1);
        memset(dp,0,sizeof(dp));
        bool flag = 0;
        Rep(i,1,m) dp[0][0][i] = i-1;
        Rep(now,1,n){
            Rep(i,0,m){
                Rep(j,max(1,i),m){
                    if(i>0 && a[now]==b[i]) dp[1][i][j] = max(dp[1][i][j],dp[0][i-1][j]);
                    if(dp[0][i][j]<m && a[now]==b[dp[0][i][j]+1]) dp[1][i][j] = max(dp[1][i][j],dp[0][i][j]+1);
                    dp[1][i][j] = max(dp[1][i][j],dp[0][i][j]);
                }
            }
            Rep(i,0,m){
                Rep(j,0,m){
                    dp[0][i][j] = dp[1][i][j];
                    dp[1][i][j] = 0;
                }
            }
        }
        Rep(i,1,m){
            if(dp[0][i-1][i]==m) flag = 1;
        }
        YON;
    }
    return 0;
}