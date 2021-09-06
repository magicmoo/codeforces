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
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 505;
int a[maxn],ans[maxn][maxn],n;
bool check(int i,int j){
    if(i>n || j<=0) return 0;
    return 1;
}
void dfs(int i,int j,int last,int now){
    if(last == 0) return;
    ans[i][j] = now;
    if(check(i,j-1) && !ans[i][j-1]){
        dfs(i,j-1,last-1,now);
    }else dfs(i+1,j,last-1,now);
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dfs(i,i,a[i],a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
