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
const int maxn = 2e5+5;
vector<int> nxt[maxn];
int book[maxn],dis[maxn];
int ans,n;
struct Node{
    int now,len;
};
void bfs(){
    queue<Node> q;
    Rep(i,1,n) q.push({i,1});
    while(!q.empty()){
        int now = q.front().now;
        int len = q.front().len;
        q.pop();
        if(book[now] || dis[now]) continue;
        book[now] = 1;
        ans = max(ans,len);
        rep(i,0,nxt[now].size()){
            int NEXT = nxt[now][i];
            dis[NEXT]--;
            q.push({NEXT,len+1});
        }
    }
}
int main(){
    IOS;
    int k,num;
    CAS {
        cin>>n;
        Rep(i,1,n) nxt[i].clear();
        Rep(i,1,n) book[i] = 0;
        ans = 0;
        Rep(i,1,n){
            cin>>k;
            dis[i] = k;
            while(k--){
                cin>>num;
                nxt[num].push_back(i);
            }
        }
        bfs();
        bool flag = 1;
        Rep(i,1,n) if(!book[i]) flag = 0;
        if(flag) cout<<ans<<"\n";
        else cout<<"-1\n";
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