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
const int maxn = 55;

int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        int ans = 0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            int Max = max(a[i-1],a[i]);
            int Min = min(a[i-1],a[i]);
            if(Max <= Min*2) continue;
            else{
                ans += log2((Max+Min-1)/Min-1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
