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
ll a[maxn];
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        if(n%2==0){
            for(ll i=1;i<=n;i+=2){
                cout<<(-a[i+1])<<" "<<a[i]<<" ";
            }
            cout<<"\n";
        }else{
            if(a[1]+a[2]!=0) cout<<(-a[3])<<" "<<(-a[3])<<" "<<(a[1]+a[2])<<" ";
            else if(a[1]+a[3]!=0) cout<<(-a[2])<<" "<<(a[1]+a[3])<<" "<<(-a[2])<<" ";
            else cout<<(a[2]+a[3])<<" "<<(-a[1])<<" "<<(-a[1])<<"\n";
            for(ll i=4;i<=n;i+=2){
                cout<<(-a[i+1])<<" "<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}