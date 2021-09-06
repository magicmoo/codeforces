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
const int maxn = 105;
int book[maxn][maxn],ans[maxn][maxn],a[maxn][maxn];
struct Node{
    int dis;
    int i,j;
};
vector<Node> v;
bool cmp(Node a,Node b){
    return a.dis<b.dis;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m;
    CAS {
        cin>>n>>m;
        v.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                book[i][j] = ans[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                v.push_back({a[i][j],i,j});
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<m;i++){
            ans[v[i].i][i+1] = v[i].dis;
            book[v[i].i][v[i].j] = 1;
        }
        for(int i=1;i<=n;i++){
            int now = 1;
            for(int j=1;j<=m&&now<=m;j++){
                if(ans[i][j] > 0) continue;
                while(book[i][now]) now++;
                ans[i][j] = a[i][now++];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
