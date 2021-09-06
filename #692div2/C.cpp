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
const int maxn = 1e5+5;
struct Node{
    int x,y;
}nodes[maxn];
int map[maxn];

int query(int x){
    return map[x]==x?x:map[x] = query(map[x]);
}

bool unit(int x,int y){
    if(query(x) == query(y)) return true;
    map[x] = query(y);
    return false;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,m;
    cin>>T; while(T--){
        cin>>n>>m;
        int ans = m;
        for(int i=0;i<m;i++){
            cin>>nodes[i].x>>nodes[i].y;
        }
        for(int i=1;i<=n;i++){
            map[i] = i;
        }
        for(int i=0;i<m;i++){
            if(nodes[i].x == nodes[i].y) ans--;
            else if(unit(nodes[i].x,nodes[i].y)) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
