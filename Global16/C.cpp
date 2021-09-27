#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            Rep(__,1,CASE)
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int a[maxn],b[maxn];
int main(){
    // IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) scanf("%1d",&a[i]);
        Rep(i,1,n) scanf("%1d",&b[i]);
        int cnt0 = 0,cnt1 = 0;
        int ans = 0;
        Rep(i,1,n){
            if(a[i]+b[i]==1){
                if(cnt0) ans++;
                cnt0 = cnt1 = 0;
                ans += 2;
            }else if(a[i]+b[i]==2){
                if(cnt0){
                    cnt0 = cnt1 = 0;
                    ans += 2;
                }else cnt1 = 1;
            }else{
                if(cnt1){
                    ans += 2;
                    cnt0 = cnt1 = 0;
                }else{
                    if(cnt0) ans++;
                    else cnt0 = 1;
                }
            }
        }
        if(cnt0) ans++;
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