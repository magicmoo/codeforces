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
int book[maxn];
int sum[maxn],cnt[maxn];
vector<pair<int,int>> vec[maxn];
bool flag;
int fa[maxn];

int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void unit(int u,int v){
    int xx = find(u);
    int yy = find(v);
    if(xx != yy){
        fa[xx] = yy;
    }
}
void dfs(int now,int sign){
    if(!flag) return;
    if(book[now]){
        if(book[now]!=sign) flag = 0;
        return;
    }
    book[now] = sign;
    rep(i,0,vec[now].size()){
        dfs(vec[now][i].first,vec[now][i].second*sign);
        unit(now,vec[now][i].first);
    }
}
int main(){
    IOS;
    int n,m,l,r;
    string str;
    CAS {
        flag = true;
        cin>>n>>m;
        Rep(i,1,n) fa[i] = i;
        Rep(i,1,n) vec[i].clear();
        Rep(i,1,n) book[i] = sum[i] = cnt[i] = 0;
        Rep(i,1,m){
            cin>>l>>r>>str;
            if(str=="crewmate"){
                vec[l].push_back({r,1});
                vec[r].push_back({l,1});
            }else{
                vec[l].push_back({r,-1});
                vec[r].push_back({l,-1});
            }
        }
        Rep(i,1,n) if(book[i]==0) dfs(i,1);
        ll ans = 0;
        Rep(i,1,n){
            sum[find(i)]++;
            if(book[i]==1) cnt[find(i)]++;
        }
        Rep(i,1,n){
            if(sum[i]==0) continue;
            ans += max(cnt[i],sum[i]-cnt[i]);
        }
        if(flag) cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
