#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<ll,ll>
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 2e18;
const ll maxn = 1e5+5;
const ll MAXN = maxn;
using namespace std;

struct Dijkstra
{
    struct EDGE
    {
        ll id,v;
    };
    struct Int
    {
        ll id,dis;
        bool operator <(const Int&b)const{
            return dis>b.dis;
        }
    };

    priority_queue<Int>q;
    list<EDGE>node[MAXN];
    ll dis[MAXN];
    ll vis[MAXN];

    void init(ll n){
        for(ll i=1;i<=n;i++){dis[i]=INF;}
    }
    void add(ll u,ll v,ll w){
        node[u].push_back({v,w});
    }
    void dijkstra(ll s){
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

ll n,m,s,x,y,z;
Dijkstra dj;
struct Node{
    ll x,y,id;
}a[maxn];
bool cmp1(Node n1,Node n2){
    return n1.x<n2.x;
}
bool cmp2(Node n1,Node n2){
    return n1.y<n2.y;
}
int main(){
    IOS;
    ll n,m,sx,sy,fx,fy;
    cin>>n>>m;
    cin>>sx>>sy>>fx>>fy;
    Rep(i,1,m){
        cin>>a[i].x>>a[i].y;
        a[i].id = i;
    }
    dj.init(m+2);
    Rep(i,1,m){
        ll len = min(abs(sx-a[i].x),abs(sy-a[i].y));
        dj.add(m+1,i,len);
        len = abs(fx-a[i].x)+abs(fy-a[i].y);
        dj.add(i,m+2,len);
    }
    dj.add(m+1,m+2,abs(fx-sx)+abs(fy-sy));
    sort(a+1,a+1+m,cmp1);
    Rep(i,2,m){
        dj.add(a[i-1].id,a[i].id,a[i].x-a[i-1].x);
        dj.add(a[i].id,a[i-1].id,a[i].x-a[i-1].x);
    }
    sort(a+1,a+1+m,cmp2);
    Rep(i,2,m){
        dj.add(a[i-1].id,a[i].id,a[i].y-a[i-1].y);
        dj.add(a[i].id,a[i-1].id,a[i].y-a[i-1].y);
    }
    dj.dijkstra(m+1);
    cout<<dj.dis[m+2]<<"\n";
    return 0;
}
