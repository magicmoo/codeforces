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
const int maxn = 1e5+5;

int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,k;
    cin>>T; while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans = INF;
        for(int j=1;j<=100;j++){
            int now = 1,temp = 0;
            while(now <= n){
                if(a[now] != j){
                    now += k;
                    temp++;
                }else now++;
            }
            ans = min(ans,temp);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
