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
const int maxn = 2e5+5;

int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans = 0;
        int Max = max(abs(a[2]-a[1]),abs(a[n]-a[n-1]));
        for(int i=2;i<n;i++){
            int m = abs(a[i+1]-a[i])+abs(a[i]-a[i-1]);
            int m1 = abs(a[i+1]-a[i-1]);
            Max = max(Max,m-m1);
        }
        for(int i=n;i>=2;i--){
            ans += abs(a[i]-a[i-1]);
        }
        cout<<ans-Max<<"\n";
    }
    return 0;
}
