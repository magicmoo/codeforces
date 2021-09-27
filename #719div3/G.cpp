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
const ll INF = 2e18;
const ll maxn = 2e3+5;
ll a[maxn][maxn],book[maxn][maxn],cnt[maxn][maxn];
ll wx[4] = {1,-1,0,0};
ll wy[4] = {0,0,1,-1};
struct Node{
    ll x,y;
    ll w;
};
queue<Node> q;
int main(){
    IOS;
    ll n,m,w;
    cin>>n>>m>>w;
    Rep(i,1,n) Rep(j,1,m) cin>>a[i][j];
    q.push({n,m,0});
    while(!q.empty()){
        ll x = q.front().x;
        ll y = q.front().y;
        ll cost = q.front().w;
        q.pop();
        rep(i,0,4){
            ll tx = x+wx[i];
            ll ty = y+wy[i];
            if(tx<=0 || tx>n || ty<=0 || ty>m || a[tx][ty]==-1) continue;
            if(cnt[tx][ty]) continue;
            cnt[tx][ty] = cost+w;
            q.push({tx,ty,cost+w});
        }
    }
    ll ans = INF,Min = INF;
    cnt[n][m] = 0;
    Rep(i,1,n){
        Rep(j,1,m){
            if(a[i][j]>=1 && cnt[i][j]) Min = min(Min,cnt[i][j]+a[i][j]);
            else if(a[i][j]>=1 && i==n && j==m) Min = min(Min,a[i][j]);
        }
    }
    while(!q.empty()) q.pop();
    q.push({1,1,0});
    if(a[1][1]>=1 && Min!=INF){
        ans = a[1][1] + Min;
    }
    while(!q.empty()){
        ll x = q.front().x;
        ll y = q.front().y;
        ll cost = q.front().w;
        q.pop();
        rep(i,0,4){
            ll tx = x+wx[i];
            ll ty = y+wy[i];
            if(tx<=0 || tx>n || ty<=0 || ty>m || a[tx][ty]==-1 || book[tx][ty]) continue;
            book[tx][ty] = 1;
            if(tx==n && ty==m){
                ans = min(ans,cost+w);
                continue;
            }
            if(a[tx][ty]>=1){
                ans = min(ans,cost+w+a[tx][ty]+Min);
            }
            q.push({tx,ty,cost+w});
        }
    }
    if(ans == INF) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}
