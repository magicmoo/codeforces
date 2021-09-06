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
int cal(string a,string b){
    int now = 0,tmp = 0;
    rep(i,0,a.size()){
        bool flag = 0;
        rep(j,now,b.size()){
            if(a[i] == b[j]){
                now = j+1;
                tmp++;
                flag = 1;
                break;
            }
        }
        if(!flag) break;
    }
    return (a.size()-tmp)+(b.size()-tmp);
}
int main(){
    IOS;
    int n;
    vector<ll> v;
    ll now = 1;
    while(now <= 1e18){
        v.push_back(now);
        now *= 2;
    }
    CAS {
        cin>>n;
        int ans = INF;
        rep(i,0,v.size()){
            string s1 = to_string(v[i]);
            string s2 = to_string(n);
            ans = min(ans,cal(s1,s2));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
