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
// #include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 50+5;

int x[maxn],map[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        memset(map,0,sizeof(map));
        cin>>n;
        int ans = 0;
        for(int i=0;i<n;i++) cin>>x[i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len = x[j] - x[i];
                if(!map[len]){
                    ans++;
                    map[len] = 1;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
