#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
vector<pair<ll,ll>> v[maxn];
ll book[maxn],ans[maxn];
ll book2[maxn][55];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
map<pair<int,int>,int> mp;
int main(){
    IOS;
    ll n,m,l,r,w,ww,now,nxt,cost;
    cin>>n>>m;
    Rep(i,1,m){
        cin>>l>>r>>w;
        v[l].push_back({r,w});
        v[r].push_back({l,w});
    }
    book[1] = 1;
    rep(i,0,v[1].size()){
        nxt = v[1][i].first;
        cost = v[1][i].second;
        if(book2[nxt][cost]) continue;
        book2[nxt][cost] = 1;
        rep(j,0,v[nxt].size()){
            int ww = (v[1][i].second+v[nxt][j].second)*(v[1][i].second+v[nxt][j].second);
            if(book[v[nxt][j].first]) continue;
            if(ans[v[nxt][j].first] && ans[v[nxt][j].first]<=ww) continue;
            q.push({ww,v[nxt][j].first});
            ans[v[nxt][j].first] = ww;
        }
    }
    while(!q.empty()){
        now = q.top().second;
        w = q.top().first;
        q.pop();
        if(book[now]) continue;
        book[now] = 1;
        rep(i,0,v[now].size()){
            nxt = v[now][i].first;
            cost = v[now][i].second;
            if(book2[nxt][cost]) continue;
            book2[nxt][cost] = 1;
            rep(j,0,v[nxt].size()){
                ww = (v[now][i].second+v[nxt][j].second)*(v[now][i].second+v[nxt][j].second)+w;
                if(book[v[nxt][j].first]) continue;
                if(ans[v[nxt][j].first] && ans[v[nxt][j].first]<=ww) continue;
                q.push({ww,v[nxt][j].first});
                ans[v[nxt][j].first] = ww;
            }
        }
    }
    cout<<"0 ";
    Rep(i,2,n){
        if(ans[i] == 0) cout<<"-1 ";
        else cout<<ans[i]<<" ";
    }
    return 0;
}
