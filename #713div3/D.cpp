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
map<ll,vector<ll>> mp;
int main(){
    IOS;
    ll n;
    CAS {
        mp.clear();
        cin>>n;
        ll sum = 0;
        Rep(i,1,n+2) cin>>a[i];
        Rep(i,1,n+2) mp[a[i]].push_back(i);
        Rep(i,1,n+2) sum += a[i];
        ll n1=0,n2=0;
        Rep(i,1,n+2){
            ll tmp = sum-a[i];
            if(tmp%2==1) continue;
            vector<ll> v = mp[tmp/2];
            rep(j,0,v.size()){
                if(v[j] != i){
                    n1 = v[j];n2 = i;
                    break;
                }
            }
        }
        if(n1==0) cout<<"-1\n";
        else{
            Rep(i,1,n+2){
                if(i==n1 || i==n2) continue;
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
