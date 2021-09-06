#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;

ll t[maxn],x[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n;
    cin>>T; while(T--){
        ll ans = 0;
        cin>>n;
        for(ll i=0;i<n;i++) cin>>t[i]>>x[i];
        ll cnt = 1,now = 0,last = 0,dir = 0,st = 0;
        for(ll i=0;i<n-1;i++){
            if(t[i] >= cnt){
                if(x[i] >= now) dir = 1;
                else dir = -1;
                cnt = t[i]+abs(x[i]-now);
                last = now;
                now = x[i];
                st = t[i];
                if(t[i+1] >= cnt) ans++;
            }else{
                if(dir == 1){
                    ll b = last+(t[i]-st);
                    ll e = min(now,b+t[i+1]-t[i]);
                    if(x[i]<=e && x[i]>=b) ans++;
                }else{
                    ll b = last-(t[i]-st);
                    ll e = max(now,b-t[i+1]+t[i]);
                    if(x[i]>=e && x[i]<=b) ans++;
                }
            }
        }
        if(t[n-1] >= cnt) ans++;
        else{
            if(dir == 1){
                ll b = last+(t[n-1]-st);
                if(x[n-1]<=now && x[n-1]>=b) ans++;
            }else{
                ll b = last-(t[n-1]-st);
                if(x[n-1]>=now && x[n-1]<=b) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
