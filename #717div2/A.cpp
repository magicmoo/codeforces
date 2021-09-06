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
typedef long long ll;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int n,a[maxn],k;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("../in.txt","r",stdin); freopen("../out.txt","w",stdout);
    #endif
    CAS {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n&&k>0;i++){
            while(a[i]>0&&k>0){
                a[i]--;
                k--;
                a[n]++;
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
