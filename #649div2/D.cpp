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
const int maxn = 1e5+5;
const int MAXN = maxn;
vector<int> vec[maxn];
int book[maxn];
int n,m,k;
vector<int> v;
void dfs(int now,int last,int sign){
    if(book[sign] != 0) return;
    book[now] = sign;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(nxt==last) continue;
        dfs(nxt,now,-sign);
    }
}
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
    list<EDGE>node[MAXN];
    int dis[MAXN];
    int vis[MAXN];
    int last[MAXN];

    void init(int n){
        for(int i=1;i<=n;i++){dis[i]=INF;}
    }
    void add(int u,int v,int w){
        node[u].push_back({v,w});
    }
    void dijkstra(int s){
        q.push({s,0});
        while(!q.empty())
        {
            Int now=q.top();q.pop();
            if(vis[now.id])continue;
            vis[now.id]=1;
            for(auto& to:node[now.id]){
                if((now.id==s ? 0 : dis[now.id])+to.v<dis[to.id]){
                    last[to.id] = now.id;
                    dis[to.id]=(now.id==s ? 0 : dis[now.id])+to.v;
                    q.push({to.id,dis[to.id]});
                }
            }
        }
        v.push_back(s);
        int now = last[s];
        while(now != s){
            v.push_back(now);
            now = last[now];
        }
    }

};
int first;
void dfs2(int now,int last){
    if(book[now]){
        first = now;
        return;
    }
    book[now] = 1;
    rep(i,0,vec[now].size()){
        if(first) return;
        int nxt = vec[now][i];
        if(nxt==last) continue;
        dfs2(nxt,now);
    }
}
Dijkstra d;
int main(){
    IOS;
    int l,r;
    cin>>n>>m>>k;
    Rep(i,1,m){
        cin>>l>>r;
        vec[l].push_back(r);
        vec[r].push_back(l);
        d.add(l,r,1);
        d.add(r,l,1);
    }
    if(m==n-1){
        dfs(1,-1,1);
        int cnt = 0;
        Rep(i,1,n){
            if(book[i]==1) cnt++;
        }
        cout<<"1\n";
        if(cnt>=(k+1)/2){
            Rep(i,1,n){
                if(k==0) break;
                if(book[i]==1){
                    cout<<i<<" ";
                    k--;
                }
            }
        }else{
            Rep(i,1,n){
                if(k==0) break;
                if(book[i]==0){
                    cout<<i<<" ";
                    k--;
                }
            }
        }
    }else{
        dfs2(1,-1);
        d.init(n);
        d.dijkstra(first);
        memset(book,0,sizeof(book));
        if(v.size() <= k){
            cout<<"2\n";
            cout<<v.size()<<"\n";
            for(int val : v){
                cout<<val<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"1\n";
            for(int i=0;i<v.size();i+=2){
                if(k<=0) break;
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
