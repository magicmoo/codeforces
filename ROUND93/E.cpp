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
set<pair<ll,bool>> l,r;
set<ll> s;
ll cnt,last,ans;
void change(){
    while(r.size()>cnt){
        l.insert(*(r.begin()));
        if((*r.begin()).second==0) last++;
        ans -= (*r.begin()).first;
        r.erase(r.begin());
    }
    while(r.size()<cnt){
        r.insert(*(--l.end()));
        if((*(--l.end())).second==0) last--;
        ans += (*(--l.end())).first;
        l.erase(--l.end());
    }
    if(l.empty() || r.empty()) return;
    pair<ll,bool> back1 = *(--l.end());
    pair<ll,bool> back2 = *(r.begin());
    if(back1 > back2){
        if(back1.second==0) last--;
        if(back2.second==0) last++;
        l.erase(back1);
        l.insert(back2);
        r.insert(back1);
        r.erase(back2);
        ans += back1.first-back2.first;
    }
}
int main(){
    IOS;
    ll n,d;
    bool tp;
    cin>>n;
    auto index = s.end();
    while(n--){
        cin>>tp>>d;
        if(d>0){
            ans += d;
            if(tp==1){
                s.insert(d);
                cnt++;
                last++;
            }
            l.insert({d,!tp});
            change();
        }else{
            d = -d;
            ans -= d;
            if(tp==1){
                s.erase(d);
                cnt--;
            }
            if(l.count({d,!tp})){
                if(tp==1) last--;
                l.erase({d,!tp});
            }
            else{
                r.erase({d,!tp});
                ans -= d;
            }
            change();
        }
        if(!last){
            if(l.empty()) cout<<ans-(*s.begin())<<"\n";
            else if(!s.empty()) cout<<ans-(*s.begin())+(*(--l.end())).first<<"\n";
            else cout<<ans<<"\n";
        }else cout<<ans<<"\n";
    }
    return 0;
}
