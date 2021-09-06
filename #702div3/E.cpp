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
const ll INF = 0x3f3f3f3f;
const ll maxn = 2e5+5;
struct Node{
    ll data;
    ll i;
}a[maxn];
bool cmp(Node a,Node b){
    return a.data<b.data;
}
ll ans[maxn];
ll num[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    ll T,n,sum;
    cin>>T; while(T--){
        memset(ans,0,sizeof(ans));
        memset(num,0,sizeof(num));
        cin>>n;
        sum = 1;
        for(ll i=1;i<=n;i++){ cin>>a[i].data; a[i].i = i; }
        sort(a+1,a+n+1,cmp);
        for(ll i=1;i<=n;i++){
            num[i] = num[i-1]+a[i].data;
        }
        ans[a[n].i] = 1;
        for(ll i=n-1;i>0;i--){
            if(num[i] >= a[i+1].data){
                ans[a[i].i] = 1;
                sum++;
            }else{
                break;
            }
        }
        cout<<sum<<"\n";
        for(ll i=1;i<=n;i++){
            if(ans[i] == 1) cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
