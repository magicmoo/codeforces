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

ll ans[2005];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,k,n;
    cin>>T; while(T--){
        cin>>k;
        if(k%2 == 1){
            cout<<"-1\n";
            continue;
        }
        n = 0;
        k /= 2;
        ll last = 0;
        while(k){
            ll temp = k%2;
            if(temp == 0);
            else if(last > 0){
                ans[n++] = 1;
                for(ll i=0;i<last-1;i++) ans[n++] = 0;
                ans[n++] = 1;
            }else{
                ans[n++] = 1;
            }
            k /= 2;
            last++;
        }
        // if(n <= 2000){
            cout<<n<<"\n";
            for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        // }else cout<<"-1\n";
    }
    return 0;
}
