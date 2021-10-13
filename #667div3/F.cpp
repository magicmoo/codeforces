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
const int maxn = 205;
char a[maxn];
char ch1,ch2;
int dp[maxn][maxn][maxn];
int main(){
    // IOS;
    int n,K;
    scanf("%d%d",&n,&K);
    scanf("%s",a+1);
    getchar();
    scanf("%c%c",&ch1,&ch2);
    if(ch1 == ch2){
        int cnt = 0;
        Rep(i,1,n) if(a[i]==ch1) cnt++;
        cnt = min(n,cnt+K);
        cout<<cnt*(cnt-1)/2;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;
    Rep(i,1,n){
        dp[i][0][0] = dp[i-1][0][0];
        Rep(j,1,i){
            if(a[i]==ch1) dp[i][j][0] = dp[i-1][j-1][0];
            else if(a[i]==ch2 && dp[i-1][j][0]>=0) dp[i][j][0] = dp[i-1][j][0]+j;
            else dp[i][j][0] = dp[i-1][j][0];
            Rep(k,1,min(i,K)){
                if(a[i]==ch2 && dp[i-1][j][k]>=0) dp[i][j][k] = dp[i-1][j][k]+j;
                else if(a[i]==ch1) dp[i][j][k] = dp[i-1][j-1][k];
                else dp[i][j][k] = dp[i-1][j][k];
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-1]);
                if(dp[i-1][j][k-1]>=0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+j);
            }
        }
    }
    int ans = 0;
    Rep(j,1,n){
        Rep(k,0,K){
            ans = max(ans,dp[n][j][k]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
