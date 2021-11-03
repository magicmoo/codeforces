#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+5;
const int maxv = 1e3+5;
int a[maxn];
int sum[maxv][maxv];
int main(){
    IOS;
    int t,x,y,q;
    cin>>q;
    while(q--){
        cin>>t>>x>>y;
        if(t==1){
            a[x] += y;
            Rep(i,1,800){
                sum[i][x%i] += y;
            }
        }
        else{
            if(x <= 800) cout<<sum[x][y]<<"\n";
            else{
                int ans = 0;
                for(int i=y;i<=5e5;i+=x){
                    ans += a[i];
                }
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}
