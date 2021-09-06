#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(ll i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,m;
    CAS {
        cin>>n>>m;
        if(n > m) cout<<"0\n";
        else if(n == m){
            ll cnt = 0;
            while(n%2){
                n /= 2;
                cnt++;
            }
            cout<<(1<<cnt)<<"\n";
        }else{
            ll ans = 0,tmp = 0;
            bool flag = 0;
            Dep(i,30,0){
                ll l = (n>>i)&1;
                ll r = (m>>i)&1;
                if(l==0){
                    if(r == 0) tmp = i;
                    else ans += 1<<i;
                }else{
                    if(r == 0){ flag = 1; break; }
                }
            }
            if(flag) cout<<ans<<"\n";
            else cout<<(ans>>tmp<<tmp)+(1<<tmp)<<"\n";
        }
    }
    return 0;
}
