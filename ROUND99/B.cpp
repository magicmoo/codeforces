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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,x;
    cin>>T; while(T--){
        cin>>x;
        int l=1,r=1e4;
        while(l+1 < r){
            int mid = (l+r)>>1;
            if(mid*(mid+1)/2 >= x) r = mid;
            else l = mid+1;
        }
        int m,ans = 0;
        if(l == r) m = l;
        else{
            if(l*(l+1)/2 >= x) m = l;
            else m = r;
        }
        int mm = m*(m+1)/2;
        if(x == mm-1) cout<<m+1<<"\n";
        else cout<<m<<"\n";
    }
    return 0;
}
