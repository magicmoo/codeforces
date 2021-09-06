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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,d,k;
    cin>>T; while(T--){
        cin>>d>>k;
        ll cnt = sqrt(1.0*d*d/2);
        ll num = cnt/k*k;
        if(num*num+(num+k)*(num+k) <= d*d) cout<<"Ashish\n";
        else cout<<"Utkarsh\n";
    }
    return 0;
}
