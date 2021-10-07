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
const int maxn = 1e3+5;
vector<int> vec[maxn];
struct Dijkstra
{
    struct EDGE
    {
        int id,v;
    };
    struct Int
    {
        int id,dis;
        bool operator <(const Int&b)const{
            return dis>b.dis;
        }
    };

    priority_queue<Int>q;
    list<EDGE>node[maxn];
    int dis[maxn];
    int vis[maxn];

    void init(int n){
        Rep(i,1,n){dis[i]=INF;}
        Rep(i,1,n) vis[i] = 0;
        while(!q.empty()) q.pop();
    }
    void add(int u,int v,int w){
        node[u].push_back({v,w});
        node[v].push_back({u,w});
    }
    void dijkstra(int s){
        dis[s]=0;
        q.push({s,0});
        while(!q.empty())
        {
            Int now=q.top();q.pop();
            if(vis[now.id])continue;
            vis[now.id]=1;
            for(auto& to:node[now.id]){
                if(dis[now.id]+to.v<dis[to.id]){
                    dis[to.id]=dis[now.id]+to.v;
                    q.push({to.id,dis[to.id]});
                }
            }
        }
    }

};
Dijkstra a;
struct Node{
    int l,r,w;
}e[maxn];
pair<int,int> b[maxn];
int dis[maxn][maxn];
int main(){
    IOS;
    int n,m,k,l,r,w;
    cin>>n>>m>>k;
    Rep(i,1,m){
        cin>>l>>r>>w;
        e[i] = {l,r,w};
        a.add(l,r,w);
    }
    Rep(i,1,k) cin>>b[i].first>>b[i].second;
    Rep(i,1,n){
        a.init(n);
        a.dijkstra(i);
        Rep(j,1,n) dis[i][j] = a.dis[j];
    }
    int ans = INF;
    Rep(i,1,m){
        int tmp = 0;
        int u = e[i].l;
        int v = e[i].r;
        Rep(j,1,k){
            l = b[j].first; r = b[j].second;
            tmp += min(dis[l][r],min(dis[l][u]+dis[v][r],dis[l][v]+dis[u][r]));
        }
        ans = min(ans,tmp);
    }
    cout<<ans<<"\n";
    return 0;
}
