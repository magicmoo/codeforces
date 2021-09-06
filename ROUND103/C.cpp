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

ll c[maxn],a[maxn],b[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=0;i<n;i++) cin>>c[i];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        a[n] = 1; b[n] = c[n-1];
        ll ans = 0, temp = max(a[1],b[1])-min(a[1],b[1])+1;
        for(ll i=1;i<n;i++){
            if(a[i+1] == b[i+1]){
                ans = max(temp+c[i],ans);
                temp = 1;
            }else{
                ans = max(temp+c[i],ans);
                temp += c[i] - max(a[i+1],b[i+1])+1;
                temp += min(a[i+1],b[i+1]);
                temp = max(temp,max(a[i+1],b[i+1])-min(a[i+1],b[i+1])+1);
            }
        }
        // temp = c[n-1];
        // for(ll i=n-2;i>=0;i--){
        //     if(a[i+1] == b[i+1]){
        //         ans = max(temp+1,ans);
        //         temp = c[i];
        //     }else{
        //         ans = max(max(a[i+1],b[i+1])-min(a[i+1],b[i+1])+1+temp,ans);
        //         temp += c[i] - max(a[i+1],b[i+1])+1;
        //         temp += min(a[i+1],b[i+1]);
        //     }
        // }
        cout<<ans<<"\n";
    }
    return 0;
}
