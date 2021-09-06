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
const int maxn = 5005;

int a[maxn],b[maxn],c[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) b[i] = a[i];
        ll ans = 0;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            if(a[i] > b[i]+1) ans += a[i]-b[i]-1;
            for(int j=min(i+a[i],n-1);j>i+1;j--){
                b[j]++;
            }
            if(b[i] >= a[i]) b[i+1] += b[i]-a[i]+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
