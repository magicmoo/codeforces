#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
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
const int maxn = 2e3+5;
char a[maxn][maxn];
int dp[maxn][maxn];
pair<int,int> st[maxn][maxn];
int wx[4] = {0,0,1,-1};
int wy[4] = {1,-1,0,0};
char fx[4] = {'R','L','D','U'};
int n,m;
void dfs(int x,int y,int lx,int ly,int len){
    if(dp[x][y]) return;
    dp[x][y] = 1;
    st[x][y] = {0,0};
    int tx=x,ty=y;
    if(a[x][y]=='R') ty++;
    else if(a[x][y]=='L') ty--;
    else if(a[x][y]=='D') tx++;
    else tx--;
    if(tx<=0 || tx>n || ty<=0 || ty>m){
        st[x][y] = {x,y};
        dp[x][y] = len;
        return;
    }
    if(dp[tx][ty]){
        if(st[tx][ty]==make_pair(0,0)){
            st[x][y] = {lx,ly};
            dp[x][y] = len;
        }else{
            st[x][y] = st[tx][ty];
            dp[x][y] = 1+dp[tx][ty];
        }
        return;
    }
    dfs(tx,ty,x,y,len+1);
    if(st[tx][ty]==make_pair(x,y)){
        st[x][y] = {lx,ly};
        dp[x][y] = len;
    }else{
        st[x][y] = st[tx][ty];
        dp[x][y] = 1+dp[tx][ty];
    }
}
int main(){
    IOS;
    CAS {
        cin>>n>>m;
        Rep(i,1,n){
            Rep(j,1,m){
                cin>>a[i][j];
                dp[i][j] = 0;
            }
        }
        int r,c,d = 0;
        Rep(i,1,n){
            Rep(j,1,m){
                dfs(i,j,0,0,1);
                if(dp[i][j] > d){
                    r = st[i][j].first; c = st[i][j].second;
                    d = dp[i][j];
                }
            }
        }
        cout<<r<<" "<<c<<" "<<d<<"\n";
    }
    return 0;
}
