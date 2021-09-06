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
const int maxn = 2005;

int map[maxn][maxn],book[10][2],book2[10][2],sum[10];
int main(){
    // std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%1d",&map[i][j]);
        for(int k=0;k<10;k++){
            book[k][0] = book2[k][0] = 0;
            book[k][1] = book2[k][1] = 0;
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(book[map[i][j]][0]) book[map[i][j]][0] = min(j,book[map[i][j]][0]);
                else book[map[i][j]][0] = j;
                book[map[i][j]][1] = max(j,book[map[i][j]][1]);
                if(book2[map[j][i]][0]) book2[map[j][i]][0] = min(j,book2[map[j][i]][0]);
                else book2[map[j][i]][0] = j;
                book2[map[j][i]][1] = max(j,book2[map[j][i]][1]);
                sum[map[i][j]]++;
            }
        }
        int ans[10] = {0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k = map[i][j];
                // if(k != 0) continue;
                if(sum[k] <= 1) continue;
                if(book[k][0] > 0) ans[k] = max(ans[k],(j-book[k][0])*max(n-i,i-1));
                if(book[k][1] > 1) ans[k] = max(ans[k],(book[k][1]-j)*max(n-i,i-1));
                if(book2[k][0] > 0) ans[k] = max(ans[k],(i-book2[k][0])*max(n-j,j-1));
                if(book2[k][1] > 0) ans[k] = max(ans[k],(book2[k][1]-i)*max(n-j,j-1));
            }
        }
        for(int k=0;k<10;k++)
            cout<<ans[k]<<" ";
        cout<<"\n";
    }
    return 0;
}
