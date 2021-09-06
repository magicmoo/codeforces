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
const int maxn = 100+5;

int r[maxn],b[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>r[i];
        cin>>m;
        for(int i=1;i<=m;i++) cin>>b[i];
        int ans = 0,temp = 0;
        for(int i=1;i<=n;i++){
            temp += r[i];
            ans = max(ans,temp);
        }
        temp = ans;
        for(int i=1;i<=m;i++){
            temp += b[i];
            ans = max(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
