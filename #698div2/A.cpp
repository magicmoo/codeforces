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

int a[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans = 1,temp = 1;
        for(int i=1;i<=n;i++){
            if(a[i] == a[i-1]) temp++;
            else{
                ans = max(ans,temp);
                temp = 1;
            }
        }
        ans = max(ans,temp);
        cout<<ans<<"\n";
    }
    return 0;
}
