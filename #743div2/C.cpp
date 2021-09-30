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
vector<int> pre[maxn];
vector<int> v[maxn];
int book[maxn],dp[maxn],book2[maxn];
int ans,n;
bool flag;
void dfs(int now){
    if(!flag) return;
    if(book[now]) return;
    book[now] = 1;
    if(pre[now].size() == 0) dp[now] = 1;
    rep(i,0,pre[now].size()){
        int nxt = pre[now][i];
        if(book2[nxt]){
            flag = 0;
            return;
        }
        book2[nxt] = 1;
        dfs(nxt);
        book2[nxt] = 0;
        if(nxt < now) dp[now] = max(dp[now],dp[nxt]);
        else dp[now] = max(dp[now],dp[nxt]+1);
    }
}
int main(){
    IOS;
    int k,num;
    CAS {
        cin>>n;
        Rep(i,1,n) pre[i].clear();
        Rep(i,1,n) book[i] = dp[i] = 0;
        ans = 0;
        Rep(i,1,n){
            cin>>k;
            while(k--){
                cin>>num;
                pre[i].push_back(num);
                v[i].push_back(num);
                v[num].push_back(i);
            }
        }
        flag = 1;
        Rep(i,1,n){
            book2[i] = 1;
            dfs(i);
            book2[i] = 0;
        }
        Rep(i,1,n) if(!book[i]) flag = 0;
        Rep(i,1,n) ans = max(dp[i],ans);
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