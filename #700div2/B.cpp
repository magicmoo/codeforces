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

ll a[maxn],b[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    ll T,A,B,n;
    cin>>T;
    while(T--){
        bool flag = true;
        cin>>A>>B>>n;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        ll Min = 0, Mini = -1;
        for(ll i=0;i<n;i++){
            if(a[i] > Min){
                Min = a[i];
                Mini = i;
            }
        }
        for(ll i=0;i<n;i++){
            if(i == Mini) continue;
            B -= (b[i]+A-1)/A*a[i];
            if(B <= 0){
                flag = false;
                break;
            }
        }
        B -= (b[Mini]-1)/A*a[Mini];
        if(B <= 0) flag = false;
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
