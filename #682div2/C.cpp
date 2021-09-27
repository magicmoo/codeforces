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
const int maxn = 105;
int a[maxn][maxn];
int main(){
    IOS;
    int n,m;
    CAS {
        cin>>n>>m;
        Rep(i,1,n) Rep(j,1,m) cin>>a[i][j];
        Rep(i,1,n){
            Rep(j,1,m){
                if(i%2!=j%2 && a[i][j]%2==1) a[i][j]++;
                else if(i%2==j%2 && a[i][j]%2==0) a[i][j]++;
            }
        }
        Rep(i,1,n){
            Rep(j,1,m){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
