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
    int T,n,m,r,c;
    cin>>T; while(T--){
        cin>>n>>m>>r>>c;
        int ans = 0;
        ans = max(ans,r-1+c-1);
        ans = max(ans,n-r+c-1);
        ans = max(ans,n-r+m-c);
        ans = max(ans,r-1+m-c);
        cout<<ans<<"\n";
    }
    return 0;
}
