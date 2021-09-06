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
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll n;
    CAS {
        vector<pair<int,int>> ans;
        cin>>n;
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll Min = 1e9+5,Mini = 0;
        for(ll i=1;i<=n;i++) if(a[i]<Min) Min = a[i],Mini = i;
        for(int i=Mini-1;i>0;i--){
            if(__gcd(a[i],a[i+1]) != 1){
                ans.push_back({i,a[i+1]+1});
                a[i] = a[i+1]+1;
            }
        }
        for(int i=Mini+1;i<=n;i++){
            if(__gcd(a[i-1],a[i]) != 1){
                ans.push_back({i,a[i-1]+1});
                a[i] = a[i-1]+1;
            }
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<Mini<<" "<<ans[i].second<<" "<<Min<<"\n";
        }
    }
    return 0;
}
