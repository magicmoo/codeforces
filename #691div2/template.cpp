#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;

int n,m,t;
int a[maxn],b[maxn];
int dp[2][110][10010];
int suma[maxn],sumb;
int main(){
    #ifndef ONLINE_JUDGE
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        suma[i]=suma[i-1]+a[i];
        sumb+=b[i];
    }
    int now=0;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        now^=1;
        for(int j=0;j<=i;j++){
            for(int k=0;k<=suma[i];k++){
                dp[now][j][k]=dp[now^1][j][k];
            }
        }
        for(int j=1;j<=i;j++){
            for(int k=a[i];k<=suma[i];k++){
                dp[now][j][k]=max(dp[now][j][k],dp[now^1][j-1][k-a[i]]+b[i]);
            }
        }
    }
    int ans=0;
    for(int j=1;j<=n;j++){
        ans=0;
        for(int k=0;k<=suma[n];k++){
            ans=max(ans,min(dp[now][j][k]+sumb,2*k));
        }
        printf("%.10f%c",1.0*ans/2,j==n?'\n':' ');
    }
    return 0;
}