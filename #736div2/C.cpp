#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m,u,v,q,index;
    cin>>n>>m;
    int ans = n;
    while(m--){
        cin>>u>>v;
        if(u<v){
            if(!a[u]) ans--;
            a[u]++;
        }else{
            if(!a[v]) ans--;
            a[v]++;
        }
    }
    cin>>q;
    while(q--){
        cin>>index;
        if(index == 1){
            cin>>u>>v;
            if(u<v){
                if(!a[u]) ans--;
                a[u]++;
            }else{
                if(!a[v]) ans--;
                a[v]++;
            }
        }else if(index == 2){
            cin>>u>>v;
            if(u<v){
                a[u]--;
                if(!a[u]) ans++;
            }else{
                a[v]--;
                if(!a[v]) ans++;
            }
        }else cout<<ans<<"\n";
    }
    return 0;
}
