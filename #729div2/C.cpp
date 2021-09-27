#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;
const ll mod = 1e9+7;
ll num[1000];
int main(){
    IOS;
    ll n;
    ll now = 1,cnt = 3;
    while(now <= 1e16){
        ll temp = (cnt%2==0)?cnt/2:cnt;
        now = now/__gcd(now,temp)*temp;
        num[cnt++] = now;
    }
    CAS {
        cin>>n;
        ll ans = 5*(n/2);
        if(n%2) ans+=2;
        ans %= mod;
        n /= 2;
        for(ll i=3;i<cnt;i++){
            ans += n/num[i];
            ans %= mod;
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
//             ·ð×æ±£ÓÓ       ÓÀÎÞBUG