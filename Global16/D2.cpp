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
}a[maxn*maxn];
int n,m,book[maxn*maxn];
ll ans;
bool cmp(Node n1,Node n2){
    if(n1.s == n2.s) return n1.i<n2.i;
    return n1.s<n2.s;
}
int row(int now){
    return (now-1)/m+1;
}
void solve(int l,int r){
    if(row(l)==row(r)){
        int L = (row(l)-1)*m+1;
        int cnt = (l-1)-(row(l)-1)*m;
        Rep(j,l,r){
            rep(now,L,L+cnt){
                if(book[now] && book[now]<a[j].i) ans++;
            }
        }
        Rep(j,l,r){
            int now = l+(r-j);
            book[j] = a[now].i;
        }
    }else{
        int tr = row(l)*m;
        int L = (row(l)-1)*m+1;
        int cnt = (l-1)-(row(l)-1)*m;
        Rep(j,l,tr){
            rep(now,L,L+cnt){
                if(book[now]<a[j].i) ans++;
            }
        }
        int tl = (row(r)-1)*m+1;
        Rep(j,tl,r){
            int now = tl+(r-j);
            book[j] = a[now].i;
        }
    }
}
int main(){
    IOS;
    CAS {
        cin>>n>>m;
        Rep(i,1,n*m) cin>>a[i].s,a[i].i = i;
        Rep(i,1,n*m) book[i] = 0;
        sort(a+1,a+1+n*m,cmp);
        int l = 1;
        ans = 0;
        Rep(i,2,n*m){
            if(a[i].s==a[i-1].s) continue;
            int r = i-1;
            solve(l,r);
            l = i;
        }
        solve(l,n*m);
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