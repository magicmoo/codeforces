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
const ll maxn = 2e5+5;
pair<ll,ll> a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n;
    cin>>T; while(T--){
        cin>>n;
        a[0].first = a[0].second = 1;
        for(ll i=1;i<=n;i++) cin>>a[i].first;
        for(ll i=1;i<=n;i++) cin>>a[i].second;
        sort(a+1,a+n+1);
        ll ans = 0,r,c;
        for(ll i=1;i<=n;i++){
            if(a[i-1].first==a[i].first) continue;
            if(a[i].first == a[i].second){
                ans += a[i].first-a[i-1].first;
            }else if((a[i-1].first+a[i-1].second)%2 == 0){
                if(a[i].first-a[i].second == a[i-1].first-a[i-1].second){
                    ans += a[i].first-a[i-1].first;
                }else{
                    c = a[i-1].second+a[i].first-a[i-1].first-1;
                    ans += (abs(c-a[i].second)+1)/2;
                }
            }else{
                c = a[i-1].second+a[i].first-a[i-1].first;
                ans += (abs(c-a[i].second)+1)/2;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
