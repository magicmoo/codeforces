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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 505;
char map[maxn][maxn];
int sum[maxn][maxn];
bool check(int l,int r,int y){
    if(sum[y][r]-sum[y][l-1] == r-l+1) return true;
    return false;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m;
    cin>>T; while(T--){
        memset(sum,0,sizeof(sum));
        cin>>n>>m;
        ll ans = 0;
        for(int i=n;i>0;i--)
            for(int j=1;j<=m;j++)
                cin>>map[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j] == '*') sum[i][j] = sum[i][j-1]+1;
                else sum[i][j] = sum[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=i;k++){
                    if(j-k+1<1 || j+k-1>m || !check(j-k+1,j+k-1,i-k+1)) break;
                    ans++;
                }
            }   
        }
        cout<<ans<<"\n";
    }
    return 0;
}
