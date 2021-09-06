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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,a,b,c,p;
    cin>>T; while(T--){
        cin>>p>>a>>b>>c;
        ll ta = (p+a-1)/a * a - p;
        ll tb = (p+b-1)/b * b - p;
        ll tc = (p+c-1)/c * c - p;
        // cout<<ta<<" "<<tb<<" "<<tc<<"\n";
        cout<<min(ta,min(tb,tc))<<"\n";
    }
    return 0;
}
