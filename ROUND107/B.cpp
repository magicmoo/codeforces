#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
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
    int a,b,c;
    CAS {
        cin>>a>>b>>c;
        int cc = 1;
        for(int i=1;i<c;i++) cc *= 10;
        cc++;
        int aa = cc;
        int temp = aa;
        for(int i=0;i<a-c;i++) aa *= 10;
        aa += temp;
        int bb = cc;
        for(int i=0;i<b-c;i++) bb *= 10;
        cout<<aa<<" "<<bb<<"\n";
        // cout<<__gcd(aa,bb)<<"\n";
    }
    return 0;
}
