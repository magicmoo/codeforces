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
    int T,n,k;
    string s;
    cin>>T; while(T--){
        cin>>n>>k;
        cin>>s;
        int first = -1,last = -1;
        for(int i=0;i<n;i++) if(s[i] == '*'){ first = i; break; }
        for(int i=n-1;i>=0;i--) if(s[i] == '*'){ last = i; break; }
        int now = first;
        int ans = 2;
        if(first == -1) ans = 0;
        if(first == last) ans = 1;
        while(now <= last){
            int next = min(now+k,last);
            if(next == last) break;
            for(int i=next;i>now;i--){
                if(s[i] == '*'){ now = i; break;}
            }
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
