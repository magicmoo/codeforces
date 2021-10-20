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
char a[5][maxn];
int dp[5][maxn];
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,2){
            Rep(j,1,n){
                cin>>a[i][j];
                dp[i][j] = 0;
            }
        }
        dp[1][1] = 1;
        Rep(j,1,n){
            Rep(i,1,2){
                if(a[i][j] == '1') continue;
                if(dp[1][j-1] || dp[2][j-1]) dp[i][j] = 1;
            }
        }
        if(dp[2][n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
