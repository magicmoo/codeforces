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
ll a[maxn],b[maxn];
vector<ll> aa[maxn],bb[maxn];
pair<ll,ll> p[maxn];
int main(){
    IOS;
    ll n,x,y;
    CAS {
        cin>>n;
        Rep(i,1,n) aa[i].clear(),bb[i].clear();
        Rep(i,1,n) a[i] = b[i] = 0;
        Rep(i,1,n){
            cin>>x>>y;
            p[i] = {x,y};
            a[x]++;
            aa[x].push_back(y);
            b[y]++;
            bb[y].push_back(x);
        }
        Rep(i,1,n){
            sort(aa[i].begin(),aa[i].end());
            sort(bb[i].begin(),bb[i].end());
        }
        ll cnt = 0;
        Rep(i,1,n){
            ll x = p[i].first,y = p[i].second;
            cnt += (a[x]-1)*(b[y]-1);
        }
        map<ll,ll> mp;
        Rep(i,1,n){
            mp.clear();
            if(a[i] < 3) continue;
            rep(j,0,aa[i].size()){
                mp[aa[i][j]]++;
            }
            for(auto val : mp){
                if(val.second < 2) continue;
                cnt += val.second*(val.second-1)/2*(aa[i].size()-val.second);
            }
        }
        Rep(i,1,n){
            mp.clear();
            if(b[i] < 3) continue;
            rep(j,0,bb[i].size()){
                mp[bb[i][j]]++;
            }
            for(auto val : mp){
                if(val.second < 2) continue;
                cnt += val.second*(val.second-1)/2*(bb[i].size()-val.second);
            }
        }
        ll ans = n*(n-1)*(n-2)/6 - cnt;
        cout<<ans<<"\n";
    }
    return 0;
}
