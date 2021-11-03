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
    ll n;
    // cout<<"-----------------\n";
    CAS {
        cin>>n;
        ll now = 0,nxt = 0;
        while((now+(1LL<<nxt)*3) < n){
            now += (1LL<<nxt)*3;
            nxt += 2;
        }
        ll tmp = nxt;
        if((n-now)%3==1){
            cout<<(1LL<<tmp)+((n-now))/3<<"\n";
        }else if((n-now)%3==2){
            ll cnt = (1LL<<tmp)+((n-now))/3;
            ll num = (1LL<<(tmp+1));
            for(int i=0;i<tmp;i+=2){
                if(((cnt>>i)&1)==0 && ((cnt>>(i+1))&1)==0);
                else if(((cnt>>i)&1)==0 && ((cnt>>(i+1))&1)==1) num += (1LL<<(i))+(1LL<<(i+1));
                else if(((cnt>>i)&1)==1 && ((cnt>>(i+1))&1)==0) num += (1LL<<(i+1));
                else num += (1LL<<i);
            }
            cout<<num<<"\n";
        }else{
            ll cnt1 = (1LL<<tmp)+((n-now))/3-1;
            ll cnt = (1LL<<tmp)+((n-now-1))/3;
            ll num = (1LL<<(tmp+1));
            for(int i=0;i<tmp;i+=2){
                if(((cnt>>i)&1)==0 && ((cnt>>(i+1))&1)==0);
                else if(((cnt>>i)&1)==0 && ((cnt>>(i+1))&1)==1) num += (1LL<<(i))+(1LL<<(i+1));
                else if(((cnt>>i)&1)==1 && ((cnt>>(i+1))&1)==0) num += (1LL<<(i+1));
                else num += (1LL<<i);
            }
            cout<<(cnt1^num)<<"\n";
        }
    }
    return 0;
}
