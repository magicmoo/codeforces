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
const int maxn = 4e5+5;
vector<int> v[maxn];
int dp[maxn],book[maxn];
int used[maxn];
void dfs1(int now){
    if(used[now]){
        dp[now] = -1;
        return;
    }
    if(book[now]){
        if(dp[now]!=-1) dp[now] = 2;
        return;
    }
    used[now] = book[now] = 1;
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        dfs1(nxt);
    }
    used[now] = 0;
}
void dfs2(int now,int num){
    if(book[now]) return;
    book[now] = 1;
    dp[now] = num;
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        dfs2(nxt,num);
    }
}
int main(){
    IOS;
    int n,m,l,r;
    CAS {
        cin>>n>>m;
        Rep(i,1,n) dp[i] = book[i] = 0;
        dp[1] = 1;
        Rep(i,1,n) v[i].clear();
        Rep(i,1,m){
            cin>>l>>r;
            v[l].push_back(r);
        }
        dfs1(1);
        Rep(i,1,n) book[i] = 0;
        Rep(i,1,n){
            if(dp[i]==-1) dfs2(i,dp[i]);
        }
        Rep(i,1,n){
            if(dp[i]==2) dfs2(i,dp[i]);
        }
        Rep(i,1,n){
            if(dp[i]==1) dfs2(i,dp[i]);
        }
        Rep(i,1,n) cout<<dp[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
