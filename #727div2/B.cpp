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
#define CAS int CASE;  \
            cin>>CASE; \
            while(CASE--)
#define YON if(flag) cout<<"YES\n"; \
            else cout<<"NO\n"
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int pre[maxn][30];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int n,q,l,r;
    string s;
    cin>>n>>q;
    cin>>s;
    pre[0][s[0]-'a'] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<30;j++){
            if(s[i]-'a' == j) pre[i][j] = pre[i-1][j]+1;
            else pre[i][j] = pre[i-1][j];
        }
    }
    while(q--){
        cin>>l>>r;
        ll ans = 0;
        for(int i=0;i<30;i++){
            if(l != 1)
                ans += (i+1)*(pre[r-1][i]-pre[l-2][i]);
            else ans += (i+1)*(pre[r-1][i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
