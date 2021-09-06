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
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    char ch[50]; int n;
    CAS {
        cin>>n;
        scanf("%s",ch+1);
        char ch2[50];
        Rep(i,1,n) ch2[i] = ch[i];
        sort(ch2+1,ch2+1+n);
        int ans = 0;
        Rep(i,1,n) if(ch2[i] != ch[i]) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
