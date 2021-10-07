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

int main(){
    IOS;
    ll n,m,k;
    CAS {
        cin>>n>>m>>k;
        if(n == 1){
            if(m==0 && k>1) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(k <= 2){
            cout<<"NO\n";
            continue;
        }
        if(k > 3){
            if(m<=n*(n-1)/2 && m>=n-1) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(m == n*(n-1)/2){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
    return 0;
}
