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
const ll maxn = 2e5+5;
ll arr[maxn];
ll cal(ll len){
    return len*(len+1)/2;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    CAS {
        cin>>n;
        ll ans = n;
        for(ll i=1;i<=n;i++) cin>>arr[i];
        for(ll l=1;l<n;l++){
            ans++;
            char fx = '0';
            if(arr[l+1]==arr[l]) continue;
            else if(arr[l+1]<arr[l]) fx = 'x';
            else fx = 's';
            if(fx == 's'){
                if(l+2<=n && arr[l+2]<arr[l+1]) ans++;
                else continue;
                if(arr[l+2]>=arr[l]) continue;
                if(l+3<=n && arr[l+3]<arr[l+1] && arr[l+3]>arr[l+2]) ans++;
            }else{
                if(l+2<=n && arr[l+2]>arr[l+1]) ans++;
                else continue;
                if(arr[l+2]<=arr[l]) continue;
                if(l+3<=n && arr[l+3]<arr[l+2] && arr[l+3]>arr[l+1]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
