#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 5e2+5;
char a[maxn][maxn];
int main(){
    IOS;
    int n,m;
    CAS {
        cin>>n>>m;
        Rep(i,1,n){
            Rep(j,1,m){
                cin>>a[i][j];
            }
        }
        Rep(i,1,n){
            for(int j=2;j<=m;j+=3){
                a[i][j] = 'X';
            }
        }
        for(int j=2;j<m-1;j+=3){
            bool flag = 0;
            Rep(i,1,n){
                if(a[i][j+1]=='X' || a[i][j+2]=='X'){
                    flag = 1;
                    a[i][j+1] = a[i][j+2] = 'X';
                    break;
                }
            }
            if(!flag){
                a[1][j+1] = a[1][j+2] = 'X';
            }
        }
        if(m==1){
            Rep(i,1,n) a[i][1] = 'X';
        }else if(m%3==1){
            Rep(i,1,n){
                if(a[i][m]=='X') a[i][m-1] = 'X';
            }
        }
        Rep(i,1,n){
            Rep(j,1,m){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
