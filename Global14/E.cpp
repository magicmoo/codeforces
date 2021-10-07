#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll maxn = 405;
ll dp[maxn][maxn];
ll cnt[maxn];
ll n,m;
const ll maxv = maxn;
ll C[maxv][maxv];   
void init(){
	for(ll i=0;i<maxv;i++) C[i][0]=1;
	for(ll i=1;i<maxv;i++)
	    for(ll j=1;j<maxv;j++)
	        C[i][j] = (C[i-1][j]+C[i-1][j-1])%m;
}
int main(){
    IOS;
    cin>>n>>m;
    cnt[0] = 1;
    init();
    Rep(i,1,n){
        cnt[i] = (cnt[i-1]*2)%m;
    }
    dp[1][1] = 1;
    Rep(i,2,n){
        dp[i][i] = cnt[i-1];
        Rep(j,1,i){
            Rep(k,1,j-1){
                if(i-k-1 >= j-k) dp[i][j] += (dp[i-k-1][j-k]*cnt[k-1]%m*C[j][k])%m;
                dp[i][j] %= m;
            }
        }
    }
    ll ans = 0;
    Rep(i,1,n){
        ans += dp[n][i];
        ans %= m;
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