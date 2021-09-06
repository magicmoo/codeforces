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
const int maxn = 1e5+5;
int a[maxn],book[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m;
    cin>>T; while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=0;i<m;i++) book[i] = 0;
        int ans = 0;
        for(int i=1;i<=n;i++){
            book[a[i]%m]++;
        }
        if(book[0]) ans++;
        for(int i=1;i<=m/2;i++){
            int next = m-i;
            int x = max(book[i],book[next]),y=min(book[i],book[next]);
            if(x==0 && y==0) continue;
            if(x-y <= 1) ans++;
            else ans += (x-y);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
