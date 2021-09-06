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
struct Node{
    int l,r;
}nodes[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n;
    cin>>T; while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>nodes[i].l>>nodes[i].r;
        vector<int> l,r;
        for(int i=1;i<=n;i++){
            l.push_back(nodes[i].l);
            r.push_back(nodes[i].r);
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        int ans = 0;
        for(int i=1;i<=n;i++){
            int left = lower_bound(r.begin(),r.end(),nodes[i].l) - r.begin();
            int right = n-(upper_bound(l.begin(),l.end(),nodes[i].r) - l.begin());
            ans = max(ans,n-left-right);
        }
        cout<<n-ans<<"\n";
    }
    return 0;
}
