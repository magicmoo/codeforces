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
const int maxn = 25;
char a[maxn][maxn];
int n,k,m;
bool flag;
bool check(int x,int y){
    if(x<=0 || x>n || y<=0 || y>m) return 0;
    return 1;
}
void solve(int x,int y){
    Rep(i,1,k){
        int tx = x-i;
        int ty1 = y-i,ty2 = y+i;
        if(!check(tx,ty1) || !check(tx,ty2) || a[tx][ty1]=='.' || a[tx][ty2]=='.') return;
    }
    a[x][y] = '!';
    Rep(i,1,k){
        int tx = x-i;
        int ty1 = y-i,ty2 = y+i;
        a[tx][ty1] = a[tx][ty2] = '!';
    }
    Rep(i,k+1,INF){
        int tx = x-i;
        int ty1 = y-i,ty2 = y+i;
        if(!check(tx,ty1) || !check(tx,ty2) || a[tx][ty1]=='.' || a[tx][ty2]=='.') return;
        a[tx][ty1] = a[tx][ty2] = '!';
    }
}
int main(){
    IOS;
    CAS {
        cin>>n>>m>>k;
        flag = 1;
        Rep(i,1,n) Rep(j,1,m) cin>>a[i][j];
        Rep(i,1,n){
            Rep(j,1,m){
                if(a[i][j] == '.') continue;
                solve(i,j);
            }
        }
        Rep(i,1,n){
            Rep(j,1,m){
                if(a[i][j] == '*') flag = 0;
            }
        }
        YON;
    }
    return 0;
}
