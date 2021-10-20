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
const int maxn = 3e5+5;
vector<int> vec[maxn],v[maxn],odd;
int cnt[maxn],book[maxn];
int a[maxn],b[maxn];
void dfs(int now){
    book[now] = 1;
    rep(i,0,vec[now].size()){
        int nxt = vec[now][i];
        if(book[nxt]) continue;
        v[now].push_back(nxt);
        v[nxt].push_back(now);
        dfs(nxt);
    }
}
bool flag;
void dfs(int now,int last,int ed,vector<int>& road){
    if(now == ed){
        flag = 1;
        return;
    }
    rep(i,0,v[now].size()){
        int nxt = v[now][i];
        if(nxt == last) continue;
        road.push_back(nxt);
        dfs(nxt,now,ed,road);
        if(flag) return;
        road.pop_back();
    }
}
int main(){
    IOS;
    int n,m,x,y,q;
    cin>>n>>m;
    Rep(i,1,m){
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cin>>q;
    Rep(i,1,q){
        cin>>a[i]>>b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    Rep(i,1,n){
        if(cnt[i]%2==1) odd.push_back(i);
    }
    if(odd.size() == 0){
        cout<<"YES\n";
        dfs(1);
        vector<int> road;
        Rep(i,1,q){
            road.clear();
            flag = 0;
            road.push_back(a[i]);
            dfs(a[i],-1,b[i],road);
            cout<<road.size()<<"\n";
            rep(i,0,road.size()){
                cout<<road[i]<<" ";
            }
            cout<<"\n";
        }
    }else{
        cout<<"NO\n";
        cout<<odd.size()/2<<"\n";
    }
    return 0;
}
