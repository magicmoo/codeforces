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

int a[maxn],sum[maxn];
int n,k;

bool check(int num){
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+(a[i]>=num?1:-1);
    }
    int ans = 0,mi;
    for(int i=k;i<=n;i++){
        mi = min(mi,sum[i-k]);
        ans = max(ans,sum[i]-mi);
    }
    return ans>0;
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l = 1, r = n;
    while(l+1 < r){
        int mid = (l+r)>>1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    if(l == r) cout<<l<<"\n";
    else{
        if(check(r)) cout<<r<<"\n";
        else cout<<l<<"\n";
    }
    return 0;
}
