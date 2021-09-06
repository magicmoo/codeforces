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
ll ans[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int n,q,k,l,r;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1] = k+1;
    for(int i=1;i<=n;i++){
        ans[i] = ans[i-1]+(a[i+1]-a[i-1]-2);
    }
    while(q--){
        cin>>l>>r;
        cout<<ans[r-1]-ans[l]+(k-a[r-1]-1)+(a[l+1]-2)<<"\n";
    }
    return 0;
}
