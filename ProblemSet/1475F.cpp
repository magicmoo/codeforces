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
const int maxn = 1e3+5;

int a[maxn][maxn],b[maxn][maxn];
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
                scanf("%1d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%1d",&b[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j] = (a[i][j] != b[i][j]);
        for(int i=1;i<=n;i++){
            if(a[i][1] == 1){
                for(int j=1;j<=n;j++){
                    a[i][j] = !(a[i][j]);
                }
            }
        }
        bool flag = true;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(a[j-1][i] != a[j][i]){ flag = false; break; }
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
