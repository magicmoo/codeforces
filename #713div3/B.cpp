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
const int maxn = 405;
char a[maxn][maxn];
int main(){
    IOS;
    int n;
    CAS {
        int x1=0,x2=0,y1=0,y2=0;
        cin>>n;
        Rep(i,1,n){
            Rep(j,1,n){
                cin>>a[i][j];
                if(a[i][j] == '.') continue;
                if(x1==0) x1=i,y1=j;
                else x2=i,y2=j;
            }
        }
        if(x1==x2){
            if(x1==1) a[2][y1] = a[2][y2] = '*';
            else a[1][y1] = a[1][y2] = '*';
        }else if(y1==y2){
            if(y1==1) a[x1][2] = a[x2][2] = '*';
            else a[x1][1] = a[x2][1] = '*';
        }else a[x1][y2] = a[x2][y1] = '*';
        Rep(i,1,n){
            Rep(j,1,n){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
