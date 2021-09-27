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
 
int main(){
    IOS;
    ll s,n;
    CAS {
        cin>>s>>n;
        ll ss = s;
        ll sum = 0;
        ll tmp = s;
        while(tmp){
            sum += tmp%10;
            tmp /= 10;
        }
        if(sum >= n){
            ll cnt = 1;
            Rep(i,1,n-1){
                while(s && s/cnt%10 == 0) cnt *= 10;
                cout<<cnt<<" ";
                s -= cnt;
            }
            cout<<s<<"\n";
        }else{
            vector<ll> ans;
            ll now = 1,last = n;
            ll cnt = 1;
            Rep(i,1,n-1){
                while(s && s/cnt%10 == 0) cnt *= 10;
                if(s == 0) break;
                ans.push_back(cnt);
                s -= cnt;
                last--;
            }
            rep(i,0,ans.size()){
                if(!last) break;
                if(ans[i] > 1){
                    if(last >= 9){
                        last -= 9;
                        rep(j,0,9) ans.push_back(ans[i]/10);
                        ans[i] = ans[i]/10;
                        sort(ans.begin(),ans.end());
                        i = -1;
                    }else{
                        rep(j,0,last) ans.push_back(ans[i]/10);
                        ans[i] = (10-last)*ans[i]/10;
                        break;
                    }
                }
            }
            sort(ans.begin(),ans.end());
            rep(i,0,n) cout<<ans[i]<<" ";
            cout<<"\n";
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
//             佛祖保佑      永无bug