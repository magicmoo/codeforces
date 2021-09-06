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
const int maxn = 105;

int a[maxn],ans[maxn];
int T,n;
void cal(int l,int r,int deep){
    if(l == r){
        ans[l] = deep;
        return;
    }
    int max = 0,maxi = 0;
    for(int i=l;i<=r;i++){
        if(a[i] > max){
            max = a[i];
            maxi = i;
        }
    }
    ans[maxi] = deep;
    if(l <= maxi-1) cal(l,maxi-1,deep+1);
    if(maxi+1 <= r) cal(maxi+1,r,deep+1);
}
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    cin>>T; while(T--){
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        cal(0,n-1,0);
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
