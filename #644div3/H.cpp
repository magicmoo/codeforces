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
ll n,m;
ll change(string& str){
    ll ans = 0;
    rep(i,0,str.size()){
        ans *= 2;
        if(str[i]=='1') ans++;
    }
    return ans;
}
string change(ll num){
    string ans = "";
    while(num){
        if(num%2) ans = '1'+ans;
        else ans = '0'+ans;
        num /= 2;
    }
    string tmp = "";
    rep(i,0,m-ans.size()) tmp.push_back('0');
    return tmp+ans;    
}
set<ll> s;
int main(){
    IOS;
    string str;
    CAS {
        s.clear();
        cin>>n>>m;
        ll mid = ((1LL<<m)-1)/2;
        ll l = mid;
        ll r = (1LL<<m)-1-mid;
        Rep(i,1,n){
            cin>>str;
            ll num = change(str);
            s.insert(num);
            if(num == mid){
                if(r>l){
                    while(s.count(mid)) mid++;
                    r--;
                }else{
                    while(s.count(mid)) mid--;
                    l--;
                }
            }else if(num > mid){
                r--;
                if(r<l){
                    mid--;
                    while(s.count(mid)) mid--;
                    l--; r++;
                }
            }else{
                l--;
                if(l<r-1){
                    mid++;
                    while(s.count(mid)) mid++;
                    l++; r--;
                }
            }
        }
        cout<<change(mid)<<"\n";
    }
    return 0;
}
