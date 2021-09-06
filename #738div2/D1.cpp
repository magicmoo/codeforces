#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
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
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
int cnt1[maxn],cnt2[maxn];
namespace A{
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
}
namespace B{
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
}
int main(){
    IOS;
    int n,m1,m2;
    int l,r;
    cin>>n>>m1>>m2;
    Rep(i,1,n){
        A::fa[i] = i;
        B::fa[i] = i;
    }
    Rep(i,1,m1){
        cin>>l>>r;
        A::unit(l,r);
    }
    Rep(i,1,m2){
        cin>>l>>r;
        B::unit(l,r);
    }
    vector<pair<int,int>> ans;
    Rep(i,1,n){
        Rep(j,i+1,n){
            if((A::find(i)==A::find(j)) || (B::find(i)==B::find(j))) continue;
            A::unit(i,j);
            B::unit(i,j);
            ans.push_back({i,j});
        }
    }
    cout<<ans.size()<<"\n";
    rep(i,0,ans.size()) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
}
