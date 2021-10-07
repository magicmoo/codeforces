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
const int maxn = 305;
char a[maxn][maxn];
int n;
bool check(int i,int j){
    if(j-2>0 && a[i][j-2]=='X' && a[i][j-1]=='X') return 1;
    if(j-1>0 && j+1<=n && a[i][j-1]=='X' && a[i][j+1]=='X') return 1;
    if(j+2<=n && a[i][j+1]=='X' && a[i][j+2]=='X') return 1;
    
    return 0;
}
int main(){
    IOS;
    CAS {
        cin>>n;
        Rep(i,1,n) Rep(j,1,n) cin>>a[i][j];
        Rep(i,1,n){
            for(int j=i%3;j<=n;j+=3){
                if(check(i,j)) a[i][j] = 'O';
            }
        }
        Rep(i,1,n){
            Rep(j,1,n){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
