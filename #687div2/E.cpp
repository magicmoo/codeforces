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
const ll maxn = 5e5+5;

ll a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll now = 0,mid = 0,ans = 0;
    if(k == 0){
        for(ll i=n;i>0;i--){
            ans += now;
            now += a[i];
        }
        cout<<ans<<"\n";
    }else{
        for(ll i=n;i>0;i--){
            if(now >= 0){
                ans += now;
                now += a[i];
            }else{
                mid = i;
                break;
            }
        }
        a[mid+1] = now;
        for(ll i=1;i<=mid+1;i+=(k+1)){
            for(ll j=i;j<i+k+1&&j<=mid+1;j++){
                ans += (i-1)/(k+1)*a[j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
