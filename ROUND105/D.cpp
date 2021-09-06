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
const int maxn = 505;

int a[maxn][maxn],ans[maxn];

vector<pair<int,pair<int,int>>> v;
int fa[maxn<<2],pre[maxn<<2];

int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        fa[i] = i;
        ans[i] = a[i][i];
        for(int j=i+1;j<=n;j++){
            v.push_back({a[i][j],{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int now = n+1;
    for(auto temp : v){
        int val = temp.first,x = temp.second.first,y = temp.second.second;
        int fx = find(x),fy = find(y);
        if(val == ans[fx]){
            fa[fy] = fx; pre[fy] = fx;
        }else if(val == ans[fy]){
            fa[fx] = fy; pre[fx] = fy;
        }else{
            fa[fx] = fa[fy] = pre[fx] = pre[fy] = now;
            ans[now] = val;
            fa[now] = now;
            now++;
        }
    }
    cout<<now-1<<"\n";
    for(int i=1;i<now;i++) cout<<ans[i]<<" ";
    cout<<"\n"<<now-1<<"\n";
    for(int i=1;i<now-1;i++) cout<<i<<" "<<pre[i]<<"\n";
    cout<<"\n";
    return 0;
}
