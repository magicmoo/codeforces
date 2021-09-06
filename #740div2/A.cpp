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
const int maxn = 1005;
int a[maxn];
bool check(int n){
    Rep(i,1,n) if(a[i] != i) return 0;
    return 1;
}
int main(){
    IOS;
    int n;
    CAS {
        cin>>n;
        Rep(i,1,n) cin>>a[i];
        int ans = 0;
        while(!check(n)){
            if(ans%2 == 0){
                for(int i=1;i<n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            }else{
                for(int i=2;i<n;i+=2) if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            }
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
