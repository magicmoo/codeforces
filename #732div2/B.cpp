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
const int maxn = 2e5+5;
string arr[maxn];
int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        int n,m;
        cin>>n>>m;
        n = n*2-1;
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=0;i<m;i++){
            map<char,int> mp;
            for(int j=1;j<=n;j++){
                mp[arr[j][i]]++;
            }
            for(int i=0;i<26;i++){
                if(mp['a'+i]%2) cout<<(char)('a'+i);
            }
        }
        cout<<"\n";
    }
    return 0;
}
