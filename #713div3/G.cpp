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
const int maxn = 1e7+5;
int cnt[maxn];
int ans[maxn];
int main(){
    IOS;
    int c;
    Rep(i,1,1e7){
        for(int j=i;j<=1e7;j+=i){
            if(cnt[j] > 1e7) continue;
            cnt[j] += i;
        }
    }
    Rep(i,1,1e7){
        if(cnt[i] > 1e7) continue;
        if(ans[cnt[i]] == 0) ans[cnt[i]] = i;
    }
    CAS {
        cin>>c;
        if(ans[c] == 0) cout<<"-1\n";
        else cout<<ans[c]<<"\n";
    }
    return 0;
}
