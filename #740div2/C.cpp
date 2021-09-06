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
vector<ll> v[maxn];
ll a[maxn],pre[maxn];
pair<ll,ll> p[maxn];
int main(){
    IOS;
    ll n,k,num;
    CAS{
        cin>>n;
        Rep(i,1,n){
            cin>>k;
            v[i].clear();
            rep(j,0,k){
                cin>>num;
                v[i].push_back(num);
            }
        }
        Rep(i,1,n){
            a[i] = 0;
            rep(j,0,v[i].size()){
                a[i] = max(a[i],v[i][j]+1-j);
            }
        }
        Rep(i,1,n){
            p[i] = {a[i],v[i].size()};
        }
        sort(p+1,p+1+n);
        ll ans = 0;
        pre[0] = 0;
        Rep(i,1,n){
            ans = max(ans,p[i].first-pre[i-1]);
            pre[i] = p[i].second+pre[i-1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
