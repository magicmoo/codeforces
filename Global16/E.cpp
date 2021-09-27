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
int dp[maxn];
vector<int> v[maxn];
int ans;
void dfs1(int now,int last){
    if(v[now].size()==1 && now!=1){
        ans++;
        return;
    }
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(nxt==last) continue;
        dfs1(nxt,now);
    }
}
void dfs(int now,int last){
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(nxt==last) continue;
        dfs(nxt,now);
    }
    dp[now] = 1;
    int cnt = 0;
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(nxt==last) continue;
        if(dp[nxt]==1){
            dp[now] = 0;
        }else ans--;
        cnt++;
    }
    if(dp[now] && cnt) ans++;
}
int main(){
    IOS;
    int n,l,r;
    CAS {
        cin>>n;
        ans = 0;
        Rep(i,1,n) v[i].clear(),dp[i] = 0;
        Rep(i,1,n-1){
            cin>>l>>r;
            v[l].push_back(r);
            v[r].push_back(l);
        }
        dfs1(1,-1);
        dfs(1,-1);
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