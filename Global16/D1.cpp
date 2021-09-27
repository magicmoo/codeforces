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
const int maxn = 305;
struct Node{
    int i,s;
}a[maxn];
bool cmp(Node n1,Node n2){
    if(n1.s==n2.s) return n1.i>n2.i;
    return n1.s<n2.s;
}
int book[maxn];
int main(){
    IOS;
    int n,m;
    CAS {
        cin>>n>>m;
        Rep(i,1,n*m) cin>>a[i].s,a[i].i = i;
        sort(a+1,a+m+1,cmp);
        ll ans = 0;
        Rep(i,1,m) book[i] = 0;
        Rep(now,1,m){
            int x = 0;
            Rep(i,1,m){
                if(a[i].i==now){
                    x = i;
                    break;
                }
            }
            rep(i,1,x){
                if(book[i]) ans++;
            }
            book[x] = 1;
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