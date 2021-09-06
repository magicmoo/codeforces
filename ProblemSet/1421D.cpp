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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll x,y;
    ll c[10];
    ll cc[10];
    CAS {
        cin>>y>>x;
        for(ll i=1;i<=6;i++) cin>>c[i];
        cc[1] = min(c[1],c[6]+c[2]);
        cc[2] = min(c[2],c[1]+c[3]);
        cc[3] = min(c[3],c[4]+c[2]);
        cc[4] = min(c[4],c[3]+c[5]);
        cc[5] = min(c[5],c[4]+c[6]);
        cc[6] = min(c[6],c[1]+c[5]);
        if(x*y == 0){
            if(x != 0){
                if(x > 0) cout<<cc[2]*x<<"\n";
                else cout<<(-cc[5]*x)<<"\n";
            }else{
                if(y > 0) cout<<cc[6]*y<<"\n";
                else cout<<(-cc[3]*y)<<"\n";
            }
        }
        else if(x*y > 0){
            if(x > 0){
                if(x >= y) cout<<(x-y)*cc[2]+y*cc[1]<<"\n";
                else cout<<(y-x)*cc[6]+x*cc[1]<<"\n";
            }else{
                if(x >= y) cout<<(-x)*cc[4]+(x-y)*cc[3]<<"\n";
                else cout<<(-y)*cc[4]+(y-x)*cc[5]<<"\n";
            }
        }else{
            if(x > 0) cout<<x*cc[2]-y*cc[3]<<"\n";
            else cout<<y*cc[6]-x*cc[5]<<"\n";
        }
    }
    return 0;
}
