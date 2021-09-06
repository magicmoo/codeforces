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
const ll maxn = 1e5+5;
ll a[maxn];
ll pre1[maxn],pre2[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n;
    cin>>T; while(T--){
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        pre1[1] = a[1]; pre2[2] = a[2];
        for(ll i=3;i<=n;i+=2) pre1[i] = pre1[i-2]+a[i];
        for(ll i=4;i<=n;i+=2) pre2[i] = pre2[i-2]+a[i];
        ll ans = n*a[1]+n*a[2];
        ll m1 = 1e9+5,m2 = 1e9+5,last1,last2,temp;
        for(int i=1;i<n;i++){
            if(i%2==1){
                m1 = min(m1,a[i]);
                m2 = min(m2,a[i+1]);
                last1 = n-(i/2)-1;
                last2 = n-(i/2)-1;
                temp = pre1[i]+m1*last1 + pre2[i+1]+m2*last2;
            }else{
                m2 = min(m2,a[i]);
                m1 = min(m1,a[i+1]);
                last1 = n-(i/2)-1;
                last2 = n-(i/2);
                temp = pre2[i]+m2*last2 + pre1[i+1]+m1*last1;
            }
            ans = min(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
