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
const ll maxn = 15;
ll a[maxn];
ll calc(ll num){
    ll now = 1;
    Rep(i,1,num) now *= 10;
    return now;
}
int main(){
    IOS;
    ll n,k;
    CAS {
        cin>>n>>k;
        Rep(i,1,n) cin>>a[i];
        ll last = 1,cnt = 0;
        bool flag = 0;
        Rep(i,2,n){
            ll now = calc(a[i]);
            if((now/last-1)+cnt > k){
                flag = 1;
                ll ans = last*(k-cnt+1);
                rep(j,0,a[i-1]){
                    ans += calc(j)*9;
                }
                cout<<ans<<"\n";
                break;
            }
            cnt += (now/last-1);
            last = now;
        }
        if(!flag){
            ll ans = last*(k-cnt+1);
            rep(i,0,a[n]){
                ans += calc(i)*9;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
