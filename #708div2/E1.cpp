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
const int maxn = 2e5+5;
const int maxv = 1e7+5;  //注意修改maxn数值
int vis[maxn],prime[maxn],tol;
void liner_shai(){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<maxn;i++){
        if(!vis[i])
            prime[tol++] = i;
        for(int j=0;j<tol&&i*prime[j]<maxn;j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k,sum;
    liner_shai();
    set<int> s;
    cin>>T; while(T--){
        s.clear();
        cin>>n>>k;
        int ans = 1;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            int temp = 1;
            for(int j=0;j<tol&&prime[j]*prime[j]<=a[i];j++){
                sum = 0;
                while(a[i]%prime[j]==0){
                    sum++;
                    a[i]/=prime[j];
                }
                if(sum%2) temp *= prime[j];
            }
            if(a[i] != 1){
                temp *= a[i];
            }
            if(s.count(temp)){
                s.clear();
                s.insert(temp);
                ans++;
            }else s.insert(temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
