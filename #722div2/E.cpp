#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5+5;
const int MAXN = maxn;
const int MAXPOW = 25;

struct LCA
{
    struct TO{ll id,v;};
    struct NODE
    {
        ll f,deep;
        vector<TO>to;
    };
    NODE node[MAXN];
    ll f2[MAXN][MAXPOW+5];

    void addEdge(int u,int v,int w,int flag)
    {
        node[u].to.push_back({v,w});
        if(flag==1) node[v].to.push_back({u,w});//双向
    }

    ll lca(ll a,ll b)
    {
        if(node[a].deep<node[b].deep)swap(a,b);
        for(ll i=MAXPOW;i>=0;i--)
            if(node[f2[a][i]].deep>=node[b].deep)
                a=f2[a][i];
        if(b==a) return b;
        for(ll i=MAXPOW;i>=0;i--)
            if(f2[b][i]!=f2[a][i])
                {a=f2[a][i];b=f2[b][i];}
        return (f2[b][0]==0)?b:f2[b][0];
    }

    ll dfs(ll x)//run dfs(root),before use lca(x,y);查询LCA前先跑一次dfs(root),预处理
    {
        for(auto& to:node[x].to){
            ll i=to.id,v=to.v;
            if(i==node[x].f)continue;
            node[i].f=x;
            node[i].deep=node[x].deep+1;
            f2[i][0]=x;
            for(ll j=1;j<=MAXPOW;j++){
                if(node[i].deep<(1<<j))break;
                f2[i][j]=f2[f2[i][j-1]][j-1];
            }
            dfs(i);
        }
        return 0;
    }
};
vector<int> vec1[maxn],vec2[maxn];
vector<int> v[maxn];
int sz[maxn],p[maxn],fa[maxn];
int tol;
void dfs1(int now,int last){
    sz[now] = 1;
    int Max = 0,Maxi = -1;
    for(int nxt : vec1[now]){
        if(nxt == last) continue;
        dfs1(nxt,now);
        sz[now] += sz[nxt];
        if(sz[nxt]>Max){
            Maxi = nxt;
            Max = sz[nxt];
        }
    }
    p[now] = Maxi;
}

int main(){
    IOS;
    int n,l,r;
    CAS {
        LCA a;
        tol = 0;
        cin>>n;
        Rep(i,1,n) v[i].clear();
        Rep(i,1,n-1){
            cin>>l>>r;
            vec1[l].push_back(r);
            vec1[r].push_back(l);
        }
        Rep(i,1,n-1){
            cin>>l>>r;
            vec2[l].push_back(r);
            vec2[r].push_back(l);
            a.addEdge(l,r,0,1);
        }
    }
    return 0;
}
