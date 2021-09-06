#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
#define Rep(i,x,y) for(auto i=(x);i<=(y);i++)
#define rep(i,x,y) for(auto i=(x);i<(y);i++)
#define Dep(i,x,y) for(auto i=(x);i>=(y);i--)
#define dep(i,x,y) for(auto i=(x);i>(y);i--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int W,H,x1,y1,x2,y2,w,h;
    CAS {
        cin>>W>>H;
        cin>>x1>>y1>>x2>>y2;
        cin>>w>>h;
        int max1 = max(W-x2,x1);
        int max2 = max(H-y2,y1);
        int len = x2-x1,height = y2-y1;
        if(len+w>W && height+h>H){
            cout<<"-1\n"; continue;
        }
        int x = 0,y = 0;
        if(max1 < w) x = w-max1;
        if(max2 < h) y = h-max2;
        if(len+w > W) x = INF;
        if(height+h > H) y = INF;
        int ans = min(x,y);
        cout<<ans<<"\n";
    }
    return 0;
}
