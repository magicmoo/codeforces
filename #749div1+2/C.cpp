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
const int maxn = 1e6+5;
char a[maxn];
int dp[maxn];
int n,m;
int get(int x,int y){
    return (x-1)*m+y;
}
int wx[4] = {1,-1,0,0};
int yx[4] = {0,0,1,-1};
int dfs(int x,int y){
    if(dp[get(x,y)]) return dp[get(x,y)];
    if(y==1 || x==1) return dp[get(x,y)] = -1;
    int tmp = y;
    if(a[get(x-1,y)]=='.') tmp = min(tmp,dfs(x-1,y));
    if(a[get(x,y-1)]=='.') tmp = min(tmp,dfs(x,y-1));
    return dp[get(x,y)] = tmp;
}
namespace ST{
int a[maxn];
int maxsum[maxn][20],minsum[maxn][20];
void RMQ(int num){  //共num个数
    for(int i=1;i<=num;i++)
        maxsum[i][0] = minsum[i][0] = a[i];
    for(int j=1;j<20;j++){
        for(int i=1;i<=num;i++){
            if(i+(1<<j)-1 <= num){
                maxsum[i][j] = max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
                minsum[i][j] = min(minsum[i][j-1],minsum[i+(1<<(j-1))][j-1]);
            }
        }
    }
}
int maxl,minl;
void Query(int l,int r){
    int k = (int)(log(r-l+1)/log(2.0));
    maxl = max(maxsum[l][k],maxsum[r-(1<<k)+1][k]);
    minl = min(minsum[l][k],minsum[r-(1<<k)+1][k]);
}
}
int main(){
    IOS;
    cin>>n>>m;
    Rep(i,1,n){
        Rep(j,1,m){
            cin>>a[get(i,j)];
        }
    }
    dfs(1,3);
    Dep(i,n,1){
        Dep(j,m,1){
            if(!dp[get(i,j)]) dfs(i,j);
        }
    }
    Rep(i,1,n){
        Rep(j,1,m){
            ST::a[j] = max(ST::a[j],dp[get(i,j)]);
        }
    }
    ST::RMQ(m);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        ST::Query(l,r);
        if(ST::maxl > l) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
