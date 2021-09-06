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
const int maxn = 105;

int a[maxn],b[maxn],t[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int i=1;i<=n;i++) cin>>t[i];
        int now = 0;
        for(int i=1;i<=n;i++){
            now += a[i]-b[i-1]+t[i];
            int mid = (b[i]-a[i]+1)>>1;
            if(i == n) continue;
            if(now + mid <= b[i]) now = b[i];
            else now += mid;
        }
        cout<<now<<"\n";
    }
    return 0;
}
