#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int a[maxn],n;
int main(){
    IOS;
    CAS {
        cin>>n;
        vector<int> v;
        for(int i=1;i<=n;i++) cin>>a[i];
        int Min = INF,Max = -INF;
        for(int i=1;i<=n;i++){
            Min = min(Min,a[i]);
            Max = max(Max,a[i]);
        }
        if(Min<0) cout<<"NO\n";
        else{
            cout<<"YES\n";
            cout<<Max+1<<"\n";
            for(int i=0;i<=Max;i++) cout<<i<<" ";
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
//             佛祖保佑       永无BUG