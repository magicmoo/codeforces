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

int a[105],b[105];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m;
    cin>>T; while(T--){
        memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
        cin>>n>>m;
        int ans = 0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i] == b[j]) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
