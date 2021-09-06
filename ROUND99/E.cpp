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

struct Node{
    ll x,y;
}p[4];
ll x[4],y[4];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T;
    cin>>T; while(T--){
        for(ll i=0;i<4;i++) cin>>p[i].x>>p[i].y;
        vector<ll> v;
        for(ll i=0;i<4;i++){
            for(ll j=i+1;j<4;j++){
                v.push_back(abs(p[i].x-p[j].x));
                v.push_back(abs(p[i].y-p[j].y));
            }
        }
        // v.push_back(0); v.push_back(2); v.push_back(4);
        ll ans = 1e18;
        for(ll i=0;i<v.size();i++){
            // cout<<v[i]<<" ";
            for(ll a=0;a<4;a++){
                for(ll b=0;b<4;b++){
                    if(a == b) continue;
                    for(ll c=0;c<4;c++){
                        if(c == b || c==a) continue;
                        for(ll d=0;d<4;d++){
                            if(d == c || d==a || d==b) continue;
                            ll temp = 0;
                            x[0] = p[a].x; y[0] = p[a].y;
                            x[1] = p[b].x-v[i]; y[1] = p[b].y;
                            x[2] = p[c].x; y[2] = p[c].y-v[i];
                            x[3] = p[d].x-v[i]; y[3] = p[d].y-v[i];
                            sort(x,x+4); sort(y,y+4);
                            ll xx = x[2],yy = y[2];
                            for(ll j=0;j<4;j++){
                                temp += abs(xx-x[j])+abs(yy-y[j]);
                            }
                            ans = min(ans,temp);
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
