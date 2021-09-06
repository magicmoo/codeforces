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
const int maxn = 2e5+5;
int a[maxn],b[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        int n;
        scanf("%d",&n);
        Rep(i,1,n) scanf("%1d",&a[i]);
        Rep(i,1,n) scanf("%1d",&b[i]);
        a[0] = a[n+1] = -1;
        int ans = 0;
        Rep(i,1,n){
            if(b[i] == 0) continue;
            if(a[i-1] == 1){
                a[i-1] = -1; ans++;
            }else if(a[i] == 0){
                a[i] = -1; ans++;
            }else if(a[i+1] == 1){
                a[i+1] = -1; ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
