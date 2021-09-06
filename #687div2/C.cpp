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

int a[maxn],sum[maxn];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,p,k,x,y;
    cin>>T; while(T--){
        memset(sum,0,sizeof(sum));
        cin>>n>>p>>k;
        for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
        cin>>x>>y;
        for(int i=n;i>0;i--){
            if(a[i] == 0) sum[i] = sum[i+k]+1;
            else sum[i] = sum[i+k];
        }
        int ans = 1e9;
        for(int i=p;i<=n;i++){
            ans = min((i-p)*y+x*sum[i],ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
