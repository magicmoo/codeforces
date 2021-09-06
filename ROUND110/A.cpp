#include<bits/stdc++.h>
using namespace std;
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        int s1,s2,s3,s4;
        cin>>s1>>s2>>s3>>s4;
        if(max(s1,s2)>min(s3,s4) && max(s3,s4)>min(s1,s2)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
