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

int a[maxn],sum[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>60){
        cout<<"1\n";
    }else{
        int ans = INF;
        for(int i=1;i<=n;i++) sum[i] = sum[i-1]^a[i];
        for(int l=1;l<n-1;l++){
            for(int mid=l;mid<n;mid++){
                for(int r=mid+1;r<=n;r++){
                    int a = sum[mid]^sum[l-1];
                    int b = sum[mid]^sum[r];
                    if(a > b) ans = min(ans,r-l-1);
                }
            }
        }
        if(ans == INF) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;   
}
