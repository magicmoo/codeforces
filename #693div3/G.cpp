#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
vector<int> vec[maxn];
int book[maxn],ans[maxn],d[maxn];
int n,m,l,r;
void dfs(int now){
    if(book[now]){
        return;
    }
    book[now] = 1;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(d[now] >= d[nxt]) ans[now] = min(ans[now],d[nxt]);
        else{
            dfs(nxt);
            ans[now] = min(ans[now],ans[nxt]);
        }
    }
    return;
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        int now = q.front().first;
        int cost = q.front().second;
        q.pop();
        if(book[now]) continue;
        book[now] = 1;
        d[now] = cost;
        rep(i,0,vec[now].size()){
            int nxt = vec[now][i];
            q.push({nxt,cost+1});
        }
    }
    Rep(i,1,n) ans[i] = d[i];
}
int main(){
    IOS;
    CAS {
        cin>>n>>m;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n) d[i] = ans[i] = book[i] = 0;
        Rep(i,1,m){
            cin>>l>>r;
            vec[l].push_back(r);
        }
        bfs();
        Rep(i,1,n) book[i] = 0;
        dfs(1);
        Rep(i,1,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
