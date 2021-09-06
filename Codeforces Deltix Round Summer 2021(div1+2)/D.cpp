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
ll AND(ll u,ll v){
    ll ans = 0;
    cout<<"and "<<u<<" "<<v<<"\n";
    cin>>ans;
    fflush(stdout);
    return ans;
}
ll OR(ll u,ll v){
    ll ans = 0;
    cout<<"or "<<u<<" "<<v<<"\n";
    cin>>ans;
    fflush(stdout);
    return ans;
}
int main(){
    ll n,k;
    cin>>n>>k;
    ll a1 = AND(1,2);
    ll o1 = OR(1,2);
    ll a2 = AND(1,3);
    ll o2 = OR(1,3);
    ll a3 = AND(2,3);
    ll o3 = OR(2,3);
    ll now = 1,cnt = 1;
    rep(i,0,30) cnt *= 2;
    now = cnt;
    ll n1,n2,n3;
    n1 = n2 = n3 = 0;
    while(now){
        if(a1&now){
            n1 += now,n2 += now;
            if(a2&now) n3 += now;
        }else if((o1&now) == 0){
            if(o2&now) n3 += now;
        }else{
            if((o2&now) && (o3&now)){
                n3 += now;
                if(a2&now) n1 += now;
                else n2 += now;
            }else if(o2&now){
                n1 += now;
            }else if(o3&now) n2 += now;
        }
        now /= 2;
    }
    vector<ll> v;
    v.push_back(n1); v.push_back(n2); v.push_back(n3);
    Rep(i,4,n){
        ll num1 = AND(1,i);
        ll num2 = OR(1,i);
        now = cnt;
        ll tmp = 0;
        while(now){
            if((n1&now) && (num1&now)) tmp += now;
            else if((n1&now)==0 && num2&now) tmp += now;
            now /= 2;
        }
        v.push_back(tmp);
        
    }
    sort(v.begin(),v.end());
    cout<<"finish "<<v[k-1]<<"\n";
    fflush(stdout);
    return 0;
}
