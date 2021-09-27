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
const ll INF = 2e18;
const ll maxn = 2e5+5;
ll a[maxn],pre[maxn];
int main(){
    IOS;
    ll n,m,x,y;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    Rep(i,1,n) pre[i] = pre[i-1]+a[i];
    ll sum = 0;
    Rep(i,1,n) sum += a[i];
    cin>>m;
    while(m--){
        cin>>x>>y;
        ll index = lower_bound(a+1,a+1+n,x)-a;
        ll ans = INF;
        if(index <= n){
            ll last = sum-a[index];
            if(last>=y) ans = 0;
            else ans = y-last;
        }
        if(index>1){
            ll tmp = x-a[index-1];
            ll last = sum-a[index-1];
            if(last<y) tmp += y-last;
            ans = min(tmp,ans);
        }
        cout<<ans<<"\n";
    }
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