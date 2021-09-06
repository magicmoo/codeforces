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
vector<ll> v1,v2;
int main(){
    IOS;
    ll n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        v1.clear(); v2.clear();
        ll num = 0;
        Rep(i,1,n){
            if(a[i]%2) v1.push_back(i),num++;
            else v2.push_back(i),num--;
        }
        if(abs(num)>1){
            cout<<"-1\n";
            continue;
        }
        ll n1=0,n2=0,ans = 0;
        if(v1.size() > v2.size()){
            Rep(i,1,n){
                if(i%2 == 1) ans += abs(i-v1[n1++]);
                else ans += abs(i-v2[n2++]);
            }
            ans /= 2;
        }else if(v1.size() < v2.size()){
            Rep(i,1,n){
                if(i%2 == 0) ans += abs(i-v1[n1++]);
                else ans += abs(i-v2[n2++]);
            }
            ans /= 2;
        }else{
            ans = INF;
            ll tmp = 0;
            Rep(i,1,n){
                if(i%2 == 0) tmp += abs(i-v1[n1++]);
                else tmp += abs(i-v2[n2++]);
            }
            ans = min(tmp/2,ans);
            tmp = n1 = n2 = 0;
            Rep(i,1,n){
                if(i%2 == 1) tmp += abs(i-v1[n1++]);
                else tmp += abs(i-v2[n2++]);
            }
            ans = min(tmp/2,ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
