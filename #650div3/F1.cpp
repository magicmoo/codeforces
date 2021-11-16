#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<ll,ll>
#define Rep(i,x,y) for(ll i=(x);i<=(y);i++)
#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(ll i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 3e3+5;
ll a[maxn],mp[maxn];
PII p[maxn];
ll dp[maxn][3];
ll post[maxn];
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n){
            p[i] = {a[i],i};
        }
        sort(p+1,p+1+n);
        Rep(i,1,n) mp[p[i].second] = i;
        int ans = n-1;
        Rep(i,1,n){
            int tmp=n-1;
            int r = mp[i]+1;
            Rep(j,i+1,n){
                if(mp[j]==r){
                    tmp--;
                    r++;
                }
            }
            ans = min(tmp,ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
