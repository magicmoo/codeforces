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
const int maxn = 1e5+5;
const int maxv = 1e3+5;
int a[maxn],book[maxn];
int dp[maxn][maxv];
int main(){
    // IOS;
    int n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    book[0] = 1;
    dp[0][0] = 0;
    Rep(i,1,1000) dp[0][i] = INF;
    Rep(i,1,n){
        Rep(j,0,1000) dp[i][j] = INF;
        Rep(j,0,1000){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            if(dp[i-1][j]>=a[i]) continue;
            dp[i][j^a[i]] = min(dp[i][j^a[i]],a[i]);
            book[j^a[i]] = 1;
        }
    }
    int cnt = 0;
    Rep(i,0,1000){
        if(book[i]) cnt++;
    }
    cout<<cnt<<"\n";
    Rep(i,0,1000){
        if(book[i]) cout<<i<<" ";
    }
    return 0;
}
