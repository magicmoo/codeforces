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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,a,b;
    cin>>T;
    while(T--){
        cin>>a>>b;
        ll x = 0;
        ll ans = INF;
        for(int i=0;i<30;i++){
            ll temp = i;
            if(b+i == 1) continue;
            ll aa = a;
            ll bb = b+i;
            while(aa){
                temp++;
                aa /= bb;
            }
            ans = min(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
