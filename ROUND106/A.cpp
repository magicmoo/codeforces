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
const int INF = 0x3f3f3f3f;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k1,k2,w,b;
    cin>>T; while(T--){
        cin>>n>>k1>>k2;
        cin>>w>>b;
        int white = min(k1,k2);
        white += (max(k1,k2)-white)/2;
        int black = min(n-k1,n-k2);
        black += (max(n-k1,n-k2)-black)/2;
        if(w<=white && b<=black) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
