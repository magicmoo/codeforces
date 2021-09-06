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

int pre[maxn],post[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    int T,n,q,l,r;
    string s;
    cin>>T; while(T--){
        cin>>n>>q;
        cin>>s;
        while(q--){
            bool flag = false;
            cin>>l>>r;
            l--; r--;
            int now = l;
            for(int i=0;i<l;i++){
                if(s[i] == s[l]){
                    flag = true;
                    break;
                }
            }
            for(int i=r+1;i<n;i++){
                if(s[i] == s[r]){
                    flag = true;
                    break;
                }
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
