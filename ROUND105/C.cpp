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
const int maxn = 2e5+2;

int a[maxn],b[maxn],sum[maxn];

bool find(int num,int l,int r){
    while(l <= r){
        int mid = (l+r)>>1;
        if(b[mid] == num) return true;
        if(b[mid] > num) r = mid-1;
        else l = mid+1;
    }
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
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];
        int ans1 = 0,ans2 = 0;
        int mid = upper_bound(b+1,b+m+1,0)-b;
        int mida = upper_bound(a+1,a+1+n,0)-a;
        for(int i=1;i<=n;i++){
            if(find(a[i],1,m)) sum[i] = sum[i-1]+1;
            else sum[i] = sum[i-1];
        }
        sum[n+1] = sum[n];
        for(int i=mid;i<=m;i++){
            int num = upper_bound(a+1,a+n+1,b[i])-a-mida;
            if(num == 0) continue;
            int num2 = i-(lower_bound(b+1,b+m+1,b[i]-num+1)-b)+1;
            int j = upper_bound(a+1,a+n+1,b[i])-a;
            ans1 = max(ans1,num2+sum[n]-sum[j-1]);
        }
        for(int i=mid-1;i>=1;i--){
            int num = mida - (lower_bound(a+1,a+n+1,b[i])-a);
            if(num == 0) continue;
            int num2 = (upper_bound(b+1,b+m+1,b[i]+num-1)-b)-i;
            int j = lower_bound(a+1,a+n+1,b[i])-a;
            ans2 = max(ans2,num2+sum[j-1]);
        }
        // cout<<ans1<<" "<<ans2<<"\n";
        cout<<ans1+ans2<<"\n";
    }
    return 0;
}
