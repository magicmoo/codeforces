#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
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
const int maxn = 1e5+5;
const int maxv = 1e6+5;
int a[maxn],cnt[maxv][20][2];
int sz[maxn],son[maxn];
ll ans;
vector<int> vec[maxn];
void dfs1(int now,int last){
    sz[now] = 1;
    int Max = 0;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        dfs1(nxt,now);
        sz[now] += sz[nxt];
        if(sz[nxt]>Max){
            son[now] = nxt;
            Max = sz[nxt];
        }
    }   
}
void update(int now,int last,int LCA){
    int num = a[now]^a[LCA];
    if(num <= 1e6){
        rep(i,0,20){
            if(((now>>i)&1)==0) ans+=(1LL<<i)*cnt[num][i][1];
            else ans+=(1LL<<i)*(cnt[num][i][0]);
        }
    }
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        update(nxt,now,LCA);
    }
}
void add(int now,int last,int mul){
    rep(i,0,20){
        cnt[a[now]][i][(now>>i)&1] += mul;
    }
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        add(nxt,now,mul);
    }
}
void dfs(int now,int last,int keep){
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last || nxt==son[now]) continue;
        dfs(nxt,now,0);
    }
    if(son[now]) dfs(son[now],now,1);
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last || nxt==son[now]) continue;
        update(nxt,now,now);
        add(nxt,now,1);
    }
    rep(i,0,20){
        cnt[a[now]][i][(now>>i)&1]++;
    }
    if(!keep){
        add(now,last,-1);
    }
}
int main(){
    IOS;
    int n,l,r;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n-1){
        cin>>l>>r;
        vec[l].push_back(r);
        vec[r].push_back(l);
    }
    dfs1(1,-1);
    dfs(1,-1,1);
    cout<<ans<<"\n";
    return 0;
}
