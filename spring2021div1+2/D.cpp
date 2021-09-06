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
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int a[maxn][70],book[maxn];
int fa[maxn];
int n,m,q,ans;
vector<int> v;
set<int> s[70];
int dfs(int now){
    
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) scanf("%1d",&a[i][j]);
    }
    for(int i=1;i<=m;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(a[j][i] == 1) cnt++;
        }
        if(cnt >= (n+1)/2) v.push_back(i);
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            int cnt = 0;
            for(int k=1;k<=n;k++){
                if(a[i][k]==1 && a[j][k]==1) cnt++;
            }
            if(cnt >= (n+1)/2){
                s[i].insert(j); s[j].insert(i);
            }
        }
    }
    
    return 0;
}
