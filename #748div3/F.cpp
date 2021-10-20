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
const int maxn = 45;
int dp[maxn][maxn][maxn][maxn];
int pre[maxn][maxn][maxn][maxn];
struct Node{
    int i,j,k1,k2;
}pre2[maxn][maxn][maxn][maxn];
ll quick_pow(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1) ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }  
    return ans;
}
int main(){
    IOS;
    int n,A,B;
    string str;
    CAS {
        int ans = INF;
        string s;
        cin>>n>>A>>B;
        cin>>str;
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0] = 1;
        rep(i,0,n){
            Rep(j,0,i){
                rep(k1,0,A){
                    rep(k2,0,B){
                        if(dp[i][j][k1][k2]==0) continue;
                        dp[i+1][j+1][(k1*10+(str[i]-'0'))%A][k2] = 1;
                        pre[i+1][j+1][(k1*10+(str[i]-'0'))%A][k2] = 1;
                        pre2[i+1][j+1][(k1*10+(str[i]-'0'))%A][k2] = {i,j,k1,k2};
                        dp[i+1][j][k1][(k2*10+(str[i]-'0'))%B] = 1;
                        pre[i+1][j][k1][(k2*10+(str[i]-'0'))%B] = 0;
                        pre2[i+1][j][k1][(k2*10+(str[i]-'0'))%B] = {i,j,k1,k2};
                    }
                }
            }
        }
        Rep(a,1,n-1){
            if(dp[n][a][0][0]==1 && ans>(abs(n-2*a))){
                ans = abs(n-2*a);
                s = "";
                int j=a,k1=0,k2=0;
                Dep(i,n,1){
                    if(pre[i][j][k1][k2]) s = "R"+s;
                    else s = "B"+s;
                    int jj = pre2[i][j][k1][k2].j;
                    int kk1 = pre2[i][j][k1][k2].k1;
                    int kk2 = pre2[i][j][k1][k2].k2;
                    j = jj; k1 = kk1; k2 = kk2;
                }
            }
        }
        if(ans==INF) cout<<"-1\n";
        else cout<<s<<"\n";
    }
    return 0;
}
