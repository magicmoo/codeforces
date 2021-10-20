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
const int maxn = 1e5+5;
int a[maxn],b[maxn],c[maxn],book[maxn];
int main(){
    IOS;
    int n,m;
    CAS {
        cin>>n>>m;
        Rep(i,1,n) book[i] = 0;
        Rep(i,1,m) cin>>a[i]>>b[i]>>c[i];
        Rep(i,1,m){
            book[b[i]] = 1;
        }
        int ans = 0;
        Rep(i,1,n){
            if(!book[i]){
                ans = i;
                break;
            }
        }
        Rep(i,1,n){
            if(ans == i) continue;
            cout<<i<<" "<<ans<<"\n";
        }
    }
    return 0;
}
