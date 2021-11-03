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
const int maxn = 2e3+5;
int a[maxn],cnt[maxn],tmp[maxn],ans[maxn][maxn];
int main(){
    IOS;
    int n,q,x,k;
    CAS {
        cin>>n;
        Rep(i,1,n) cnt[i] = 0;
        Rep(i,1,n) cin>>a[i];
        Rep(i,1,n) cnt[a[i]]++;
        Rep(i,1,n) ans[0][i] = a[i];
        int now = 1;
        while(now<=n){
            Rep(i,1,n) ans[now][i] = cnt[ans[now-1][i]];
            Rep(i,1,n) tmp[i] = cnt[i],cnt[i] = 0;
            Rep(i,1,n) cnt[tmp[i]] += tmp[i];
            now++;
        }
        cin>>q;
        while(q--){
            cin>>x>>k;
            if(k<=n) cout<<ans[k][x]<<"\n";
            else cout<<ans[n][x]<<"\n";
        }
    }
    return 0;
}
