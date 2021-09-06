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

ll h[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,n,k;
    cin>>T; while(T--){
        bool flag = true;
        cin>>n>>k;
        for(ll i=0;i<n;i++) cin>>h[i];
        ll U = h[0]+k, D = h[0]; 
        for(ll i=1;i<n-1&&flag;i++){
            if(h[i]>=U || h[i]+k-1+k <= D) flag = false;
            else{
                D = max(D-k+1,h[i]);
                U = min(U+k-1,h[i]+k-1+k);
            }
        }
        if(h[n-1]>=U || h[n-1]+k <= D) flag = false;
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
