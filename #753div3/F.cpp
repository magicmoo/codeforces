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
int dp[maxn][maxn],book[maxn][maxn];
int wx[4] = {0,0,1,-1};
int wy[4] = {1,-1,0,0};
char fx[4] = {'R','L','D','U'};
int n,m,len;
void nxt(int& x,int& y){
    if(a[x][y]=='R') y++;
    else if(a[x][y]=='L') y--;
    else if(a[x][y]=='D') x++;
    else x--;
}
void dfs(){
    queue<pair<int,int>> q;
    Rep(i,1,n){
        Rep(j,1,m){
            q.push({i,j});
        }
    }
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();    
        if(dp[x][y]) continue;
        int tx=x,ty=y;
        int len = 0,sum = 0;
        int tempx = x,tempy = y;
        while(!book[tx][ty] && !dp[tx][ty]){
            if(tx<=0 || tx>n || ty<=0 || ty>m){
                break;
            }
            book[tx][ty] = ++len;
            tempx = tx,tempy = ty;
            nxt(tx,ty);
        }
        if(tx<=0 || tx>n || ty<=0 || ty>m){
            while(!(tx==x && ty==y)){
                book[x][y] = 0;
                dp[x][y] = len--;
                nxt(x,y);
            }
        }else if(dp[tx][ty]){
            book[tx][ty] = 0;
            while(!(tx==x && ty==y)){
                book[x][y] = 0;
                dp[x][y] = dp[tx][ty]+len--;
                nxt(x,y);
            }
        }else{
            int num = dp[tempx][tempy] = book[tempx][tempy]-book[tx][ty]+1;
            book[tempx][tempy] = 0;
            while(!(tx==tempx && ty==tempy)){
                book[tx][ty] = 0;
                dp[tx][ty] = num;
                nxt(tx,ty);
            }
            while(!dp[x][y]){
                book[x][y] = 0;
                dp[x][y] = len--;
                nxt(x,y);
            }
        }
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
        dfs();
        Rep(i,1,n){
            Rep(j,1,m){
                len = 0;
                if(dp[i][j] > d){
                    r = i; c = j;
                    d = dp[i][j];
                }
            }
        }
        cout<<r<<" "<<c<<" "<<d<<"\n";
    }
    return 0;
}
