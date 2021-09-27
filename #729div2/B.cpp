#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS ll CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll INF = 0x3f3f3f3f;

int main(){
    IOS;
    ll a,b,n;
    CAS {
        cin>>n>>a>>b;
        if(a == 1){
            if((n-1)%b == 0) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            ll now = 1;
            bool flag = false;
            while(!flag && now<=n){
                if((n-now)%b == 0) flag = true;
                now *= a;
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
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