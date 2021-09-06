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
    ll k;
    CAS {
        cin>>k;
        ll n = sqrt(k);
        if(n*n == k){
            cout<<n<<" 1\n";
            continue;
        }
        n++;
        ll num = k-(n-1)*(n-1);
        if(num <= n) cout<<num<<" "<<n<<"\n";
        else cout<<n<<" "<<(n-num+n)<<"\n";
    }
    return 0;
}
