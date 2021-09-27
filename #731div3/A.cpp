#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CAS int CASE; \
            cin>>CASE; \
            while(CASE--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int INF = 0x3f3f3f3f;

int main(){
    IOS;
    int xa,ya,xb,yb,xf,yf;
    CAS {
        cin>>xa>>ya; cin>>xb>>yb; cin>>xf>>yf;
        if(xa == xb){
            if(xf == xa && yf<max(ya,yb) && yf>min(ya,yb)) cout<<2+(max(ya,yb)-min(ya,yb))<<"\n";
            else cout<<max(ya,yb)-min(ya,yb)<<"\n";
        }else if(ya == yb){
            if(yf == ya && xf<max(xa,xb) && xf>min(xa,xb)) cout<<2+(max(xa,xb)-min(xa,xb))<<"\n";
            else cout<<max(xa,xb)-min(xa,xb)<<"\n";
        }else{
            cout<<( max(xa,xb)-min(xa,xb)+ max(ya,yb)-min(ya,yb) )<<"\n";
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