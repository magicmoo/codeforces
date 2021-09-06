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
const int maxn = 1e5+5;

int x[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    // freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        set<int> s;
        cin>>n;
        for(int i=0;i<n;i++) cin>>x[i];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s.count(x[i]) == 0){
                s.insert(x[i]);
                ans++;
            }else if(s.count(x[i]+1) == 0){
                s.insert(x[i]+1);
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
