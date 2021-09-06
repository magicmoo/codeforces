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

int a[maxn],b[maxn],book[maxn];
vector<int> v[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,x;
    cin>>T; while(T--){
        memset(book,0,sizeof(book));
        cin>>n>>x;
        for(int i=1;i<=n;i++){ cin>>a[i]; b[i] = a[i]; }
        bool flag = true;
        // int Max = 0;
        // for(int i=1;i<=n;i++){
        //     Max = max(Max,a[i]);
        //     if(a[i]<Max && a[i]<x){
        //         flag = false;
        //         break;
        //     }
        // }
        // if(!flag){
        //     cout<<"-1\n";
        //     continue;
        // }
        b[n+1] = x;
        sort(b+1,b+n+2);
        for(int i=0;i<maxn;i++){
            v[i].clear();
        }
        for(int i=1;i<=n+1;i++){
            v[b[i]].push_back(i);
        }
        int now = n;
        while(now>0 && a[now] == b[now+1]) now--;
        int ans = 0;
        bool flag1 = true;
        for(int i=1;i<=now;i++){
            int m = b[i];
            if(a[i] == b[i]) continue;
            if(x != b[i]){
                flag1 = false;
                break;
            }
            x = a[i];
            ans++;
        }
        if(!flag1) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
