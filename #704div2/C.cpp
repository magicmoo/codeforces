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
int pre[maxn],ord[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    int now = 0,ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == t[now]){
            pre[now] = i;
            now++;
        }
    }
    now = m-1;
    for(int i=n-1;i>=0;i--){
        if(s[i] == t[now]){
            ord[now] = i;
            now--;
        }
    }
    for(int i=0;i<n;i++){
        ans = max(ans,ord[i+1]-pre[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
