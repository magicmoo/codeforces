#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll maxn = 505;
const ll mod = 998244353;
struct Node{
    char ch;
    ll num;
}a[maxn];
ll dp[maxn][maxn];
int main(){
    IOS;
    ll n;
    cin>>n;
    Rep(i,1,n){
        cin>>a[i].ch;
        if(a[i].ch == '+') cin>>a[i].num;
    }
    ll ans = 0;
    Rep(I,1,n){
        if(a[I].ch == '-') continue;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        Rep(i,1,n){
            Rep(j,0,i){
                if(i == I) dp[i][j] = dp[i-1][j];
                else if(a[i].ch == '-'){
                    if(j==0 && i<I) dp[i][j] = (dp[i-1][j]*2+dp[i-1][j+1])%mod;
                    else dp[i][j] = (dp[i-1][j+1]+dp[i-1][j])%mod;
                }else{
                    if(a[i].num<a[I].num || (a[i].num==a[I].num && i<I)) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
                    else dp[i][j] = (dp[i-1][j]*2)%mod;
                }
            }
        }
        ll temp = 0;
        Rep(j,0,n) temp += dp[n][j],temp %= mod;
        ans += temp*(a[I].num%mod);
        ans %= mod;
    }
    cout<<ans<<"\n";
    return 0;
}

//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑      永无bug