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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll INF = 0x3f3f3f3f;
const ll maxn = 1e4+5;

ll map[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,x;
    vector<ll> v;
    for(ll i=1;i<=1e4;i++){
        map[i] = i*i*i;
    }
    bool flag = true;
    map[0] = INF;
    cin>>T; while(T--){
        cin>>x;
        flag = false;
        for(ll i=1;i<=1e4;i++){
            ll y = x-map[i];
            if(y <= 0) break;
            ll index = lower_bound(map+1,map+10000+1,y)-map;
            if(map[index] == y){
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
