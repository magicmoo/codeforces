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
    string str;
    CAS {
        cin>>str;
        int l0 = 0,l1 = 0,r0 = 0,r1 = 0,_l = 0,_r = 0;
        int nex1 = 5,nex2 = 5;
        int ans = -1;
        rep(i,0,10){
            if(i%2==0){
                if(str[i] == '1') l1++;
                else if(str[i] == '0') l0++;
                else _l++;
                nex1--;
            }else{
                if(str[i] == '1') r1++;
                else if(str[i] == '0') r0++;
                else _r++;
                nex2--;
            }
            if(l1+_l>nex2+r1 || r1+_r>nex1+l1){
                ans = i+1;
                break;
            }
        }
        if(ans != -1) cout<<ans<<"\n";
        else cout<<"10\n";
    }
    return 0;
}
