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
    int n;
    CAS {
        cin>>n;
        if(n==1){
            cout<<"a\n";
        }else if(n%2 == 0){
            rep(i,0,n/2) cout<<"a";
            cout<<"b";
            rep(i,1,n/2) cout<<"a";
            cout<<"\n";
        }else{
            rep(i,0,n/2) cout<<"a";
            cout<<"b";
            rep(i,1,n/2) cout<<"a";
            cout<<"c\n";
        }
    }
    return 0;
}
