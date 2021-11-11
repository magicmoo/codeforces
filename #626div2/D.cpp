#include<bits/stdc++.h>
using namespace std;
#define CAS ll CASE;  \
            cin>>CASE; \
            Rep(__,1,CASE)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n";
#define PII pair<int,int>
#define Rep(i,x,y) for(int i=(x);i<=(y);i++)
#define rep(i,x,y) for(int i=(x);i<(y);i++)
#define Dep(i,x,y) for(int i=(x);i>=(y);i--)
#define dep(i,x,y) for(int i=(x);i>(y);i--)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 4e5+5;
int a[maxn],cnt[32],cnt2[32];
int main(){
    IOS;
    int n;
    cin>>n;
    Rep(i,1,n) cin>>a[i];
    Rep(i,1,n){
        rep(j,0,30){
            cnt[j] += (a[i]>>j)&1;
        }
    }
    int ans = 0;
    Rep(i,1,n){
        int tmp = 0,now = 1;
        rep(j,0,30){
            if((a[i]>>j)&1){
                if((n-cnt[j])&1) ans += now;
            }else{
                if(cnt[j]&1) ans += now;
            }
            now *= 2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
