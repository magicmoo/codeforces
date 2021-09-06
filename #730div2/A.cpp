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
#define CAS ll CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);   
    #endif
    ll a,b;
    CAS {
        cin>>a>>b;
        if(a == b) cout<<"0 0\n";
        else if(abs(a-b) == 1) cout<<"1 0\n";
        else{
            ll c = abs(a-b);
            cout<<c<<" "<<min(a-a/c*c,a/c*c+c-a)<<"\n";
        }
    }
    return 0;
}
