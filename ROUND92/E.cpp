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
<<<<<<< HEAD
const ll INF = 0x3f3f3f3f;
ll lcm(ll a,ll b){
=======
const int INF = 0x3f3f3f3f;
int lcm(int a,int b){
>>>>>>> 28154b9c92a107f6bc0f309507eb4b9fd0ce4421
    return a/__gcd(a,b)*b;
}
int main(){
    IOS;
<<<<<<< HEAD
    ll m,d,w;
    CAS {
        cin>>m>>d>>w;
        if(m==1 || d==1){
            cout<<"0\n";
            continue;
=======
    int m,d,w;
    CAS {
        cin>>m>>d>>w;
        int num = min(m,d);
        int g = __gcd(w,d-1);
        if(g==1){
            cout<<(num-1)*num/2<<"\n";
            continue
>>>>>>> 28154b9c92a107f6bc0f309507eb4b9fd0ce4421
        }
        ll g;
        g = lcm(d-1,w)/(d-1);
        ll num = min(m,d)-1;
        ll f = num-num/g*g;
        ll n = (num-f)/g;
        cout<<(f+1)*n+(n-1)*n*g/2<<"\n";
    }
    return 0;
}
