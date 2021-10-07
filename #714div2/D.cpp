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
const ll maxn = 2e5+5;
ll a[maxn];
pair<ll,ll> b[maxn];
ll fa[maxn];

ll find(ll x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void unit(ll u,ll v){
    ll xx = find(u);
    ll yy = find(v);
    if(xx != yy){
        fa[xx] = yy;
    }
}
int main(){
    IOS;
    ll n,p;
    CAS {
        cin>>n>>p;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n){
            b[i].first = a[i];
            b[i].second = i;
        }
        Rep(i,1,n) fa[i] = i;
        sort(b+1,b+1+n);
        ll ans = 0;
        Rep(m,1,n){
            ll id = b[m].second;
            if(b[m].first>=p) break;
            Rep(i,id+1,n){
                if(find(i)==find(id) || a[i]<a[id] || a[i]%a[id]!=0) break;
                unit(i,id);
                ans += a[id];
            }
            Dep(i,id-1,1){
                if(find(i)==find(id) || a[i]<=a[id] || a[i]%a[id]!=0) break;
                unit(i,id);
                ans += a[id];
            }
        }
        Rep(i,2,n){
            if(find(1) != find(i)){
                ans += p;
                unit(1,i);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
