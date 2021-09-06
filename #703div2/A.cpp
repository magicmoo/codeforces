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
const ll maxn = 105;

ll a[maxn],sum[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,num;
    cin>>T; while(T--){
        bool flag = true;
        num = 0;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=n;i++) sum[i] = sum[i-1]+a[i];
        for(ll i=1;i<=n;i++){
            if(sum[i] < (i-1)*i/2){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    } 
    return 0;
}
