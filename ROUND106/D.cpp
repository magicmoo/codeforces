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
const int maxn = 1e4+5;  //注意修改maxn数值
int vis[maxn],prime[maxn],tol;
const int maxv = 2e7+5; //注意修改maxv数值
int mind[maxv],val[maxv];
void init(){
    for(int i=1;i<maxv;i++) mind[i] = -1;
    mind[1] = 1;
    for(int i=2;i<maxv;i++){
        if(mind[i] == -1){
            for(int j=i;j<=maxv;j+=i) mind[j] = i;
            mind[i] = i;
        }
    }
    for(int i=2;i<maxv;i++){
        int j = i/mind[i];
        val[i] = val[j]+(mind[i]!=mind[j]);
    }
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,c,d,x,k1,k2;
    init();
    cin>>T; while(T--){
        int ans = 0;
        cin>>c>>d>>x;
        for(int i=1;i*i<=x;i++){
            if(x%i != 0) continue;
            k1 = x/i+d;
            if(k1%c == 0){
                ans += 1 << val[k1/c];
            }
            if(i*i==x) continue;
            k2 = i+d;
            if(k2%c == 0){
                ans += 1 << val[k2/c];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
